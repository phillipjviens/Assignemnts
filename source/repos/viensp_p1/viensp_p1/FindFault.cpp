#include "FindFault.h"
//#include "EncryptWord.h"

//ctor
FindFault::FindFault(int cap)
{
	size = 10;
	capacity = cap;
	rightGuess = 0;
	wrongGuess = 0;
	faultify = new string[capacity];
}



//Destructor
FindFault::~FindFault()
{
	delete []  faultify;
}

//
//
//
bool FindFault::insert(string faultWord) {
	if (size >= capacity)
		return false;

	faultify[size] = faultWord;
	return false;

}

//description:
//preconditions:
//postcondtions:
string FindFault::getWord(int index) const {
	return faultify[index];
} 

//description:
//preconditions:
//postcondtions:
int FindFault::getSize() const{
	return sizeof(faultify);
}

//description:
//preconditions:
//postcondtions:

int FindFault::getCapacity() const {
	return size;
}