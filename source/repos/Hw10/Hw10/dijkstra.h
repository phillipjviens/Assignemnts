#pragma once
#include "Graph.h"
#include <vector>
#include <map>
#include <string>
#include "heap.h"
#include <limits>

using namespace std;

class dijkstra
{
public:
	int inf = numeric_limits<int>::infinity();
	dijkstra() {};
	dijkstra(Graph& g, string start);



	~dijkstra() {};

private: 
	Graph g;
	typedef Graph::Edge e;
	typedef map <string, int> Edges;
	int new_path_to_k;
	vector <e> shortestEdges;
	vector <string> path;
	vector <string> found;
	map <string, int> weightMap;
	map <string, int> shortest;
	vector <string> vert;
	string vertex;
	map <string, int> unsolved; 
	string closest;
	int distance;


	string start;
};

