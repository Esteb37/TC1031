
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "data.h"

using namespace std;

int main()
{

  Data data;

  data.readFile("points.txt");

  cout << "---- Sorted by X Coordinates: ----" << endl;
  data.sortByX();

  cout << "---- Sorted by Y Coordinates: ----" << endl;
  data.sortByY();

  return 0;
}