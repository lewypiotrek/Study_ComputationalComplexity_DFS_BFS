#pragma once
#include<list>
#include<iostream>
#include<fstream>
#include <string>
#include <random>
#include <time.h>
#include <stack>

using namespace std;


class Graph
{
private:
	bool isCorrect;
	int V;    // No. of vertices 
	int C;	  // No. of Connections
	list<int> *adj;
	//void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	Graph();
	~Graph();

	void InsertGraphByFile(string name);
	void GenerateRandomGraph(int e, const int N);
	void addEdge(int v, int w);
	bool GetCorrect();

	void BFS(int s);
	void DFS(int v);
};

