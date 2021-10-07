#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Coordinate
{
public:
	Coordinate();
	Coordinate(T, T);

	T getX() const;
	T getY() const;

	void set(T, T);

	void print() const;
	string toString() const;

	bool operator==(const Coordinate &);
	void operator=(const Coordinate &);

private:
	T x, y;
};

template <class T>
Coordinate<T>::Coordinate() : x(0), y(0) {}

template <class T>
Coordinate<T>::Coordinate(T vx, T vy) : x(vx), y(vy) {}

template <class T>
T Coordinate<T>::getX() const { return x; }

template <class T>
T Coordinate<T>::getY() const { return y; }

template <class T>
void Coordinate<T>::set(T vx, T vy)
{
	x = vx;
	y = vy;
}

template <class T>
void Coordinate<T>::print() const
{
	cout << toString() << endl;
}

template <class T>
string Coordinate<T>::toString() const
{
	std::stringstream aux;
	aux << "(" << x << ", " << y << ")";
	return aux.str();
}

template <class T>
bool Coordinate<T>::operator==(const Coordinate<T> &other)
{
	return other.x == x && other.y == y;
}

template <class T>
void Coordinate<T>::operator=(const Coordinate<T> &source)
{
	x = source.getX();
	y = source.getY();
}