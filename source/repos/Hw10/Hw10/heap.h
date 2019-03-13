#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class heap {
public:
	typedef int Weight;
	typedef string Key;
	//ttypedef vector<Key> HeapArray;
	typedef map<Key, Weight> WeightMap;

	struct KeyWeight {
		Key key;  

		Weight weight;
		KeyWeight() : key(""), weight(0) {}
		KeyWeight(Key k, Weight w) : key(k), weight(w) {}
	};

	heap() {}
	~heap() {}

	/***  Construct a heap from the given initial list,
	* Θ(n) time.
	* @param initial start with these keys 
	* and their weights
	*/
	heap(const map<Key, Weight>& initial);
	bool empty() const;
	void enqueue(Key key, int weight);
	KeyWeight dequeue();




	/***  Get a list of all the key:weight pairs currently in the heap.
	*@return list of key:weight pairs (arbitrary order)*/
	const WeightMap& weightMap() const;

private:
	typedef map<Key, int> PlaceMap;
	vector<Key> heaps;
	map<Key, Weight> weights;
	PlaceMap place;

	int last() const;
	int parent(int i) const;
	int leftChild(int p) const;
	int rightChild(int p) const;
	Weight weight(int i) const;
	
	void swapUp(int i);
	
	void swapDown(int p);
	
	void heapConstruct();

};

