#include "dijkstra.h"
#include "heap.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


 const dijkstra::data  dijkstra::dijkstraAlg(Graph& g, string start) {
	
	this->g = g;
	this->start = start;

	//n is |V|, number of vertices in the graph
	int n = size(g.vertices());
	vert = g.vertices();
	found = {};
	shortest = {};
	path = {};
	for (auto itr = vert.begin(); itr != vert.end(); itr++) {
		path[*itr] = " ";
		shortest[*itr] = inf;
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
			string k = it->v_to;
			if (find(found.begin(), found.end(), k) != found.end()) {

			}
			else {
				new_path_to_k = shortest[closest] + it->weight;

				// fix weight in priority queue
				if (new_path_to_k < weightMap[k]) {
					unsolved.enqueue(k, new_path_to_k);
					shortest[k] = new_path_to_k;
					path[k] = closest;
				}
			}

	// report results (not officially part of Dijkstra's--we wouldn't 
	//count this in time analysis)
	paths = {};
	string w;
	string pathw;
	for (auto it = vert.begin(); it != vert.begin(); it++) {
		if (*it != start) {
			this_path = {};
			w = *it;
			while (w != start) {
				this_path.push_back(w);
				w = path[w];
				pathw = pathw + w;
			}
			this_path.push_back(start);
			reverse(this_path.begin(), this_path.end());
			paths[*it] = " " + pathw;
		}
	}
	results.d = shortest;
	results.p = paths;

//	returns.insert(pair<KeyWeight, Path> (shortest, paths));

			shortest.erase(start);
			return results;
			}
		}

	}
