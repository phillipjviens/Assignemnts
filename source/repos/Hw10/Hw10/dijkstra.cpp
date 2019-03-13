#include "dijkstra.h"
#include "heap.h"
#include <iostream>
//#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <map>




dijkstra::dijkstra(Graph& g, string start) {
	
	this->g = g;
	this->start = start;
	
	
	int n = size(g.vertices());
	vert = g.vertices();
	found = {};
	shortest = {};
	path = {};
	for (int i= 0; i < n; i++) {
		path.push_back("None");
	}
	for (auto it = g.vertices().begin(); it != g.vertices().at(closest); it++) {
		vertex = *it;
		shortest.insert(pair<string, int> (vertex, inf));
	}
	shortest.begin()->second = 0;
	heap unsolved(shortest);
	weightMap = unsolved.weightMap();

	//get the shortest path to every other vertex
	while (size(found) < n) {

		//find closest unsolved vertex
		closest = unsolved.dequeue().key;
		distance = unsolved.dequeue().weight;

		//closest vertex is now solved, we know that no other
		//shorter path exists
		found.push_back(closest);

		//update paths to other vertices via closest
		shortestEdges = g.outgoing(closest);
		
		for (auto it = shortestEdges.begin(); it != shortestEdges.end(); it++) {
			Graph::Edge k = *it;
			if (find(shortestEdges.begin(), shortestEdges.end(), k) != shortestEdges.end()) {

			}
			else {
				new_path_to_k = shortest[closest] + it->weight;
				if (new_path_to_k < ) {
					unsolved.enqueue(k, new_path_to_k);

				}

			}
		}

	}

	}

