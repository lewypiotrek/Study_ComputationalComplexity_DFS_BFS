#include "Graph.h"
//#define N 10


Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

Graph::Graph()
{
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph()
{
	//delete adj;
}

void Graph::InsertGraphByFile(string FileName)
{
	fstream file;

	file.open(FileName, ios::in);

	if (file.good())
	{
		// read number of edges = v and read numbers of connections C
		file >> this->V;
		file >> this->C;

		this->V = V;
		adj = new list<int>[V];

		int n1, n2;

		for (int i = 0; i < C; i++)
		{
			file >> n1;
			file >> n2;
			addEdge(n1, n2);
		}

		// Close file 
		file.close();
	}
	else
	{
		cout << "ERROR: Cannot open file " << FileName << " ...\n";
	}


}

void Graph::GenerateRandomGraph(int e, const int N)
{

	int ** edge = new int * [e];

	for (int i = 0; i < e; i++)
		edge[i] = new int[2];

	int i, j, count;
	i = 0;
	// generate a connection between two random numbers, for //sample a small case, limit the number of vertex to 10.
	while (i < e) {
		edge[i][0] = rand() % N + 1;
		edge[i][1] = rand() % N + 1;
		i++;
	}
	//Print all the connection of each vertex, irrespective of the //direction.
	cout << "\nThe generated random graph is: ";
	for (i = 0; i < N; i++) {
		count = 0;
		cout << "\n\t" << i + 1 << " ";
		for (j = 0; j < e; j++) {
			if (edge[j][0] == i + 1) {
				cout << edge[j][1] << " ";
				count++;
			}
			else if (edge[j][1] == i + 1) {
				cout << edge[j][0] << " ";
				count++;
			}
			else if (j == e - 1 && count == 0)
				cout << " ";
		}
	}

}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}


void Graph::BFS(int s)
{

	// Mark all the vertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS 
	list<int> queue;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v)
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited);
}