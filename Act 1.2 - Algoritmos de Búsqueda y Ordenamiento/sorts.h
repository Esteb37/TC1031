#include <iostream>
#include <vector>

using namespace std;

class Sorts
{
public:
  Sorts(){};

  vector<int> ordenaSeleccion(const vector<int> &);
  vector<int> ordenaBurbuja(const vector<int> &);
  vector<int> ordenaMerge(const vector<int> &);
  int busqSecuencial(const vector<int> &, int);
  int busqBinaria(const vector<int> &, int);

private:
  void swap(vector<int> &, int, int);
};

void Sorts::swap(vector<int> &v, int i, int j)
{
  int bin = v[i];
  v[i] = v[j];
  v[j] = bin;
}

vector<int> Sorts::ordenaBurbuja(const vector<int> &source)
{
  vector<int> v(source);

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
  return v;
};

vector<int> Sorts::ordenaSeleccion(const vector<int> &source)
{
  vector<int> v(source);
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
  return v;
}

vector<int> Sorts::ordenaMerge(const vector<int> &source)
{
  return source;
};
int Sorts::busqSecuencial(const vector<int> &source, int num)
{
  return num;
};
int Sorts::busqBinaria(const vector<int> &source, int num)
{
  return num;
};
