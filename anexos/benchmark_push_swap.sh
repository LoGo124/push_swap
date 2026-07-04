#!/usr/bin/env bash
set -euo pipefail

BINARY="./push_swap"
RESULTS="bench-results.csv"
SUMMARY="bench-summary.csv"

SIZES=(400 420 440 460 480 500) #SIZES=(8 10 12 15 25 50 100 250 500 1000)
ALGOS=("--medium" "--complex" "--adaptive") 
TRIALS=50

function ensure_binary() {
  if [ ! -x "$BINARY" ]; then
    echo "Compiling push_swap..."
    make
  fi
}

function generate_list() {
  local size="$1"

  python3 - "$size" <<'PY'
import sys
import random

size = int(sys.argv[1])
arr = list(range(1, size + 1))
random.shuffle(arr)
print(" ".join(str(x) for x in arr))
PY
}

function run_benchmarks() {
  echo "size,algo,trial,ops,disorder,strategy" > "$RESULTS"

  for size in "${SIZES[@]}"; do
    for algo in "${ALGOS[@]}"; do
      for trial in $(seq 1 "$TRIALS"); do
        echo "Running size=$size algo=$algo trial=$trial"
        list=$(generate_list "$size")
        output=$( { $BINARY --silence --bench $algo $list 2>&1 1>/dev/null; } )
        strategy=$(echo "$output" | awk -F": " '/Strategy:/ {print $2}')
        ops=$(echo "$output" | awk -F": " '/Total operations:/ {print $2}')
        disorder=$(echo "$output" | awk -F": " '/Disorder:/ {gsub(/%/,"",$2); print $2}')
        printf '%s,%s,%s,%s,%s,%s\n' "$size" "$algo" "$trial" "$ops" "$disorder" "$strategy" >> "$RESULTS"
      done
    done
  done
}

function summarize_results() {
  echo "size,simple,medium,complex,adaptive" > "$SUMMARY"

  python3 <<'PY'
import csv
from collections import defaultdict

results = defaultdict(lambda: defaultdict(list))
with open('bench-results.csv', newline='') as f:
    reader = csv.DictReader(f)
    for row in reader:
        size = int(row['size'])
        algo = row['algo'].lstrip('-')
        ops = float(row['ops'])
        results[size][algo].append(ops)

sizes = sorted(results.keys())
algos = ['simple', 'medium', 'complex', 'adaptive']
with open('bench-summary.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['size', 'simple', 'medium', 'complex', 'adaptive'])
    for size in sizes:
        row = [size]
        for algo in algos:
            vals = results[size].get(algo, [])
            row.append('%.2f' % (sum(vals) / len(vals)) if vals else '')
        writer.writerow(row)
PY

  echo "Summary saved to $SUMMARY"
}

ensure_binary
run_benchmarks
summarize_results

echo "Benchmark finished. Detailed data in $RESULTS and aggregated summary in $SUMMARY."
