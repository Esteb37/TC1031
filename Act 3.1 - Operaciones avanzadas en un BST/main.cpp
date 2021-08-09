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
#include "bst.h"

using namespace std;

int main(int argc, char* argv[]) {
	BST<int> bst;
	string  ans;

	bst.add(10);

	ans =	"[10]\n[10]\n[10]\n[10]";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << bst.visit() << "\n";
	cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << "\n" <<"2.- esperada " << 1  << "\n programa " << bst.height() << "\n";
	cout << 	(1 == bst.height() ? "success\n" : "fail\n");

	bst.add(12);
	bst.add(8);
	bst.add(110);
	bst.add(112);
	bst.add(18);

	ans = "[10 8 12 110 18 112]\n[8 10 12 18 110 112]\n[8 18 112 110 12 10]\n[10 8 12 110 18 112]";
	cout << "\n" <<"3.- esperada " << ans << "\n programa " << bst.visit() << "\n";
	cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << "\n" <<"4.- esperada " << 4  << "\n programa " << bst.height() << "\n";
	cout <<	(4 == bst.height() ? "success\n" : "fail\n");

	ans = "[10 12 110]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << bst.ancestors(112) << "\n";
	cout <<	(!ans.compare(bst.ancestors(112)) ? "success\n" : "fail\n");

	ans = "[]";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << bst.ancestors(1000) << "\n";
	cout <<	(!ans.compare(bst.ancestors(1000)) ? "success\n" : "fail\n");

	cout << "\n" <<"7.- esperada " << 4  << "\n programa " << bst.whatlevelamI(18) << "\n";
	cout << (4 == bst.whatlevelamI(18) ? "success\n" : "fail\n");

	cout << "\n" <<"8.- esperada " << 2  << "\n programa " << bst.whatlevelamI(8) << "\n";
	cout <<	(2 == bst.whatlevelamI(8) ? "success\n" : "fail\n");

}
