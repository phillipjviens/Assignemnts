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
	Graph g;
	typedef Graph::Edge e;
	typedef map <string, int> Edges;
	typedef map <string, string> Path;
	typedef map <string, int> KeyWeight;
	typedef map <KeyWeight, Path> returnPair;
	typedef vector <KeyWeight, Path> returnpair;
	int inf = numeric_limits<int>::infinity();
	returnPair returns;
	dijkstra() {};

	struct data {
		KeyWeight d;
		Path p;
	};

	data results;
	
	const data dijkstraAlg(Graph& g, string start);



	~dijkstra() {};

private: 
	int new_path_to_k;
	vector <e> shortestEdges;

	Path path;
	Path paths;
	KeyWeight shortest;
	vector <string> this_path;
	//map <KeyWeight, Path> returns;
	vector <string> found;
	map <string, int> weightMap;
	vector <string> vert;
	string vertex;
	map <string, int> unsolved; 
	string closest;
	int distance;


	string start;
};

