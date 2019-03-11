#include "heap.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


heap::heap(const map<Key, Weight>& initial) {
	this->weights = {};
	this->place = {};
	this->heaps = {};

	if (!(initial.empty())) {
		int last = 0;
		cout << "Testing constructor" << endl;
		for (auto kvp : initial) {
			this->heaps.push_back(kvp.first);
			cout << kvp.first << " : " << kvp.second <<  endl;
			this->weights.insert(kvp);
			this->place.insert(pair<Key, Weight>(kvp.first, last));
			last++;

			heapConstruct();

		}
	}
}

void heap::heapConstruct() {

	int last_parent = parent(last());

	for (int i = last_parent; i > -1; i--) {
		swapDown(i);
	}
}

const heap::WeightMap &heap:: weightMap() const {

	return weights;
}

bool heap::empty() const{
	return last()==0;
}

void heap::enqueue(Key key, int weight) {

	map<Key, int>::iterator p;
	int i;
	int old_w;
	map<Key, int> second;
	if (weights.count(key)) {
		p = weights.find(key);
		old_w = p->second;
		i = place[key];
	}
	else {
		heaps.push_back(key);

		old_w = NULL;
		i = last();
		place[key] = i;
	}
	weights[key] = weight;
	if (old_w == NULL || old_w > weight) {
		swapUp(i);
	}
	else if (old_w < weight) {

		swapDown(i);
	}
}

heap::KeyWeight heap::dequeue() {
	map<Key, int>::iterator p;
	int l = heaps.size()-1;
	Key key;
	Weight weigth;
	cout << "L is: " << l << endl;
	if (l <= 0) {
		return KeyWeight(weights.begin()->first, weights.begin()->second);
	}

	key = heaps[0];
	
	weights.erase(key);

	place.erase(key);

	if (l > 0){
		heaps[0] = heaps.back();
		heaps.pop_back();
		place[heaps[0]] = 0;

	}
	else {

		heaps.erase(heaps.begin());

	}
	return KeyWeight(weights.begin()->first, weights.begin()->second);
}

heap::Weight heap::weight(int i) const {
	if (i > last())
		return 0;
	string p = heaps[i];
	return weights.at(p);
}

//returns the parent of the given index
int heap::parent(int i) const {
	return (i - 1) >> 1;
}


//returns the left child of the given index
int heap::leftChild(int p) const {
	return (2 * p);
}

//returns the right child of the given index
int heap::rightChild(int p) const {
	return (2 * p) + 1;
}


int heap::last() const {
	return heaps.size()-1;
}

void heap::swapUp(int i) {
	if (i > 0) {
		int p = parent(i);
		if (weight(i)< weight(p)) {
			swap(heaps[i], heaps[p]);
			place[heaps[i]] = i;
			place[heaps[p]] = p;
			swapUp(p);
		}
	}
}

void heap::swapDown(int p) {

	int leChi = leftChild(p);
	int riChi = rightChild(p);
	int largest = p;
	int riChiW = weight(riChi);
	int leChiW = weight(leChi);

	if (leChi < last() && weight(leChi) > weight(p)) {
		largest = leChi;
	}
	if (riChi < last() && weight(riChi) > weight(p)) {
		largest = riChi;
	}

	if (largest != p) {
		swap(heaps[p], heaps[largest]);

		place[heaps[largest]] = largest;
		place[heaps[p]] = p;
		swapDown(largest);
	}
	/*
	riChiW = weight(riChi);
	if (riChiW != 0 && riChiW < leChiW) {
		leChi = riChi;
		leChiW = riChiW;
		if (weight(p) > riChiW) {
			swap(heaps[p], heaps[riChiW]);
			place[heaps[riChi]] = riChi;
			place[heaps[p]] = p;
			swapDown(leChi);
		}
	
	}
	*/
}