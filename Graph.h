#pragma once
#include<list>
#include<iostream>
#include<fstream>
#include <string>
#include <random>

using namespace std;

class Graph
{
private:
	int V;    // No. of vertices 
	int C;	  //  // No. of Connections
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);  // Constructor 
	Graph();
	~Graph();

	void InsertGraphByFile(string name);

	void GenerateRandomGraph(int e, const int N);

	// function to add an edge to graph 
	void addEdge(int v, int w);

	void BFS(int s);
	void DFS(int v);




};

