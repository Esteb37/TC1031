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
#include "heap.h"

using namespace std;

/* Agregue en tu heap.h el metodo to string

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}
*/

int main(int argc, char* argv[]) {
	Heap<int> heap(20);
	string ans;
	heap.push(8);

  ans =	"[8]";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	heap.push(20);
	heap.push(31);
	heap.push(5);
	heap.push(87);
	ans ="[5 8 31 20 87]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	heap.pop();
	ans ="[8 20 31 87]";
	cout << "\n" <<"3.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"4.- esperada " << 4 << " programa " << heap.size() << "\n";
	cout <<	((4 == heap.size()) ? "success\n" : "fail\n");

	heap.pop();
	ans ="[20 87 31]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"6.- esperada " << 3 << " programa " << heap.size() << "\n";
	cout <<	((3 == heap.size()) ? "success\n" : "fail\n");

	cout << "\n" <<"7.- esperada " << 20 << " programa " << heap.top() << "\n";
	cout << ((20 == heap.top()) ? "success\n" : "fail\n");

	cout << "\n" <<"8.- esperada " << 0 << " programa " << heap.empty() << "\n";
	cout <<	((0 == heap.empty()) ? "success\n" : "fail\n");

	heap.pop();

	cout << "\n" <<"9.- esperada " << 31 << " programa " << heap.top() << "\n";
	cout <<	((31 == heap.top()) ? "success\n" : "fail\n");

	heap.pop();

	cout << "\n" <<"10.- esperada " << 0 << " programa " << heap.empty() << "\n";
	cout <<	((0 == heap.empty()) ? "success\n" : "fail\n");

}
