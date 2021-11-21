"""
  Programa para generar una lista de coordenadas aleatoria
  Autor: Esteban Padilla Cerdio
  Creado: 19 de septiembre de 2021
  Última versión: 20 de septiembre de 2021
  Título: random_points.py
"""

import random

points = int(input("Number of points: "));
radius = int(input("Range: "))
pointlist = ""

for i in range(points):
  x = random.randint(0,radius);
  y = random.randint(0,radius);
  pointlist+="{0} {1}\n".format(x,y);

print(pointlist)

with open("points.txt","w") as file:
  file.write(pointlist);
