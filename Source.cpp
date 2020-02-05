#include<iostream>
#include "Graph.h"
#include <exception>



using namespace std;



int main()
{

	Graph g;

	//g.InsertGraphByFile("TestExample.txt");

	//g.DFS(2);
	//cout << endl;
	//g.BFS(2);

	g.GenerateRandomGraph(10,10);


	cout << endl << endl;
	system("pause");
	return 0;
}