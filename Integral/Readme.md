# Algoritmo de generación de rutas a partir de coordenadas para sistemas robóticos de movimiento autónomo

## Esteban Padilla Cerdio

## A01703068

Este programa tiene como propósito recibir una lista de coordenadas por las cuales un sistema robótico de movimiento autónomo debe cruzar, generando un camino optimizado que las atraviese todas.

<img src="https://i.stack.imgur.com/CJFw1.png" width=500px height=250px/>

## SICT0302B: Toma decisiones

### Selecciona y usa una estructura lineal adecuada al problema

El programa utiliza una estructura de lista ligada doble, ya que al estar trabajando con series de coordendas y caminos, es conveniente ir pasando de un punto al siguiente de forma rápida y eficiente, para indicarle al sistema robótico la dirección a la que se debe dirigir. Igualmente, se creó una nueva clase, la Coordenada, para poder representar los puntos de manera eficiente. Una vez leído el archivo, se puede llamar la función "generatePath" para transformar los puntos leídos en el archivo en una lista ligada de coordenadas, con la que se pueden manipular los datos conforme sea necesario.

### Selecciona un algoritmo de ordenamiento adecuado al problema

El programa utiliza un algoritmo tipo Merge Sort para ordenar las coordenadas, ya sea basándose en la coordenada X o en la coordenada Y. En ambos casos, utiliza el algoritmo para ordenar ambas listas, usando una de ellas como referencia. El motivo por el cual se utilizó este algoritmo es porque es rápido en la mayoría de los casos, y su peor caso, que es cuando está casi ordenada, será raro encontrarlo, ya que los puntos están generados aleatoriamente. En el archivo main.h se puede ver la ejecución de un ordenamiento con la coordenada X como referencia en la línea 18, y un ordenamiento con la coordenada Y como referencia en la línea 22.

### Usa un árbol adecuado para resolver un problema

El programa le permite al usuario seleccionar un punto de origen del sistema de coordenadas. Posteriormente, genera un árbol Heap de tipo mínimo basado en las distancias de cada uno de los puntos al origen. De esta manera, se crea una estructura de datos donde la raíz es el punto seleccionado, y los demás datos se acomodan orgánicamente según su distancia física al origen, estando los más cercanos posicionados antes en la estructura, y los más lejanos quedan hasta el final. Este tipo de estructura podría permitir posteriormente facilitar la creación de caminos optimizados entre dos puntos, ya que con este árbol heap es más sencillo obtener los puntos cercanos.

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
