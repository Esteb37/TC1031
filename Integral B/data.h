#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "coordinate.h"
#include "graph.h"

using namespace std;

/*
  Clase para manejar los datos recibidos, ordenarlos y procesarlos.
  Autor: Esteban Padilla Cerdio
  Creado: 19 de septiembre de 2021
  Última versión: 1 de noviembre de 2021
  Título: data.h
*/

template <class T>
class Data
{
public:
	Data(){};

	void readFile(string);
	void createDistanceGraph(int);
	void print();
	string findPath(int, int);

private:
	vector<Coordinate<T>> coords;
	Graph<T> graph;
};

/*
  Lee los datos de coordenadas de un archivo de texto y los guarda en vectores.
*/
template <class T>
void Data<T>::readFile(string fileName)
{
	ifstream inFile;

	inFile.open(fileName);
	if (!inFile)
	{
		cout << "No se encontró el archivo";
		return;
	}

	T coord_x;
	T coord_y;

	while (inFile >> coord_x)
	{
		inFile >> coord_y;
		coords.push_back(Coordinate<T>(coord_x, coord_y));
	}

	inFile.close();
}

/*
  Imprime la lista de coordenadas
*/
template <class T>
void Data<T>::print()
{
	for (int i = 0; i < coords.size(); i++)
	{
		cout << "Subestación " << i << ".-" << coords[i].toString();
		cout << endl;
	}
}

template <class T>
void Data<T>::createDistanceGraph(int distance)
{
	graph.createDistanceGraph(coords, distance);

	cout << graph.printAdjList();
}

template <class T>
string Data<T>::findPath(int start, int goal)
{
	return graph.BFS(start, goal);
}