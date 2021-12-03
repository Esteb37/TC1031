/*
 * graph.h
 *
 *  Created on: 30/10/2015
 *      Author: clase
 *
 */

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <fstream>
#include "coordinate.h"
using namespace std;

template <class T>
class Graph
{
private:
	int edgesList;
	int edgesMat;
	int nodes;
	std::vector<int> *adjList;
	int *adjMatrix;
	vector<Coordinate<T>> coords;

public:
	Graph();
	Graph(int);
	void addEdgeAdjList(int, int);
	void addEdgeAdjMatrix(int, int);
	string printAdjList();
	string printAdjMat();
	string BFS(int, int);
	void breadthHelper(int, int, queue<int> &, list<int> &, vector<vector<int>> &);
	string print_visited(list<int>);
	string print_path(vector<vector<int>> &, int, int);
	bool contains(list<int>, int);
	void sortAdjList();
	void createDistanceGraph(vector<Coordinate<T>>, int);
};

template <class T>
Graph<T>::Graph()
{
}

template <class T>
Graph<T>::Graph(int n)
{
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int[nodes * nodes];
	for (int i = 0; i < nodes * nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

template <class T>
void Graph<T>::createDistanceGraph(vector<Coordinate<T>> coords_, int distance)
{
	coords = coords_;
	nodes = coords.size();
	adjList = new vector<int>[nodes];
	adjMatrix = new int[nodes * nodes];
	for (int i = 0; i < nodes * nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;

	for (int i = 0; i < coords.size(); i++)
	{
		for (int j = 0; j < coords.size(); j++)
		{
			if (i != j && distance >= coords[i].getDistance(coords[j]))
			{
				addEdgeAdjList(i, j);
				addEdgeAdjMatrix(i, j);
			}
		}
	}
}

template <class T>
void Graph<T>::addEdgeAdjList(int u, int v)
{
	adjList[u].push_back(v);
	edgesList++;
}

template <class T>
void Graph<T>::addEdgeAdjMatrix(int u, int v)
{
	adjMatrix[u * nodes + v] = 1;
	adjMatrix[v * nodes + u] = 1;
	edgesMat++;
}

template <class T>
string Graph<T>::printAdjList()
{
	stringstream aux;
	for (int i = 0; i < nodes; i++)
	{
		aux << coords[i].toString() << " :\n\n";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			aux << "\t" << coords[adjList[i][j]].toString() << " a " << coords[i].getDistance(coords[adjList[i][j]]) << "mts" << endl;
		}
		aux << endl;
	}
	return aux.str();
}

template <class T>
void Graph<T>::sortAdjList()
{
	for (int i = 0; i < nodes; i++)
		sort(adjList[i].begin(), adjList[i].end());
}

template <class T>
string Graph<T>::printAdjMat()
{
	stringstream aux;
	for (int i = 0; i < nodes; i++)
	{
		aux << endl
			<< coords[i].toString() << " :\n\n";
		for (int j = 0; j < nodes; j++)
		{
			aux << "\t" << coords[j].toString() << ":\t" << adjMatrix[i * nodes + j] << endl;
		}
	}
	return aux.str();
}

template <class T>
string Graph<T>::BFS(int start, int goal)
{

	queue<int> qu;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(0));
	qu.push(start);
	breadthHelper(start, goal, qu, visited, paths);

	return print_path(paths, start, goal);
}

template <class T>
void Graph<T>::breadthHelper(int current,
							 int goal,
							 queue<int> &qu,
							 list<int> &visited,
							 vector<vector<int>> &paths)
{

	if (current == goal)
	{
		print_visited(visited);
	}
	else if (qu.empty())
	{
		cout << "No hay rutas disponibles.";
	}
	else
	{
		current = qu.front();
		qu.pop();
		visited.push_back(current);
		for (int i = 0; i < adjList[current].size(); i++)
			if (!contains(visited, adjList[current][i]))
			{
				qu.push(adjList[current][i]);
				paths[adjList[current][i]].push_back(current);
			}
		breadthHelper(current, goal, qu, visited, paths);
	}
}

template <class T>
bool Graph<T>::contains(list<int> ls, int node)
{
	list<int>::iterator it;
	it = find(ls.begin(), ls.end(), node);
	if (it != ls.end())
		return true;
	else
		return false;
}

template <class T>
string Graph<T>::print_visited(list<int> q)
{
	stringstream aux;
	aux << "visited: ";
	while (!q.empty())
	{
		aux << q.front() << " ";
		q.pop_front();
	}
	return aux.str();
}

template <class T>
string Graph<T>::print_path(vector<vector<int>> &path, int start, int goal)
{
	int node = path[goal][0];
	stack<int> reverse;
	reverse.push(goal);
	stringstream aux;
	aux << "\nRuta:\n";
	while (node != start)
	{
		reverse.push(node);
		node = path[node][0];
	}
	reverse.push(start);
	while (!reverse.empty())
	{
		aux << "\tSubestación " << reverse.top() << " " << coords[reverse.top()].toString() << endl;
		reverse.pop();
	}
	string result = aux.str();
	result.pop_back();
	return result;
}

#endif /* Graph_H_ */
