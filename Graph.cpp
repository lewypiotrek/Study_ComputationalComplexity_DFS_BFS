#include "Graph.h"

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	this->isCorrect = true;
}

Graph::Graph()
{
	this->V = 0;
	this->isCorrect = true;
}

Graph::~Graph()
{
	//delete adj;
}

//	UTILITIES
void Graph::InsertGraphByFile(string FileName)
{
	cout << "Inserting Graph by file. Please wait...\n\n";
	// Preparing file for reading
	fstream file;
	file.open(FileName, ios::in);

	if (file.good())
	{
		// Insert no. of verticals 
		file >> this->V;
		adj = new list<int>[V];

		// insert no. of connections
		file >> this->C;

		// additional variable for inserting edges
		int n1, n2;

		// inserting a pair of verticals
		for (int i = 0; i < C; i++)
		{
			file >> n1;
			file >> n2;
			addEdge(n1, n2);
		}

		file.close();

		cout << "\t Graph has been inserted by file " << FileName;
		cout << "\n\t-------------------------------------------\n\n";
	}
	else
	{
		isCorrect = false;
		cout << "ERROR: Cannot open file " << FileName << " ...\n";
	}
}

void Graph::GenerateRandomGraph(int e, const int N)
{
	cout << "Generating random graph. Please wait...\n\n";
	fstream file;

	int ** edge = new int * [e];
	for (int i = 0; i < e; i++)
		edge[i] = new int[2];

	int i, j, count, rows = 0;
	i = 0;

	while (i < e) {
		edge[i][0] = rand() % N;
		edge[i][1] = rand() % N;
		i++;
	}
	
	file.open("RandomGraph", ios::out);
	
	file << N << " ";
	file << e << "\n";

	for (i = 0; i < N; i++) {
		
		count = 0;

		//file << "\n"<< i + 1 << " ";

		for (j = 0; j < e; j++) {
			if (edge[j][0] == i) {
				file << i << " ";
				file << edge[j][1] << "\n";
				count++;
				rows++;
			}
			else if (edge[j][1] == i) {
				file << i << " ";
				file << edge[j][0] << "\n";
				count++;
				rows++;
			}
			else if (j == e - 1 && count == 0)
				file << "";
		}
	}
	file.seekg(0, std::ios::beg);
	//file << e <<" ";
	file << rows;

	cout << "\t Graph has been generated";
	cout << "\n\t-------------------------------------------\n\n";

	// close file
	file.close();

	// clear memory 
	for (int i = 0; i < e; i++)
		delete[] edge[i];

	delete[] edge;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}

bool Graph::GetCorrect()
{
	return this->isCorrect;
}


//	ALGORITHMS
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

	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		//cout << s << " ";
		queue.pop_front();

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

// prints all not yet visited vertices reachable from s 
void Graph::DFS(int s)
{
	// Initially mark all verices as not visited 
	vector<bool> visited(V, false);

	// Create a stack for DFS 
	stack<int> stack;

	// Push the current source node. 
	stack.push(s);

	while (!stack.empty())
	{
		s = stack.top();
		stack.pop();

		if (!visited[s])
		{
			cout << s << " ";
			visited[s] = true;
		}

		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
				stack.push(*i);
	}
}