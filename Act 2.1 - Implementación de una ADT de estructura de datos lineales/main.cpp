/*
 * main.cpp
 *
 *  Created on: 10/08/2020
 *      Author: bvaldesa
 */
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "list.h"

using namespace std;


/* Agregar un metodo toString a su clase.h

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
*/

int main(int argc, char* argv[]) {
	List<int> b1;
	string ans;

	b1.insertion(2);
	ans = "[2]";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.insertion(3);
	b1.insertion(6);
	b1.insertion(10);
	ans = "[2, 3, 6, 10]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"3.- esperada " << 3 << " programa " << b1.search(10) << "\n";
	cout <<	(3 == b1.search(10) ? "success\n" : "fail\n");

	cout << "\n" <<"4.- esperada " << -1 << " programa " << b1.search(1) << "\n";
	cout <<	(-1 == b1.search(1) ? "success\n" : "fail\n");

	b1.update(1,13);
	ans = "[2, 13, 6, 10]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.update(3,32);
	ans ="[2, 13, 6, 32]";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout << (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.deleteAt(0);
	ans = "[13, 6, 32]";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.deleteAt(1);
	ans = "[13, 32]";
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

}
