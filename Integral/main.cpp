
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "data.h"

using namespace std;

/*
  Programa  para generar rutas a partir de coordenadas para sistemas robóticos de movimiento autónomo
  Autor: Esteban Padilla Cerdio
  Creado: 19 de septiembre de 2021
  Última versión: 20 de septiembre de 2021
  Título: main.cpp
*/

int main()
{

  Data data;

  data.readFile("points.txt");

  cout << "---- Sorted by X Coordinates: ----" << endl;
  data.sortByX();
  data.print();

  cout << "---- Sorted by Y Coordinates: ----" << endl;
  data.sortByY();
  data.print();

  return 0;
}