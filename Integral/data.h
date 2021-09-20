#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
  Clase para manejar los datos recibidos, ordenarlos y procesarlos.
  Autor: Esteban Padilla Cerdio
  Creado: 19 de septiembre de 2021
  Última versión: 20 de septiembre de 2021
  Título: data.h
*/

class Data
{
public:
  Data(){};

  void readFile(string);
  void print();
  void sortByX();
  void sortByY();

  vector<int> getXCoords();
  vector<int> getYCoords();

private:
  vector<int> x_coords;
  vector<int> y_coords;

  void mergeSort(bool);

  void mergeArray(vector<int> &, vector<int> &, vector<int> &, vector<int> &, int, int, int);
  void copyArray(vector<int> &, vector<int> &, int, int);
  void mergeSplit(vector<int> &, vector<int> &, vector<int> &, vector<int> &, int, int);
};

/*
  Lee los datos de coordenadas de un archivo de texto y los guarda en vectores.
*/
void Data::readFile(string fileName)
{
  ifstream inFile;

  inFile.open(fileName);
  if (!inFile)
  {
    cout << "No se encontró el archivo";
    return;
  }

  int coord;

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
void Data::print()
{

  for (int i = 0; i < x_coords.size(); i++)
  {
    cout << x_coords[i] << " " << y_coords[i] << endl;
  }
}

vector<int> Data::getXCoords()
{
  return x_coords;
}

vector<int> Data::getYCoords()
{
  return y_coords;
}

void Data::sortByX()
{
  mergeSort(true);
}

void Data::sortByY()
{
  mergeSort(false);
}

void Data::mergeSort(bool byX)
{

  int size = x_coords.size();
  vector<int> tmp_main(size);
  vector<int> tmp_other(size);

  if (byX)
  {
    mergeSplit(x_coords, tmp_main, y_coords, tmp_other, 0, size - 1);
  }
  else
  {
    mergeSplit(y_coords, tmp_main, x_coords, tmp_other, 0, size - 1);
  }
}

void Data::mergeArray(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D, int low, int mid, int high)
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

void Data::copyArray(vector<int> &A, vector<int> &B, int low, int high)
{
  for (int i = low; i <= high; i++)
  {
    A[i] = B[i];
  }
}

void Data::mergeSplit(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D, int low, int high)
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