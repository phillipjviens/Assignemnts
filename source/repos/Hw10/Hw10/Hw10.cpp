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
	map<string, int> examps;
	examps["a"] = 1;
	examps["b"] = 5;
	examps["c"] = 3;

	heap heap1(examps);

    return 0;
}

