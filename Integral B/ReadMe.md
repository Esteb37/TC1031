# Algoritmo de generación de rutas a partir de coordenadas para sistemas robóticos de movimiento autónomo

## Esteban Padilla Cerdio

## A01703068

Este programa tiene como propósito representar una situación hipotética donde un Rover de investigación científica en Marte debe optimizar sus movimientos a través de las distintas subestaciones, registrando los resultados de sus distintos sensores de forma estructurada. En esta situación, el Rover utiliza oxígeno líquido para moverse una distancia máxima, por lo que debe planear sus trayectos tomando en cuenta que debe recargar su combustible en las subestaciones científicas.

<img src="https://d7lju56vlbdri.cloudfront.net/var/ezwebin_site/storage/images/_aliases/seo/reportajes/diez-claves-sobre-el-rover-perseverance-y-otras-nuevas-misiones-a-marte/8668097-4-esl-MX/Diez-claves-sobre-el-rover-Perseverance-y-otras-nuevas-misiones-a-Marte.jpg" width=500px height=250px/>

<img src="https://www.nasa.gov/sites/default/files/thumbnails/image/pia21720.jpg" width=500px />

## SICT0302B: Toma decisiones

## Usa grafos para hacer analisis de información

El programa utiliza un grafo para representar las posibles subestaciones a las cuales el rover puede llegar desde el lugar en donde está, basado en la distancia máxima que puede recorrer con un tanque de combustible lleno. El grafo se genera iterando a través de cada uno de los puntos, y obteniendo la lista de puntos que se encuentran a una distancia menor que la distancia máxima recorrible.

## Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema

El programa utiliza un algoritmo de Breadth Search First para encontrar una posible ruta entre el punto en el que se encuentra el rover y el punto al que quiere llegar, de forma que nunca tenga que recorrer más distancia de la que es capaz con un solo tanque de combustible.

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

Esta evidencia se encuentra en la función testStructures, que le permite al usuario agregar, encontrar y buscar coordenadas específicas. Igualmente, el Main le permite al usuario elegir una distancia máxima por tanque de combustible que puede recorrer el rover, la subestación actual y la subestación a la que quiere llegar, para que pueda observar la generación de un grafo y cómo éste se utiliza para encontrar un camino optimizado entre los dos puntos.

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

- ### Main
  La función con mayor complejidad utilizada aquí es de O(N<sup>2</sup>), por lo que esa sería la complejidad del programa
- ### Coordinate

  Todas las funciones de esta clase tienen una complejidad de O(1), ya que cada objeto consiste únicamente de dos puntos, y todas las operaciones se realizan a partir de esos dos únicos elementos.

- ### Graph

  - #### addEdgeAdjList, addEdgeAdjMatrix
    La complejidad es de O(1), ya que solamente se está agregando un valor en un punto específico de la estructura
  - #### printAdjList, printAdjMat
    En el peor de los casos, donde todos los nodos están conectados, tienen una complejidad de O(N<sup>2</sup>), ya que por cada nodo se tendrían que publicar todos los nodos con los que se conecta
  - #### BFS, breadthHelper, contains
    En el peor de los casos, se visitará cada vértice y cada edge, por lo que la complejidad sería de O(V+E)
  - #### print_path
    En el peor de los casos, la ruta generada atraviesa todos los nodos, por lo que tendría una complejidad de O(N)
  - #### createDistanceGraph
    La función atraviesa cada nodo y lo compara con todos los demás nodos para ver si está a una distancia accesible, por lo que tiene una complejidad de O(N<sup>2</sup>)

- ### KDTree

  - #### empty
    Sin importar la cantidad de datos, esta función solo realiza una acción, por lo que tiene complejidad de O(1)
  - #### add, find, remove
    Puesto que es un tipo de BST, estos algoritmos van reduciendo la cantidad de datos a iterar a la mitad con cada iteración, por lo que la complejidad termina siendo de O(logN)
  - #### levelOrder
    Esta función debe pasar por todos los nodos para poder imprimirlos, por lo que tiene una complejidad de O(N)
  - #### height
    Para encontrar el punto en el nivel más bajo, se debe atravesar todo el árbol, por lo que tiene una complejidad de O(N)

- ### Data
  - #### readFile
    Esta función atraviesa todas las líneas del archivo para extraer las coordenadas, por lo que tiene una complejidad de O(N)
  - #### createDistanceGraph
    Solo llama a la función de mismo nombre graph, por lo que tiene la misma complejidad de O(N<sup>2</sup>)
  - #### print
    Esta función imprime todos los nodos, por lo que tiene una complejidad de O(N)
  - #### findPath
    Esta función manda a llamar el BFS del grafo, el cual tiene una complejidad de O(V+E)
  - #### testStructures
    Dentro de esta función se mandan a llamar el insert, remove y find del árbol, por lo que tiene una complejidad de O(logN)
  - #### createFiles
    La función más compleja dentro de esta función tiene una complejidad de O(N<sup>2</sup>)

## SEG0702A: Tecnologías de Vanguardia

### Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso.

- ### KDTree
  El KDTree es una evolución del Árbol de Búsqueda Binaria, pero que puede manejar más de una dimensión. Proviene del nombre <b>K-Dimensional Tree</b>, donde la K es una cantidad de dimensiones específicas. Es especialmente útil cuando se trabaja con sistemas de coordenadas de 2 o 3 dimensiones, ya que permite el ordenamiento y búsqueda de dichas coordenadas con la velocidad de un BST.

### Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos

Para la inserción de un elemento en un KDTree de 2 dimensiones, como se utilizó en este proyecto, suceden los siguientes pasos.

- Se inserta el primer elemento, que estará alineado en X
- Al insertar el siguiente elemento, se compara solamente su coordenada X con la coordenada X de la raíz, para determinar si irá a la derecha o a la izquierda. Se inserta el nodo en un nuevo nivel, debajo de la raíz. Los nodos de este segundo nivel estarán ahora alineados en Y
- Se inserta el tercer elemento, compara su valor en X con la raíz, y si se encuentra con un nodo en el siguiente nivel, ahora compara su valor en Y.
- Se repite conforme se van agregando coordenadas, con cada nivel alineándose de forma alternante en X o en Y. Por ejemplo:

  <img src="https://www.geeksforgeeks.org/wp-content/uploads/ktree_1.png"/>

De esta forma, al buscar un nodo para recuperarlo o eliminarlo, se puede saber si se está ordenando con base en su coordenada en X o en su coordenada en Y según el nivel en el que se encuentre. Para la consulta y la eliminación, se repite el proceso de comparar en X y en Y de forma alternante según el nivel hasta encontrar la coordenada que se está buscando. Todos los demás procesos funcionan igual que un BST normal.

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

El programa le permite al usuario realizar las siguientes acciones:

- Ordenar las coordenadas en un árbol de 2 dimensiones
- Agregar una nueva subestación a este árbol
- Eliminar una subestación
- Descubrir si existe una subestación en una coordenada específica
- Seleccionar la distancia que puede recorrer el rover con un solo tanque
- Con este dato se genera un grafo conectado según la distancia entre cada subestación
- Seleccionar la subestación en la que se encuentra
- Seleccionar la subestación a la que quiere llegar
- Con esta información, se utiliza el grafo para encontrar la ruta más eficiente entre los puntos seleccionados

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.

Esta evidencia se demuestra al inicio del programa con la función readFile, el cual extrae las coordenadas del archivo "points.txt" y genera con ellos un vector de puntos y un KDTree de 2 dimensiones.

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.

Esta evidencia se demuestra con la función createFiles, la cual genera tres archivos:

- "path.txt" contiene la ruta que debe seguir el rover para llegar a su destino sin quedarse varado sin gasolina.
- "graph.txt" contiene la lista de subestaciones a las que puede llegar el rover con un solo tanque de gasolina desde cada una de las coordenadas de la lista.
- "tree.txt" contiene las coordenadas de las subestaciones ordenadas por un KDTree, expuestas en formato de orden por niveles.
