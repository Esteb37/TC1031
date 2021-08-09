/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementacion Grafos
*  desc: estos programas son solciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*
*/

#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {

    Graph g;
    Graph star;

    string g_ans, g_ans_2;
    string star_ans, star_ans_2;

    g.loadGraphList("g.txt", 7, 7);
    star.loadGraphList("star.txt", 5, 5);

    g.loadGraphMat("g.txt", 7, 7);
    star.loadGraphMat("star.txt", 5, 5);

    //g.printAdjList()
    g_ans ="vertex 0 : 1 4 vertex 1 : 0 2 3 vertex 2 : 1 vertex 3 : 1 6 vertex 4 : 0 5 vertex 5 : 4 vertex 6 : 3 ";
    cout << "\n" <<"1.- esperada " << g_ans << "\n programa " << g.printAdjList() << "\n";
    cout <<	(!g_ans.compare(g.printAdjList()) ? "success\n" : "fail\n");

    //star.printAdjList()
    star_ans="vertex 0 : 1 2 3 4 vertex 1 : 0 2 3 4 vertex 2 : 0 1 3 4 vertex 3 : 0 1 2 4 vertex 4 : 0 1 2 3 ";
    cout << "\n" <<"2.- esperada " << star_ans << "\n programa " << star.printAdjList() << "\n";
    cout <<	(!star_ans.compare(star.printAdjList()) ? "success\n" : "fail\n");

    //g.printAdjMat()
    g_ans = "0 1 0 0 1 0 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 ";
    cout << "\n" <<"3.- esperada " << g_ans << "\n programa " << g.printAdjMat() << "\n";
    cout <<	(!g_ans.compare(g.printAdjMat()) ? "success\n" : "fail\n");

    //star.printAdjMat()
    star_ans ="0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 ";
    cout << "\n" <<"4.- esperada " << star_ans << "\n programa " << star.printAdjMat() << "\n";
    cout << 	(!star_ans.compare(star.printAdjMat()) ? "success\n" : "fail\n");

    //g.DFS(0,3);
    g_ans = "visited: 0 4 5 1 3 path: 0 1 3";
    g_ans_2 = "visited: 0 1 2 3 path: 0 1 3";
    cout << "\n" <<"5.- esperada 1 " << g_ans << "\n esperada 2 " << g_ans_2 <<"\n programa " << g.DFS(0,3) << "\n";
    cout <<	( (!g_ans.compare(g.DFS(0,3)) || !g_ans_2.compare(g.DFS(0,3))) ? "success\n" : "fail\n");

    //star.DFS(0,3);
    star_ans = "visited: 0 4 3 path: 0 4 3";
    star_ans_2 = "visited: 0 1 2 3 path: 0 1 2 3";
    cout << "\n" <<"6.- esperada 1 " << star_ans << "\n esperada 2 " << star_ans_2 <<"\n programa " << star.DFS(0,3) << "\n";
    cout <<	( (!star_ans.compare(star.DFS(0,3)) || !star_ans_2.compare(star.DFS(0,3)))? "success\n" : "fail\n");


    //g.BFS(0,3);
    g_ans = "visited: 0 1 4 2 3 path: 0 1 3";
    g_ans_2 = "visited: 0 4 1 5 3 path: 0 1 3";
    cout << "\n" <<"7.- esperada 1 " << g_ans << "\n esperada 2 " << g_ans_2 <<"\n programa " << g.BFS(0,3) << "\n";
    cout <<	(( !g_ans.compare(g.BFS(0,3)) || !g_ans_2.compare(g.BFS(0,3))) ? "success\n" : "fail\n");

    //star.BFS(0,3);
    star_ans = "visited: 0 1 2 3 path: 0 3";
    star_ans_2 = "visited: 0 4 3 path: 0 3";
    cout << "\n" <<"8.- esperada 1 " << star_ans << "\n esperada 2 " << star_ans_2 <<"\n programa " << star.BFS(0,3) << "\n";
    cout <<	((!star_ans.compare(star.BFS(0,3)) || !star_ans_2.compare(star.BFS(0,3))) ? "success\n" : "fail\n");

}
