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

Compilar el programa principal:

```bash
make
```

Compilar la versión bonus (`checker`):

```bash
make bonus
```

Eliminar archivos objeto:

```bash
make clean
```

Eliminar archivos objeto y ejecutables:

```bash
make fclean
```

Reconstruir completamente el proyecto:

```bash
make re
```

---

## Ejecución

Ordenar una lista de números:

```bash
./push_swap 4 2 8 1 3
```

La salida será una lista de instrucciones necesarias para ordenar la pila.

Ejemplo:

```text
pb
ra
sa
pa
```

---

## Comprobación (Bonus)

El programa `checker` ejecuta una lista de instrucciones sobre una pila inicial y verifica si el resultado final está correctamente ordenado.

Ejemplo:

```bash
ARG="4 2 8 1 3"

./push_swap $ARG | ./checker $ARG
```

Salida:

```text
OK
```

---

# Decisiones técnicas

## Estrategia general

La solución implementa distintas estrategias de ordenación dependiendo del tamaño y del grado de desorden de la entrada. En lugar de aplicar un único algoritmo para todos los casos, el programa selecciona dinámicamente el método que ofrece un mejor equilibrio entre simplicidad y número de operaciones.

Esta aproximación permite optimizar tanto los casos pequeños como las entradas de mayor tamaño.

---

## Justificación de los valores límite (umbrales)

Se establecen distintos niveles de desorden mediante umbrales definidos experimentalmente.

Estos valores fueron obtenidos tras realizar numerosas pruebas con conjuntos de datos de diferentes tamaños y medir el número medio de operaciones generadas por cada estrategia.

El objetivo fue encontrar puntos de transición donde un algoritmo comienza a superar sistemáticamente a otro.

Los umbrales no responden a una propiedad matemática concreta, sino a un compromiso entre:

- Número de operaciones.
- Tiempo de ejecución.
- Simplicidad del algoritmo.
- Comportamiento observado durante las pruebas.

> **Nota:** Sustituye esta sección por los valores reales utilizados en tu implementación. Por ejemplo:
>
> - Hasta **50** elementos → Estrategia A.
> - Entre **51 y 100** → Estrategia B.
> - Entre **101 y 500** → Estrategia C.

---

## Técnicas internas empleadas

Entre las técnicas implementadas destacan:

- Normalización de valores mediante asignación de índices.
- Uso de listas enlazadas para representar ambas pilas.
- Cálculo del coste de movimiento para cada nodo candidato.
- Selección del movimiento con menor coste total.
- Uso de rotaciones simultáneas (`rr` y `rrr`) para reducir el número de instrucciones.
- Actualización dinámica de índices y posiciones tras cada operación.
- Estrategias específicas para pilas pequeñas (2, 3 y 5 elementos).
- Selección automática del algoritmo más adecuado según el tamaño y el grado de desorden de la entrada.

> **Nota:** Describe aquí únicamente las técnicas que realmente hayas implementado.

---

# Recursos

## Documentación

- Manuales de Linux (`man malloc`, `man write`, `man read`, etc.).
- The GNU C Library Documentation.
- The Open Group Base Specifications (POSIX).
- Documentación oficial del lenguaje C.
- Material del currículo de 42.

## Referencias

- Brian W. Kernighan & Dennis M. Ritchie — *The C Programming Language*.
- Robert Sedgewick — *Algorithms in C*.
- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest y Clifford Stein — *Introduction to Algorithms*.

## Uso de Inteligencia Artificial

Durante el desarrollo del proyecto se utilizó inteligencia artificial exclusivamente como herramienta de apoyo al aprendizaje y revisión del código.

Concretamente se empleó para:

- Resolver dudas sobre el funcionamiento del lenguaje C.
- Comprender estructuras de datos y algoritmos.
- Analizar posibles mejoras de rendimiento.
- Revisar implementaciones ya desarrolladas.
- Detectar posibles errores lógicos y casos límite.
- Mejorar la documentación del proyecto.

La implementación, depuración y validación del algoritmo final fueron realizadas manualmente.

---

# Autores

**Login de 42:** `mreyes-m   ilopez-g`
