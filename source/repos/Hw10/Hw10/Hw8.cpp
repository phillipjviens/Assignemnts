// Hw10.cpp : Defines the entry point for the console application.
//

#include "heap.h"
#include "Graph.h"
#include "dijkstra.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>




int main()
{

	heap::KeyWeight kw;
	heap::WeightMap wm;
	Graph g;
	dijkstra d;
	typedef map <string, string> Path;
	typedef map <string, int> KeyWeight;
	typedef map<KeyWeight, Path> returns;
	KeyWeight sortedPairs;
	Path paths;
	
	dijkstra::data results;

	g.addEdge("a", "b", 12);
	g.addEdge("a", "c", 13);
	g.addEdge("b", "a", 12);
	g.addEdge("c", "a", 12);

	
	vector<string> vertices = g.vertices();
	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		string vertex = *it;
		cout << endl << "Vertex: " << vertex << endl;

		vector<Graph::Edge> edges = g.outgoing(vertex);
		for (auto it = edges.begin(); it != edges.end(); it++) {
			cout << "\t" << it->v_from << "->" << it->v_to << "(" << it->weight << ")" << endl;
		}
	}

	 results.d= d.dijkstraAlg(g, "a").d;

	 results.p = d.dijkstraAlg(g, "a").p;
	 
	 
	 sortedPairs = results.d;
	 paths = results.p;

	 cout << "{ ";
	 for (auto kvp : sortedPairs) {
		 cout << " '" << kvp.first << "':  '" << kvp.second;
	 }
	 cout << "} " << endl;
	 cout << "{ ";
	 for (auto kvp : paths) {
		 cout << " '" << kvp.first << "' :  '" << kvp.second;
	 }
	 cout << "} " << endl;


	//map<string, int> examps;

	//wm["a"] = 1;
	//wm["b"] = 10;
	//wm["c"] = -3;

	//cout << "we got here" << endl;
	//heap h(wm);

	//cout << h.empty() << " expect 0" << endl;
	//h.enqueue("a", 1);
	//h.enqueue("b", 10);
	//h.enqueue("c", -3);
	//h.enqueue("d", 45);
	//cout << "h.enqueued" << endl;
	//kw = h.dequeue();
	//cout << kw.key << " " << kw.weight << " expect c -3" << endl;
	//kw = h.dequeue();
	//cout << kw.key << " " << kw.weight << " expect a 1" << endl;
	//kw = h.dequeue();
	//cout << kw.key << " " << kw.weight << " expect b 10" << endl;
	//cout << h.empty() << " expect 1" << endl;

    return 0;
}

