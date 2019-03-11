#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;
class Graph
{
public:
	typedef string Vertex;
	
	struct Edge {
		Vertex v_from, v_to;
		int weight;
		Edge(Vertex v_from, Vertex v_to, int w) : v_from(v_from).v_to(v_to), weight(w) {}
	};
	typedef vector<Vertex> VertexList;
	typedef vector<Edge> EdgeList;

	void addEdge(Vertex v_from, Vertex v_to, int weight = 1);
	EdgeList outgoing(Vertex v) const;
	VertexList vertices() const;


	//Graph();
	//~Graph();
private:
	VertexList vertexList;
	map<Vertex, EdgeList> edgeList;
};

