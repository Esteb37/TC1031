# visit

## Análisis de complejidad temporal

La complejidad es O(N), ya que debe atravesar todas las hojas del árbol para poderlo publicar. Para esta función, se repite el proceso de impresión 4 veces, pero la complejidad se simplifica a O(N) de cualquier manera.

# height

## Análisis de complejidad temporal

Para obtener el nivel más bajo del árbol, se deben atravesar todas sus ramas, por lo que se tiene una complejida de O(N)

# ancestors

## Análisis de complejidad temporal

En este caso, solamente se atraviesa una sola de las ramas, la que contiene el número cuyos ancestros queremos obtener, por lo que la complejidad es de O(h), donde h es la altura del árbol. En el peor de los casos, para un árbol balanceado, también se considera como O(logN)

# whatlevelamI

## Análisis de complejidad temporal

En este caso también solamente se atraviesa una sola de las ramas, la que contiene el número cuyo nivel queremos obtener, por lo que la complejidad es de O(h), donde h es la altura del árbol. En el peor de los casos, para un árbol balanceado, también se considera como O(logN)
