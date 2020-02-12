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

	//g.GenerateRandomGraph(40, 40);
	g.InsertGraphByFile("RandomGraph");


	//------------- CHECK ALGORITHMS DURATIONS -------------
	clock_t begBFS, endBFS, begDFS, endDFS;

	cout << "Results: \n BFS: ";
	// BFS 
	if (g.GetCorrect())
	{
		begBFS= clock();
		g.BFS(0);
		endBFS = clock();
	}

	cout << "\t\n DFS: ";
	// DFS
	if (g.GetCorrect())
	{
		begDFS = clock();
		g.DFS(0);
		endDFS = clock();
	}

	double diffBFS = (endBFS - begBFS) / (double)CLOCKS_PER_SEC;
	double diffDFS = (endDFS - begDFS) / (double)CLOCKS_PER_SEC;

	cout << "\n Duration BFS: " << diffBFS;
	cout << "\n Duration DFS: " << diffDFS << "\n";
	//--------------------------------------------------------


	cout << endl << endl;
	system("pause");
	return 0;
}