#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "coordinate.h"
#include "graph.h"
#include "KDTree.h"
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
	void testGraph();
	void testStructures();
	void createFiles(int, int);

private:
	vector<Coordinate<T>> coords;
	KDTree<Coordinate<T>> tree;
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
		tree.add(Coordinate<T>(coord_x, coord_y));
	}

	cout << "\nKDTree created\n";
	inFile.close();
}

/*
  Imprime la lista de coordenadas
*/
template <class T>
void Data<T>::print()
{
	cout << "\n-------------------------- Lista de subestaciones -------------------------\n\n";
	for (int i = 0; i < coords.size(); i++)
	{
		cout << "Subestación " << i << ".-" << coords[i].toString();
		cout << endl;
	}

	cout << "\n------ Coordenadas ordenadas en un KDTree de 2 dimensiones -------\n\n";
	cout << tree.levelorder();
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

template <class T>
void Data<T>::testStructures()
{
	cout << "\n\nAltura: " << tree.height();

	T temp1, temp2;
	cout << "\n\nAgrega una nueva Subestación:\nCoordenada X: ";
	cin >> temp1;
	cout << "Coordenada Y: ";
	cin >> temp2;

	Coordinate<int> coord(temp1, temp2);

	tree.add(coord);
	coords.push_back(coord);

	cout << "\nSe agregó una subestación en la ubicación: " << coord.toString();

	cout << "\n\nAltura: " << tree.height() << "\n\n";

	cout << tree.levelorder();

	cout << "\n\nEncuentra una Subestación según su coordenada:\nCoordenada X: ";
	cin >> temp1;
	cout << "Coordenada Y: ";
	cin >> temp2;

	coord.set(temp1, temp2);

	cout << "\n\n¿Hay una Subestación en " << coord.toString() << "?: " << (tree.find(coord) ? "Sí" : "No") << endl;

	while (true)
	{
		cout << "\n\nElimina una Subestación según su coordenada:\nCoordenada X: ";
		cin >> temp1;
		cout << "Coordenada Y: ";
		cin >> temp2;

		coord.set(temp1, temp2);
		if (tree.find(coord))
		{
			tree.remove(coord);
			cout << "\nSubestación eliminada.\n";
			break;
		}
		else
		{
			cout << "\nNo hay ninguna Subestación en esa coordenada.\n";
		}
	}

	cout << "\n\nAltura: " << tree.height() << "\n\n";

	cout << tree.levelorder();
}

template <class T>
void Data<T>::createFiles(int start, int goal)
{
	ofstream myfile;
	myfile.open("path.txt");
	myfile << "------- Camino optimizado ------\n\n";

	myfile << graph.BFS(start, goal);

	myfile.close();
	cout << "\n\nSe imprimió la ruta que debe seguir a 'path.txt'";
	myfile.open("graph.txt");
	myfile << "------- Grafo de conexiones ------\n\n";

	myfile << graph.printAdjList();

	myfile.close();

	cout << "\n\nSe imprimió el grafo de conexiones a 'graph.txt'";

	myfile.open("tree.txt");
	myfile << "------- KDTree de 2 dimensiones ------\n\n";
	myfile << tree.levelorder();
	myfile.close();
	cout << "\n\nSe imprimió el KDTree de 2 dimensiones a 'tree.txt'";
}