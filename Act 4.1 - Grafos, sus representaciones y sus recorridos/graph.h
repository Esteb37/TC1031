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

using namespace std;

class Graph
{
private:
	int edgesList;
	int edgesMat;
	int nodes;
	std::vector<int> *adjList;
	int *adjMatrix;

public:
	Graph();
	Graph(int);
	void addEdgeAdjList(int, int);
	void addEdgeAdjMatrix(int, int);
	string printAdjList();
	string printAdjMat();
	string DFS(int, int);
	void depthHelper(int, int, stack<int> &, list<int> &, vector<vector<int>> &);
	string BFS(int, int);
	void breadthHelper(int, int, queue<int> &, list<int> &, vector<vector<int>> &);
	string print_visited(list<int>);
	string print_path(vector<vector<int>> &, int, int);
	bool contains(list<int>, int);
	void sortAdjList();
	void loadGraphList(string, int, int);
	void loadGraphMat(string, int, int);
};
Graph::Graph()
{
}
Graph::Graph(int n)
{
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int[nodes * nodes];
	for (int i = 0; i < nodes * nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjList(int u, int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}

void Graph::addEdgeAdjMatrix(int u, int v)
{
	adjMatrix[u * nodes + v] = 1;
	adjMatrix[v * nodes + u] = 1;
	edgesMat++;
}

string Graph::printAdjList()
{
	stringstream aux;
	for (int i = 0; i < nodes; i++)
	{
		aux << "vertex "
			<< i << " : ";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			aux << adjList[i][j] << " ";
		}
	}
	return aux.str();
}

void Graph::sortAdjList()
{
	for (int i = 0; i < nodes; i++)
		sort(adjList[i].begin(), adjList[i].end());
}

string Graph::printAdjMat()
{
	stringstream aux;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			aux << adjMatrix[i * nodes + j] << " ";
		}
	}
	return aux.str();
}

string Graph::DFS(int start, int goal)
{
	stack<int> st;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(1, -1));
	st.push(start);
	depthHelper(start, goal, st, visited, paths);
	return print_visited(visited) + print_path(paths, start, goal);
}

void Graph::depthHelper(int current,
						int goal,
						stack<int> &st,
						list<int> &visited,
						vector<vector<int>> &paths)
{

	if (current == goal)
	{
		print_visited(visited);
	}
	else if (st.empty())
	{
		cout << " node not found";
	}
	else
	{
		current = st.top();
		st.pop();
		visited.push_back(current);
		for (int i = 0; i < adjList[current].size(); i++)
			if (!contains(visited, adjList[current][i]))
			{
				st.push(adjList[current][i]);
				paths[adjList[current][i]][0] = current;
			}
		depthHelper(current, goal, st, visited, paths);
	}
}

string Graph::BFS(int start, int goal)
{

	queue<int> qu;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(0));
	qu.push(start);
	breadthHelper(start, goal, qu, visited, paths);
	string result = print_visited(visited) + print_path(paths, start, goal);
	return result;
}

void Graph::breadthHelper(int current,
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
		cout << " node not found";
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

bool Graph::contains(list<int> ls, int node)
{
	list<int>::iterator it;
	it = find(ls.begin(), ls.end(), node);
	if (it != ls.end())
		return true;
	else
		return false;
}

string Graph::print_visited(list<int> q)
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

string Graph::print_path(vector<vector<int>> &path, int start, int goal)
{
	int node = path[goal][0];
	stack<int> reverse;
	reverse.push(goal);
	stringstream aux;
	aux << "path: ";
	while (node != start)
	{
		reverse.push(node);
		node = path[node][0];
	}
	reverse.push(start);
	while (!reverse.empty())
	{
		aux << reverse.top() << " ";
		reverse.pop();
	}
	string result = aux.str();
	result.pop_back();
	return result;
}

void Graph::loadGraphList(string name, int a, int b)
{
	adjList = new vector<int>[a];
	nodes = a;
	string line;
	ifstream lee(name);
	int u, v;
	if (lee.is_open())
	{
		while (getline(lee, line))
		{
			u = stoi(line.substr(1, 1));
			v = stoi(line.substr(4, 1));
			addEdgeAdjList(u, v);
		}
		lee.close(); // Closes the file
	}
	else
	{
		cout << "Unable to open file";
	}
	sortAdjList();
}

void Graph::loadGraphMat(string name, int a, int b)
{
	adjMatrix = new int[a * b];
	nodes = a;
	for (int i = 0; i < a * b; i++)
		adjMatrix[i] = 0;
	string line;
	ifstream lee(name);
	int u, v;
	if (lee.is_open())
	{
		while (getline(lee, line))
		{
			u = stoi(line.substr(1, 1));
			v = stoi(line.substr(4, 1));
			addEdgeAdjMatrix(u, v);
		}
		lee.close(); // Closes the file
	}
	else
	{
		cout << "Unable to open file";
	}
}

#endif /* Graph_H_ */
