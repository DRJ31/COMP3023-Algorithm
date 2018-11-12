#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Vertex
{
public:
	vector<Vertex*> adjList; // Adjacency list
	int inDegree; // Number of previous vertices
	bool color; // true -> white, false -> black
	int id; // ID of the vertex
	
	Vertex(); // Constructor
	~Vertex(); // Destructor
};

// Initialize Vertex
Vertex::Vertex() {
	inDegree = 0;
	color = true;
}

// Destruct Vertex
Vertex::~Vertex() {}

// Initialize color in graph
void initColor(vector<Vertex> *graph) {
	vector<Vertex>::iterator it; // Iterator for graph
	for (it = graph->begin(); it != graph->end(); it++)
		it->color = true;
}

// Read adjacency matrix from sample data
void ReadFile(ifstream *datain, vector<Vertex> *graph) {
	int temp; // Record number in sample data file
	vector<Vertex>::iterator it; // Iterator for graph

	// Initialize information for graph
	for (it = graph->begin(); it != graph->end(); it++) {
		it->id = it - graph->begin();
		for (unsigned int j = 0; j < graph->size(); j++) {
			*datain >> temp;
			if (temp) {
				it->adjList.push_back(&graph->at(j));
				(&graph->at(j))->inDegree++;
			}
		}
	}

	datain->close();
}	

// Depth-First Search Visit
void DFSVisit(vector<Vertex> *graph, Vertex *vertex) {
	vector<Vertex*>::iterator it; // Iterator for adjacency list
	vertex->color = false;

	cout << vertex->id << " ";
	// Check vertices in adjacency list
	for (it = vertex->adjList.begin(); it != vertex->adjList.end(); it++) {
		if ((*it)->color)
			DFSVisit(graph, *it);
	}
}

// Depth First Search
void DFS(vector<Vertex> *graph) {
	vector<Vertex>::iterator it; // Iterator for graph
	initColor(graph);

	cout << "Depth-First Search (starting from vertex 0)" << endl;
	for (it = graph->begin(); it != graph->end(); it++) {
		if (it->color)
			DFSVisit(graph, &(*graph)[it - graph->begin()]);
	}
	cout << endl;
}

// Breath First Search
void BFS(vector<Vertex> *graph) {
	vector<Vertex>::iterator it; // Iterator for graph
	vector<Vertex*>::iterator iter; // Iterator for adjacency list
	initColor(graph);

	cout << "Breath-First Search (starting from vertex 0)" << endl;
	for (it = graph->begin(); it != graph->end(); it++) {
		if (it->color)
			cout << it->id << " ";

		// Check vertices in adjacency list
		for (iter = it->adjList.begin(); iter != it->adjList.end(); iter++) {
			if ((*iter)->color) {
				(*iter)->color = false;
				cout << (*iter)->id << " ";
			}
		}
		it->color = false;
	}
	cout << endl;
}

// Update inDegree of graph after deleted a vertex
void UpdateInDegree(Vertex *vertex, queue<Vertex> *zero) {
	vector<Vertex*>::iterator it; // Iterator for adjacency list

	for (it = vertex->adjList.begin(); it != vertex->adjList.end(); it++) {
		(*it)->inDegree--;
		if ((*it)->inDegree == 0) 
			zero->push(*(*it));
	}
}

// Topological sorting
void TopologicalSorting(vector<Vertex> *graph) {
	vector<Vertex>::iterator it; // Iterator for graph
	queue<Vertex> zero; // Queue to store vertex with 0 indegree
	Vertex vertex; // Current vertex

	// Initialize queue
	for (it = graph->begin(); it != graph->end(); it++) {
		if (it->inDegree == 0) 
			zero.push(*it);
	}
	cout << "Topological sorting of the graph: " << endl;
	while (!zero.empty()) {
		vertex = zero.front();
		UpdateInDegree(&vertex, &zero);
		cout << vertex.id << " ";
		zero.pop();
	}
	cout << endl;
}

int main(void) {
	ifstream datain; // File stream for data file
	string fileName; // File name of data file
	vector<Vertex> graph; // Information of all the vertices
	int length; // Number of vertices

	// Main process
	while (true) {
		// Data process
		cout << "Input the name of the graph file: " << endl;
		cin >> fileName;
		if (cin.eof())
			break;
		datain.open(fileName); 
		datain >> length; 
		graph = vector<Vertex>(length);
		ReadFile(&datain, &graph);

		// Graph algorithms
		DFS(&graph);
		BFS(&graph);
		TopologicalSorting(&graph);

		graph.clear(); // Clean the vector
	}
	vector<Vertex>().swap(graph); // Realease the memory
	return 0;
}