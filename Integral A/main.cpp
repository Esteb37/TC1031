
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
  Última versión: 1 de noviembre de 2021
  Título: main.cpp
*/

int main()
{

	Data<int> data;

	data.readFile("points.txt");

	cout << "\n---- Sorted by X Coordinates: ----\n"
		 << endl;
	data.sortByX();
	data.print();

	cout << "\n---- Sorted by Y Coordinates: ----\n"
		 << endl;
	data.sortByY();
	data.print();

	cout << "\n------ As a coordinate path: ------\n"
		 << endl;
	data.generatePath();
	data.printPath();

	cout << "\n\n----------- Testing path -----------"
		 << endl;

	data.testPath();

	cout << "\n\n------ As a heap: ------\n"
		 << endl;

	data.chooseOrigin();
	data.generateHeap();

	cout << "\n\n------------ Testing heap ------------"
		 << endl;
	data.testHeap();

	data.createFiles();
	return 0;
}