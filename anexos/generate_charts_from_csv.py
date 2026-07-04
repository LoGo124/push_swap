#!/usr/bin/env python3
import argparse
import csv
import json
import sys
from pathlib import Path
from string import Template
from typing import Dict, List


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate a Chart.js HTML page with one chart per CSV file in a folder."
    )
    parser.add_argument(
        "--input-dir",
        default=str(Path(__file__).resolve().parent),
        help="Folder containing the CSV files (default: the script folder)",
    )
    parser.add_argument(
        "--output",
        default=None,
        help="Output HTML file path (default: <input-dir>/charts_from_csvs.html)",
    )
    return parser.parse_args()


def load_csv_series(path: Path) -> Dict[str, object]:
    with path.open(newline="", encoding="utf-8") as handle:
        rows = list(csv.DictReader(handle))

    if not rows:
        raise ValueError(f"{path.name} is empty")

    columns = [col for col in rows[0].keys() if col is not None]
    size_key = next((name for name in ("size", "n", "N") if name in columns), None)
    if size_key is None:
        size_key = columns[0]

    size_values: List[float] = []
    series_map: Dict[str, List[float]] = {column: [] for column in columns if column != size_key}

    for row in rows:
        if not any((value or "").strip() for value in row.values()):
            continue
        try:
            size_values.append(float(row[size_key]))
        except (KeyError, TypeError, ValueError):
            continue

        for column_name in series_map:
            value = row.get(column_name, "")
            if value is None or str(value).strip() == "":
                series_map[column_name].append(float("nan"))
            else:
                try:
                    series_map[column_name].append(float(value))
                except ValueError:
                    series_map[column_name].append(float("nan"))

    if not size_values:
        raise ValueError(f"No size values could be read from {path.name}")

    series_map = {name: values for name, values in series_map.items() if len(values) == len(size_values)}
    if not series_map:
        raise ValueError(f"No numeric series found in {path.name}")

    return {
        "title": path.stem.replace("_", " ").replace("-", " "),
        "size": size_values,
        "series": series_map,
    }


def build_html(charts: List[Dict[str, object]]) -> str:
    chart_configs = []
    for chart in charts:
        chart_configs.append(
            {
                "title": str(chart["title"]),
                "size": list(chart["size"]),
                "datasets": [
                    {
                        "label": label,
                        "data": values,
                        "borderWidth": 2,
                        "tension": 0.2,
                        "pointRadius": 3,
                    }
                    for label, values in chart["series"].items()
                ],
            }
        )

    config_json = json.dumps(chart_configs, ensure_ascii=False)
    template = Template("""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Charts from CSV files</title>
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <style>
    body { font-family: Arial, sans-serif; max-width: 1200px; margin: 2rem auto; padding: 0 1rem; }
    .chart-card { margin: 2rem 0; padding: 1rem 1.2rem; border: 1px solid #ddd; border-radius: 8px; }
    .chart-container { height: 420px; }
    .description-box { margin: 0.8rem 0 1rem; }
    .description-box textarea { width: 100%; min-height: 70px; padding: 0.6rem; border: 1px solid #ccc; border-radius: 6px; resize: vertical; }
    hr { border: 0; height: 1px; background: #ddd; margin: 2rem 0; }
  </style>
</head>
<body>
  <h1>Charts generated from CSV files</h1>
  <div id="charts"></div>

  <script>
    const chartConfigs = $config_json;

    const palette = ['#4e79a7', '#f28e2b', '#e15759', '#76b7b2', '#59a14f', '#edc949', '#af7aa1', '#ff9da7', '#9c755f', '#bab0ab'];

    function getColor(label, alpha = 1) {
      const index = Math.abs(label.split('').reduce((acc, ch) => acc + ch.charCodeAt(0), 0)) % palette.length;
      const base = palette[index];
      if (alpha === 1) return base;
      const hex = base.replace('#', '');
      const r = parseInt(hex.slice(0, 2), 16);
      const g = parseInt(hex.slice(2, 4), 16);
      const b = parseInt(hex.slice(4, 6), 16);
      return 'rgba(' + r + ', ' + g + ', ' + b + ', ' + alpha + ')';
    }

    function createChart(container, config) {
      const canvas = document.createElement('canvas');
      container.appendChild(canvas);
      new Chart(canvas, {
        type: 'line',
        data: {
          labels: config.size,
          datasets: config.datasets.map((dataset) => ({
            ...dataset,
            borderColor: getColor(dataset.label),
            backgroundColor: getColor(dataset.label, 0.2),
            fill: false,
          }))
        },
        options: {
          responsive: true,
          maintainAspectRatio: false,
          interaction: { mode: 'index', intersect: false },
          plugins: {
            title: { display: true, text: config.title },
            legend: { position: 'top' }
          },
          scales: {
            x: { title: { display: true, text: 'Size' } },
            y: { title: { display: true, text: 'Value' } }
          }
        }
      });
    }

    const chartsContainer = document.getElementById('charts');
    chartConfigs.forEach((config, index) => {
      const card = document.createElement('section');
      card.className = 'chart-card';
      card.innerHTML = '<h2>' + config.title + '</h2>' +
        '<div class="description-box"><label for="desc-' + index + '">Descripción</label><textarea id="desc-' + index + '" placeholder="Añade una descripción aquí..."></textarea></div>' +
        '<div class="chart-container"></div>';
      chartsContainer.appendChild(card);
      createChart(card.querySelector('.chart-container'), config);
      if (index < chartConfigs.length - 1) {
        const separator = document.createElement('hr');
        chartsContainer.appendChild(separator);
      }
    });
  </script>
</body>
</html>
""")
    return template.substitute(config_json=config_json)


def main() -> int:
    args = parse_args()
    input_dir = Path(args.input_dir).resolve()
    output_path = Path(args.output).resolve() if args.output else input_dir / "charts_from_csvs.html"

    if not input_dir.exists() or not input_dir.is_dir():
        print(f"Input directory does not exist: {input_dir}", file=sys.stderr)
        return 1

    csv_files = sorted(input_dir.glob("*.csv"))
    if not csv_files:
        print(f"No CSV files found in {input_dir}", file=sys.stderr)
        return 1

    charts = []
    for csv_path in csv_files:
        try:
            charts.append(load_csv_series(csv_path))
        except Exception as exc:
            print(f"Skipping {csv_path.name}: {exc}", file=sys.stderr)

    if not charts:
        print("No valid CSV files could be processed.", file=sys.stderr)
        return 1

    output_path.write_text(build_html(charts), encoding="utf-8")
    print(f"Generated {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
