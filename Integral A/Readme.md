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

Esta evidencia se encuentra presente en las funciones testHeap y testPath, las cuales le permiten al usuario agregar, eliminar y buscar datos en las estructuras. Igualmente, el main le permite al usuario observar los datos en todos los distintos formatos y estructuras, así como decidir cómo generar el Heap.

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

- ### Main
  La función con mayor complejidad del programa es de O(NlogN), por lo que esa sería la complejidad del programa completo.
- ### Coordinate
  Todas las funciones de esta clase tienen una complejidad de O(1), ya que cada objeto consiste únicamente de dos puntos, y todas las operaciones se realizan a partir de esos dos únicos elementos.
- ### DList

  - #### add

    La complejidad es O(N), ya que primero se debe atravesar la lista hasta el punto seleccionado para poder colocar el nuevo nodo. En el peor de los casos, el punto seleccionado está en la posición N.

  - #### removeFirst, removeLast, getFirst, getLast, addFirst

    La complejidad es constante, O(1), ya que no importa la longitud de la lista, se ejecuta siempre la misma única acción.

  - #### remove, get, set, contains

    La complejidad es O(N), ya que primero se debe atravesar la lista hasta el punto seleccionado para poder obtener, eliminar o modificar el nodo. En el peor de los casos, el punto seleccionado está en la posición N.

  - #### empty, length

    La complejidad es constante, O(1), ya que no importa la longitud de la lista, se ejecuta siempre la misma única acción.

  - #### toString

    La complejidad es O(N), ya que se debe atravesar la lista completa para poder publicar cada uno de sus nodos.

- ### Heap

  - #### add, remove, heapify

    La complejidad es O(logN), ya que en el peor de los casos, será necesario realizar H swaps, donde H es la altura del árbol, que es el log de la cantidad N de datos que tiene.

  - #### empty, full, setSize, getSize, getcount, setOrigin

    La complejidad es O(1), ya que sin importar la longitud del heap, únicamente se ejecuta una sola acción

  - #### toString
    La complejidad es de O(N), ya que se debe atravesar el heap completo para poder transformarlo en texto.

- ### Data

  - #### readFile, print, printPath, printHeap, createFiles

    La complejidad es de O(N), ya que, dependiendo de la cantidad de coordenadas que haya en el archivo, es la longitud del arreglo, y éste se recorre una sola vez.

  - #### generateHeap

    La complejidad es de O(NlogN), ya que se ejecuta la acción "add" del Heap N veces, la cual tiene complejidad de O(logN)

  - #### generatePath

    La complejidad es de O(N), ya que se ejecuta la acción "addFirst" de la DList N veces, la cual tiene complejidad de O(1)

  - #### getPath, getXCoords, getYCoords, chooseOrigin

    Sin importar la longitud del arreglo de coordenadas, estas acciones se ejecutan una sola vez, por lo que tienen complejidad de O(1)

  - #### sortByX, sortByY

    Estas funciones utilizan un mergeSort, el cual tiene complejidad de O(Nlog(N)), ya que el algoritmo va dividiendo el arreglo entre dos en cada vuelta, lo que ocurre log(N) veces y se debe iterar todo el arreglo, de longitud N

  - #### testHeap

    Esta función contiene varias funciones del Heap, pero la que tiene mayor complejidad es la acción "add", que tiene complejidad de O(logN).

  - #### testPath

    Esta función contiene varias funciones del Path, pero las más complejas tienen complejidad de O(N).

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

Esta evidencia se encuentra presente en las clases Data, Heap y DList.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera

Esta evidencia se encuentra presente en la función readData de la clase Data, la cual accede a un archivo de puntos generados aleatoriamente por un script de Python.

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera

Esta evidencia se encuentra presente en la función createFiles de la clase Data, la cual genera un archivo donde se colocan las coordenadas en formato de lista, y otro donde se colocan en formato de grafo según sus distancias al origen seleccionado.
