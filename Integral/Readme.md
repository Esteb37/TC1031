# Algoritmo de generación de rutas a partir de coordenadas para sistemas robóticos de movimiento autónomo

## Esteban Padilla Cerdio

## A01703068

Este programa tiene como propósito recibir una lista de coordenadas por las cuales un sistema robótico de movimiento autónomo debe cruzar, generando un camino optimizado que las atraviese todas.

<img src="https://i.stack.imgur.com/CJFw1.png" width=500px height=250px/>

## SICT0302B: Toma decisiones

### Selecciona y usa una estructura lineal adecuada al problema

### Selecciona un algoritmo de ordenamiento adecuado al problema

El programa utiliza un algoritmo tipo Merge Sort para ordenar las coordenadas, ya sea basándose en la coordenada X o en la coordenada Y. En ambos casos, utiliza el algoritmo para ordenar ambas listas, usando una de ellas como referencia. El motivo por el cual se utilizó este algoritmo es porque es rápido en la mayoría de los casos, y su peor caso, que es cuando está casi ordenada, será raro encontrarlo, ya que los puntos están generados aleatoriamente. En el archivo main.h se puede ver la ejecución de un ordenamiento con la coordenada X como referencia en la línea 18, y un ordenamiento con la coordenada Y como referencia en la línea 22.

### Usa un árbol adecuado para resolver un problema

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
