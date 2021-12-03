
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <cstdio>

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

	SetConsoleOutputCP(CP_UTF8);

	// Enable buffering to prevent VS from chopping up UTF-8 byte sequences
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	Data<int> data;

	data.readFile("points.txt");

	data.print();

	int maxDist;

	cout << "\nDistancia máxima que el rover puede recorrer con un tanque (para mejores resultados, mantener el valor entre 400 y 1000): ";
	cin >> maxDist;

	data.createDistanceGraph(maxDist);
	int start, goal;

	cout << "\n¿En qué subestación se encuentra el rover? ";
	cin >> start;
	cout << "\n¿A cuál subestación necesita llegar? ";
	cin >> goal;
	cout << data.findPath(start, goal);
	cout << endl;
	return 0;
}