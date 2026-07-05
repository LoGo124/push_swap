*Este proyecto ha sido creado como parte del currículo de 42 por `ilopez-g y mreyes-m`.*

# push_swap

## Descripción

**push_swap** es un proyecto cuyo objetivo es ordenar una pila de números enteros utilizando el menor número posible de operaciones. Para ello, el programa dispone de dos pilas (`a` y `b`) y de un conjunto limitado de instrucciones que permiten intercambiar, mover y rotar los elementos entre ambas.

El reto consiste en diseñar un algoritmo eficiente capaz de encontrar una secuencia de operaciones que ordene correctamente la pila inicial, optimizando al mismo tiempo el número total de movimientos realizados.

Este proyecto permite profundizar en conceptos fundamentales como:

- Estructuras de datos dinámicas (listas enlazadas).
- Manipulación eficiente de pilas.
- Diseño y análisis de algoritmos.
- Optimización del rendimiento.
- Gestión de memoria en C.

---

# Instrucciones

## Compilación


```bash
make  # Compilar push_swap

make bonus  # Compilar la versión bonus (`checker`)

make clean  # Eliminar archivos objeto

make fclean  # Eliminar archivos objeto y ejecutables

make re  # Reconstruir completamente el proyecto
```

---

## Ejecución

Ordenar una lista de números:

```bash
./push_swap 4 2 8 1 3
```

La salida será una lista de instrucciones necesarias para ordenar la pila.


---

## Comprobación (Bonus)

El programa `checker` ejecuta una lista de instrucciones sobre una pila inicial y verifica si el resultado final está correctamente ordenado.

Ejemplo:

```bash
ARG="4 2 8 1 3"

./push_swap $ARG | ./checker $ARG
# OK
```

---

# Decisiones técnicas

## Estrategia general

La solución implementa distintas estrategias de ordenación dependiendo del tamaño y del grado de desorden de la entrada. En lugar de aplicar un único algoritmo para todos los casos, el programa selecciona dinámicamente el método que ofrece un mejor equilibrio entre simplicidad y número de operaciones.

Esta aproximación permite optimizar tanto los casos pequeños como las entradas de mayor tamaño.

---

# Algoritmos

## Selection Sort


```bash
En cada iteración:

1. Se localiza el valor mínimo de la pila `a`.
2. Se calcula su posición.
3. Se decide si resultan más eficiente las rotaciones (`ra`) o inversas (`rra`) 
4. Se lleva el elemento a la parte superior.
5. El elemento mínimo se mueve a la pila `b` mediante `pb`.
6. El proceso se repite hasta vaciar completamente la pila `a`.
```
Una vez trasladados todos los elementos, estos se devuelven a `a` mediante operaciones `pa`, obteniendo la pila ordenada de menor a mayor.

Aunque esta estrategia tiene una complejidad temporal de **O(n²)**, resulta sencilla, determinista y suficientemente eficiente para pilas de tamaño reducido.

## Chunk Sort por Ventana Flotante

Para pilas de mayor tamaño se utiliza una estrategia basada en **índices normalizados** y una **ventana de trabajo (chunk)** cuyo tamaño depende del número de elementos de la entrada, una variante de chunk sort incremental con una estrategia de reconstrucción por máximos.

### División en bloques

Inicialmente se define una ventana de índices (`chunk`) cuyo tamaño se ajusta según el tamaño de la pila.

Los elementos se mueven a la pila `b` mediante `pb` mediante las siguientes reglas:

```bash
- 1. Si pertenece a la parte inferior de la ventana:
El elemento se envía a la pila `b` y posteriormente se realiza una rotación (`rb`).
Esto desplaza los elementos más pequeños hacia el fondo de la pila `b`.

- 2. Si pertenece al resto de la ventana:
El elemento se mueve directamente a `b` mediante `pb`.
Se amplia progresivamente el rango de índices aceptados.

- 3. Si todavía no pertenece a la ventana activa:
La pila `a` se rota (`ra`) hasta encontrar un candidato adecuado.
```

A medida que se insertan elementos, la ventana se desplaza y aumenta dinámicamente, permitiendo procesar la pila completa en una única pasada.


### Selección del tamaño del chunk

El tamaño inicial de la ventana no es constante. Se ajusta experimentalmente en función del número de elementos de entrada para mantener un equilibrio entre el número de rotaciones realizadas y el número total de instrucciones generadas.

Los valores utilizados son:

| Número de elementos | Tamaño inicial del chunk |
|---------------------|-------------------------:|
| ≤ 50                | 10 |
| ≤ 100               | 20 |
| ≤ 200               | 25 |
| ≤ 500               | 40 |
| > 500               | 45 |

Estos umbrales fueron obtenidos tras realizar múltiples pruebas comparando el número medio de operaciones generado para distintos tamaños de entrada.

---

## Binary Radix Sort (LSD-Least Significant Bit)

El algoritmo procesa los índices desde el **bit menos significativo (Least Significant Bit)** hasta el más significativo.

En cada pasada se analiza un único bit de todos los elementos presentes en la pila `a`:

- Si el bit evaluado es `0`, el elemento se mueve a la pila `b` mediante `pb`.
- Si el bit es `1`, el elemento permanece en `a`, desplazándose al final mediante `ra`.

Una vez procesados todos los elementos para ese bit, los valores almacenados en la pila `b` se devuelven a `a` mediante operaciones `pa`, conservando el orden relativo obtenido en la iteración.

Este proceso se repite para cada posición binaria hasta que la pila queda completamente ordenada.

Al trabajar sobre índices normalizados, el número de bits necesarios para representar el mayor índice es pequeño incluso para entradas grandes, lo que convierte a Binary Radix Sort en una solución especialmente eficiente y predecible para este proyecto.

### Ventajas

- No requiere comparaciones entre elementos.
- El número de operaciones crece de forma casi lineal con el tamaño de la entrada.
- Produce un rendimiento estable independientemente de la distribución inicial de los datos.
- Se adapta de forma natural al conjunto limitado de operaciones disponibles en `push_swap`.

---

## Técnicas internas empleadas

Entre las técnicas implementadas destacan:

- Normalización de valores mediante asignación de índices. Antes de comenzar la ordenación, cada valor recibe un índice comprendido entre `0` y `n - 1`, donde `0` representa el menor elemento y `n - 1` el mayor. De esta forma el algoritmo trabaja sobre posiciones relativas en lugar de sobre los valores originales.
- Uso de listas doblemente enlazadas para representar ambas pilas.
- Actualización dinámica de índices y posiciones tras cada operación.
- Estrategias específicas para pilas pequeñas (hasta 8 elementos).
- Selección automática del algoritmo más adecuado según el tamaño y el grado de desorden de la entrada.

---

## Justificación de los valores límite (umbrales)

Se establecen distintos niveles de desorden mediante umbrales definidos experimentalmente.

Estos valores fueron obtenidos tras realizar numerosas pruebas con conjuntos de datos de diferentes tamaños y medir el número medio de operaciones generadas por cada estrategia.

El objetivo fue encontrar puntos de transición donde un algoritmo comienza a superar sistemáticamente a otro.

Los umbrales no responden a una propiedad matemática concreta, sino a un compromiso entre:

- Número de operaciones. (Prioridad)
- Simplicidad del algoritmo.
- Comportamiento observado durante las pruebas.

Para decidir estos umbrales se realizo un estudio estadistico donde se analiza la eficiencia de cada algoritmo en funcion del tamaño, durante el analisis, se observan ineficiencias y se solucionan editando las expresiones logicas que seleccionan el algoritmo. El proceso de analisi, solucion y justificacion se detalla en el siguiente archivo solo accesible desde el repositorio [push_swap](https://github.com/LoGo124/push_swap) en el fichero [anexos/charts_from_csvs.html](https://github.com/LoGo124/push_swap/blob/main/anexos/charts_from_csvs.html) Github  o [Github Pages](https://logo124.github.io/push_swap/anexos/charts_from_csvs.html)

> Nota: 
> Puedes descargar el html en la carpeta '/tmp' y consultar-lo con este comando, el sistema ya borrara el archivo.

'''sh
curl https://raw.githubusercontent.com/LoGo124/push_swap/refs/heads/main/anexos/charts_from_csvs.html > /tmp/push_swap-charts.html && open /tmp/push_swap-charts.html
'''
> Nota: 
> Soy un poco perezoso y solo es compatible con gnome, siempre puedes remplazar el comando 'open'

Umbrales establecidos
- Hasta **8** elementos → Tiny sort (Hardcoded).
- Entre **8 y 12** elementos o indice de desorden inferior a **0.2** → Algoritmo simple.
- Entre **12 y 470** elementos y indice de desorden entre **0.2 y 0.7** → Algoritmo intermedio.
- A partir de **470** elementos o indice de desorden superior a **0.7** → Algoritmo complejo.

---

# Recursos

## Documentación

- Manuales de Linux (`man malloc`, `man write`, `man read`, etc.)
- The Open Group Base Specifications (POSIX).
- Documentación oficial del lenguaje C.
- Material del currículo de 42.

## Referencias

- Robert Sedgewick — *Algorithms in C*.
- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest y Clifford Stein — *Introduction to Algorithms*.

## Uso de Inteligencia Artificial

Durante el desarrollo del proyecto se utilizó inteligencia artificial exclusivamente como herramienta de apoyo al aprendizaje y revisión del código.

- Comprender estructuras de datos y algoritmos.
- Analizar posibles mejoras de rendimiento.
- Detectar posibles errores lógicos y casos límite.
- Mejorar la documentación del proyecto.

La implementación, depuración y validación del algoritmo final fueron realizadas manualmente.

---

# Autores

**Login de 42:** `mreyes-m   ilopez-g`
