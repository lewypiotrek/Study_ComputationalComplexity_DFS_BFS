#include<iostream>
#include "Graph.h"

using namespace std;

int main()
{

	Graph g;

	//g.InsertGraphByFile("TestExample.txt");

	//g.DFS(2);
	//cout << endl;
	//g.BFS(2);
	cout << "Starting...\n";
	g.GenerateRandomGraph(10,10);
	g.InsertGraphByFile("TestExample.txt");


	cout << endl << endl;
	system("pause");
	return 0;
}