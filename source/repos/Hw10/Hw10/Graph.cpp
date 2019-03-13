#include "Graph.h"
#include <string>
#include <iostream>



using namespace std;

Graph::Graph() {
	vertexList = {};
}

void Graph::addEdge(Vertex v_from, Vertex v_to, int weight) {

	this->edge.v_from = v_from;
	this->edge.v_to = v_to;
	this->edge.weight = weight;
	edges.push_back(this->edge);

	//Checks to see if the vertexList is empty
	//if it's empty the first vertex is pushed
	if (vertexList.empty()) {
		vertexList.push_back(v_from);
	}

	//If the value of v_from is already in the vertex 
	//Check to see if the value of v_to is in there
	//If v_to is not present the value is added to the vertex list
	else if (find(vertexList.begin(), vertexList.end(), v_from) != vertexList.end()) {
		if (find(vertexList.begin(), vertexList.end(), v_to) != vertexList.end()) {
			vertexList.push_back(v_to);
		}
	}
	//If v_from is not in the vertex list it is added to the list
	else {
		vertexList.push_back(v_from); 
	}

}

Graph::EdgeList Graph::outgoing(Vertex v) const {

	EdgeList vecEdges;
	Edge itEdge;

	for (auto it = edges.begin(); it != edges.end(); it++) {
		if (it->v_from == v) {
			itEdge.v_from = it->v_from;
			itEdge.v_to = it->v_to;
			itEdge.weight = it->weight;
			vecEdges.push_back(itEdge);
		}
	}

	return vecEdges;
}

Graph::VertexList Graph::vertices() const {
	return vertexList;
}

