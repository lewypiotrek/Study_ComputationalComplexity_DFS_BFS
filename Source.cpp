#include<iostream>
#include "Graph.h"
#include <ctime>

using namespace std;

int main()
{
	// create object Graph
	Graph g;
	cout << "Starting...\n";

	// setting precision
	cout.setf(ios::fixed);
	cout.precision(6);

	//g.GenerateRandomGraph(100000, 100000);
	g.InsertGraphByFile("RandomGraph");


	//------------- CHECK ALGORITHMS DURATIONS -------------
	clock_t begBFS, endBFS, begDFS, endDFS;

	// BFS 
	begBFS= clock();
	g.BFS(2);
	endBFS = clock();

	// DFS
	//begDFS = clock();
	//g.DFS(2);
	//endDFS = clock();

	double diffBFS = (endBFS - begBFS) / (double)CLOCKS_PER_SEC;
	//double diffDFS = (endDFS - begDFS) / (double)CLOCKS_PER_SEC;

	cout << "\n\tDuration BFS: " << diffBFS << "\n";
	//cout << "\n\tDuration DFS: " << diffDFS << "\n";
	//--------------------------------------------------------
	cout << endl << endl;
	system("pause");
	return 0;
}