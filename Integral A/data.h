#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "dlist.h"
#include "heap.h"

using namespace std;

/*
  Clase para manejar los datos recibidos, ordenarlos y procesarlos.
  Autor: Esteban Padilla Cerdio
  Creado: 19 de septiembre de 2021
  Última versión: 1 de noviembre de 2021
  Título: data.h
*/

template <class T>
class DList;

template <class T>
class Data
{
public:
	Data(){};

	void readFile(string);
	void print();
	void sortByX();
	void sortByY();
	void generatePath();
	void printPath();
	void testPath();

	void generateHeap();
	void printHeap();
	void chooseOrigin();
	void testHeap();

	vector<T> getXCoords();
	vector<T> getYCoords();
	DList<T> getPath();

private:
	vector<T> x_coords;
	vector<T> y_coords;

	DList<T> x_list;
	DList<T> y_list;

	void mergeSort(bool);

	void mergeArray(vector<T> &, vector<T> &, vector<T> &, vector<T> &, int, int, int);
	void copyArray(vector<T> &, vector<T> &, int, int);
	void mergeSplit(vector<T> &, vector<T> &, vector<T> &, vector<T> &, int, int);

	Heap<T> heap;
	DList<T> path;
	Coordinate<T> origin;
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

	T coord;

	bool isX = true;
	while (inFile >> coord)
	{
		if (isX)
			x_coords.push_back(coord);
		else
			y_coords.push_back(coord);

		isX = !isX;
	}

	inFile.close();
}

/*
  Imprime la lista de coordenadas
*/
template <class T>
void Data<T>::print()
{

	for (int i = 0; i < x_coords.size(); i++)
	{
		cout << x_coords[i] << " " << y_coords[i] << endl;
	}
}

template <class T>
vector<T> Data<T>::getXCoords()
{
	return x_coords;
}

template <class T>
vector<T> Data<T>::getYCoords()
{
	return y_coords;
}

template <class T>
void Data<T>::sortByX()
{
	mergeSort(true);
}

template <class T>
void Data<T>::sortByY()
{
	mergeSort(false);
}

template <class T>
void Data<T>::generatePath()
{

	path.clear();

	Coordinate<T> aux;

	for (int i = 0; i < x_coords.size(); i++)
	{
		aux.set(x_coords[i], y_coords[i]);
		path.add(aux);
	}
}

template <class T>
void Data<T>::printPath()
{
	cout << path.toString();
}

template <class T>
void Data<T>::testPath()
{

	int temp1, temp2, temp3;

	cout << "\nFirst coordinate: " << path.getFirst().toString();

	cout << "\n\nLast coordinate: " << path.getLast().toString();

	cout << "\n\nLength: " << path.length();

	temp1 = -1;

	while (temp1 < 0 || temp1 >= path.length())
	{
		cout << "\n\nChoose an index to remove from the list: ";
		cin >> temp1;
		if (temp1 < 0 || temp1 >= path.length())
			cout << "\n\nIndex out of bounds.";
	}

	Coordinate<int> removed = path.remove(temp1);

	cout << "\nRemoved coordinate with value: " << removed.toString();

	cout << "\n\nLength: " << path.length();

	cout << "\n\nAdd a new coordinate to the list:\nX value: ";
	cin >> temp1;
	cout << "Y value: ";
	cin >> temp2;

	Coordinate<int> coord(temp1, temp2);

	path.add(coord);

	cout << "\nAdded coordinate with value: " << coord.toString();

	cout << "\n\nLength: " << path.length();

	cout << "\n\nFind a coordinate in the list:\nX value: ";
	cin >> temp1;
	cout << "Y value: ";
	cin >> temp2;

	coord.set(temp1, temp2);

	cout << "\n\nList contains " << coord.toString() << "?: " << path.contains(coord);

	cout << "\n\nSet a coordinate from the list:\nIndex: ";
	cin >> temp1;
	cout << "X value: ";
	cin >> temp2;
	cout << "Y value: ";
	cin >> temp3;

	coord.set(temp2, temp3);

	path.set(temp1, coord);

	cout << "\n\nSet " << coord.toString() << " in position " << temp1 << ".\n";
}

template <class T>
void Data<T>::mergeSort(bool byX)
{

	int size = x_coords.size();
	vector<T> tmp_main(size);
	vector<T> tmp_other(size);

	if (byX)
	{
		mergeSplit(x_coords, tmp_main, y_coords, tmp_other, 0, size - 1);
	}
	else
	{
		mergeSplit(y_coords, tmp_main, x_coords, tmp_other, 0, size - 1);
	}
}

template <class T>
void Data<T>::mergeArray(vector<T> &A, vector<T> &B, vector<T> &C, vector<T> &D, int low, int mid, int high)
{
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
		{
			B[k] = A[i];
			D[k] = C[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			D[k] = C[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		for (; j <= high; j++)
		{
			B[k] = A[j];
			D[k++] = C[j];
		}
	}
	else
	{
		for (; i <= mid; i++)
		{
			B[k] = A[i];
			D[k++] = C[i];
		}
	}
}

template <class T>
void Data<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		A[i] = B[i];
	}
}

template <class T>
void Data<T>::mergeSplit(vector<T> &A, vector<T> &B, vector<T> &C, vector<T> &D, int low, int high)
{
	int mid;

	if ((high - low) < 1)
	{
		return;
	}
	mid = (high + low) / 2;

	mergeSplit(A, B, C, D, low, mid);
	mergeSplit(A, B, C, D, mid + 1, high);
	mergeArray(A, B, C, D, low, mid, high);
	copyArray(A, B, low, high);
	copyArray(C, D, low, high);
}

template <class T>
void Data<T>::generateHeap()
{
	heap.setSize(path.length());

	DListIterator<T> iter(&path);
	iter.begin();

	for (int i = 0; i < path.length(); i++)
	{
		heap.add(iter());
		++iter;
	}

	cout << heap.toString();
}

template <class T>
void Data<T>::chooseOrigin()
{
	int index = -1;
	cout << "Select an origin coordinate to order the points in relation to their distance to the origin.";
	while (index < 0 || index >= path.length())
	{
		cout << "\nOrigin coordinate index: ";

		cin >> index;

		if (index < 0 || index >= path.length())
		{
			cout << "Index out of bounds.";
		}
	}

	origin = path.get(index);
	heap.setOrigin(origin);
}

template <class T>
void Data<T>::testHeap()
{
	int temp1, temp2, temp3;

	cout << "\n\nLength: " << heap.getCount();

	cout << "\n\nPopping root...";

	Coordinate<int> removed = heap.remove();

	cout << "\n\nRemoved coordinate with value: " << removed.toString();

	cout << "\n\nLength: " << heap.getCount();

	cout << "\n\nAdd a new coordinate to the heap:\nX value: ";
	cin >> temp1;
	cout << "Y value: ";
	cin >> temp2;

	Coordinate<int> coord(temp1, temp2);

	heap.add(coord);

	cout << "\nAdded coordinate with value: " << coord.toString();

	cout << "\n\nLength: " << heap.getCount();

	cout << heap.toString();
}