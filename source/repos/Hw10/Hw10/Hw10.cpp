// Hw10.cpp : Defines the entry point for the console application.
//

#include "heap.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>




int main()
{

	heap::KeyWeight kw;
	heap::WeightMap wm;

	//map<string, int> examps;
	wm["a"] = 1;
	wm["b"] = 10;
	wm["c"] = -3;

	cout << "we got here" << endl;
	heap h(wm);

	cout << h.empty() << " expect 0" << endl;
	h.enqueue("a", 1);
	//h.enqueue("b", 10);
	//h.enqueue("c", -3);
	//kw = h.dequeue();
	cout << kw.key << " " << kw.weight << " expect c -3" << endl;
	//kw = h.dequeue();
	cout << kw.key << " " << kw.weight << " expect a 1" << endl;
	//kw = h.dequeue();
	cout << kw.key << " " << kw.weight << " expect b 10" << endl;
	cout << h.empty() << " expect 1" << endl;

    return 0;
}

