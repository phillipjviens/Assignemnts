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
		//cout << "Testing constructor" << endl;
		for (auto kvp : initial) {
			this->heaps.push_back(kvp.first);
			//cout << kvp.first << " : " << kvp.second <<  endl;
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
	int l = last();
	Key key = "";
	int w = 0;
	//cout << "L is: " << l << endl;
	if (l < 0) {
		return KeyWeight(key, w);
	}
	//cout << "this got executed1" << endl;
	key = heaps[0];
	//cout << "this got executed2" << endl;
	w = weights.find(key)->second;
	//cout << "this got executed3" << endl;
	weights.erase(key);
	//cout << "this got executed4" << endl;
	place.erase(key);
	//cout << "this got executed5" << endl;

	if (l > 0){
		//cout << "this got executed6" << endl;
		heaps[0] = heaps[last()];
		//cout << "this got executed7" << endl;
		heaps.pop_back();
		//cout << "this got executed8" << endl;
		//cout << "Place[heaps[0]]= " << place[heaps[0]] << endl;
		place[heaps[0]] = 0;
		//cout << "this got executed9" << endl;
		//cout << "Getting to swap Down" << endl;
		swapDown(0);
		//cout << "Made it past swap down" << endl;

	}
	else {
		heaps.erase(heaps.begin());
		return KeyWeight(key, w);
	}
	return KeyWeight(key, w);
}

heap::Weight heap::weight(int i) const {
	if (i > last()) {
		return 0;
	}
		string p = heaps[i];
		return weights.at(p);
}

//returns the parent of the given index
int heap::parent(int i) const {
	return (i - 1) / 2;
}


//returns the left child of the given index
int heap::leftChild(int p) const {
	return (2 * p) + 1;
}

//returns the right child of the given index
int heap::rightChild(int p) const {
	return leftChild(p) + 1;
}


int heap::last() const {

	return heaps.size()-1;
}

void heap::swapUp(int i) {
	if (i > 0) {
		int p = parent(i);
		if (weight(i) < weight(p)) {
			swap(heaps[i], heaps[p]);
			place[heaps[i]] = i;
			place[heaps[p]] = p;
			swapUp(p);
		}
	}
}

void heap::swapDown(int p) {

	int left = leftChild(p);
	int right = rightChild(p);
	int smallest = p;

	if (left < weights.size() && weight(right) < weight(p)) {
		smallest = left;
	}
	if (right < weights.size() && weight(right) < weight(smallest)) {
		smallest = right;
	}
	if (smallest != p) {
		swap(heaps[p], heaps[smallest]);
		swapDown(smallest);
	}
	/*
	int child = leftChild(p);
	cout << "child " << child << endl;
	int right = rightChild(p);
	cout << "right " << right << endl;
	int child_w = weight(child);
	if (child_w == NULL) {

	}
	else {
		int riW = weight(right);
		if (riW != NULL && riW < child_w) {
			child = right;
			child_w = riW;
			if (weight(p) > child_w) {
				swap(heaps[child], heaps[p]);
				place[heaps[child]] = child;
				place[heaps[p]] = p;
				swapDown(child);
			}
		}
	}
	*/
	/*
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
	*/
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