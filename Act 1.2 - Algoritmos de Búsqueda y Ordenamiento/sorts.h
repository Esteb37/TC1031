#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Sorts
{
private:
  void swap(vector<T> &, int, int);
  void mergeArray(vector<T> &, vector<T> &, int, int, int);
  void copyArray(vector<T> &, vector<T> &, int, int);
  void mergeSplit(vector<T> &, vector<T> &, int, int);
  int busqBinariaAux(vector<T> &, int, int, int);

public:
  Sorts(/* args */);
  void ordenaSeleccion(vector<T> &);
  void ordenaBurbuja(vector<T> &);
  void ordenaMerge(vector<T> &);
  int busqSecuencial(vector<T> &, int);
  int busqBinaria(vector<T> &, int);
};

template <class T>
Sorts<T>::Sorts(/* args */)
{
}

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j)
{
  T aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, std::vector<T> &B, int low, int mid, int high)
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
      i++;
    }
    else
    {
      B[k] = A[j];
      j++;
    }
    k++;
  }
  if (i > mid)
  {
    for (; j <= high; j++)
    {
      B[k++] = A[j];
    }
  }
  else
  {
    for (; i <= mid; i++)
    {
      B[k++] = A[i];
    }
  }
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high)
{
  for (int i = low; i <= high; i++)
  {
    A[i] = B[i];
  }
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high)
{
  int mid;

  if ((high - low) < 1)
  {
    return;
  }
  mid = (high + low) / 2;
  mergeSplit(A, B, low, mid);
  mergeSplit(A, B, mid + 1, high);
  mergeArray(A, B, low, mid, high);
  copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &v)
{
  int pos;

  for (int i = v.size() - 1; i > 0; i--)
  {
    pos = 0;
    for (int j = 1; j <= i; j++)
    {
      if (v[j] > v[pos])
      {
        pos = j;
      }
    }

    if (pos != i)
    {
      swap(v, i, pos);
    }
  }
}

template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &v)
{
  for (size_t i = v.size() - 1; i > 0; i--)
  {
    for (size_t j = 0; j < i; j++)
    {
      if (v[j] > v[j + 1])
      {
        swap(v, j, j + 1);
      }
    }
  }
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &v)
{
  vector<T> tmp(v.size());
  mergeSplit(v, tmp, 0, v.size() - 1);
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int num)
{
  for (size_t i = 0; i < v.size(); i++)
  {
    if (v[i] == num)
    {
      return i;
    }
  }
  return -1;
}

template <class T>
int Sorts<T>::busqBinariaAux(vector<T> &v, int num, int left, int right)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;
    if (v[mid] < num)
      return busqBinariaAux(v, num, mid + 1, right);
    if (v[mid] > num)
      return busqBinariaAux(v, num, left, mid - 1);
    return mid;
  }
  return -1;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int num)
{
  return busqBinariaAux(v, num, 0, v.size() - 1);
}
