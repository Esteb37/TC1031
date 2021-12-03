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
