# Algoritmo de generación de rutas a partir de coordenadas para sistemas robóticos de movimiento autónomo

## Esteban Padilla Cerdio

## A01703068

Este programa tiene como propósito representar una situación hipotética donde un Rover de investigación científica en Marte debe optimizar sus movimientos a través de las distintas subestaciones, registrando los resultados de sus distintos sensores de forma estructurada. En esta situación, el Rover utiliza oxígeno líquido para moverse una distancia máxima, por lo que debe planear sus trayectos tomando en cuenta que debe recargar su combustible en las subestaciones científicas.

<img src="https://d7lju56vlbdri.cloudfront.net/var/ezwebin_site/storage/images/_aliases/seo/reportajes/diez-claves-sobre-el-rover-perseverance-y-otras-nuevas-misiones-a-marte/8668097-4-esl-MX/Diez-claves-sobre-el-rover-Perseverance-y-otras-nuevas-misiones-a-Marte.jpg" width=500px height=250px/>

## SICT0302B: Toma decisiones

## Usa grafos para hacer analisis de información

El programa utiliza un grafo para representar las posibles subestaciones a las cuales el rover puede llegar desde el lugar en donde está, basado en la distancia máxima que puede recorrer con un tanque de combustible lleno. El grafo se genera iterando a través de cada uno de los puntos, y obteniendo la lista de puntos que se encuentran a una distancia menor que la distancia máxima recorrible.

## Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema

El programa utiliza un algoritmo de Depth Search First para encontrar una posible ruta entre el punto en el que se encuentra el rover y el punto al que quiere llegar, de forma que nunca tenga que recorrer más distancia de la que es capaz con un solo tanque de combustible.

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
