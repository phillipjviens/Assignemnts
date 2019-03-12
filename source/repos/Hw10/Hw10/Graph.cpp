#include "Graph.h"
#include <string>
#include <iostream>



using namespace std;

Graph::Graph() {
	vertexList = {};
}

void Graph::addEdge(Vertex v_from, Vertex v_to, int weight) {
	cout << "v_from " << v_from << endl;
	cout << "v_to " << v_to << endl;
	cout << "weight " << weight << endl;
	if (vertexList.empty()) {
		vertexList.push_back(v_from);
	}
	else if (find(vertexList.begin(), vertexList.end(), v_from) != vertexList.end()) {
		if (find(vertexList.begin(), vertexList.end(), v_to) != vertexList.end()) {
			vertexList.push_back(v_to);
		}
	}
	else
		vertexList.push_back(v_from);

	this->edge.v_from = v_from;
	this->edge.v_to = v_to;
	this->edge.weight = weight;
	edges.push_back(edge);

}

Graph::EdgeList Graph::outgoing(Vertex v) const {

	return edges;
}

Graph::VertexList Graph::vertices() const {
	return vertexList;
}

