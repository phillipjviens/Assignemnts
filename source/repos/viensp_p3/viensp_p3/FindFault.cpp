//AUTHOR: Phillip Viens
//FILENAME: EncryptWord.cpp
//DATE: 10/31/2017
//REVISION HISTORY: 3rd revision
//REFERENCES:EncryptWord.h
//
////Implementation Invariants: 
//Minimal: default for accessors generally is a value of 0.
//Problematic: getDecrypt will not print if there is no word that is encrypted.
//Unnecessary: non destructive is implied by constants. 
// Description for the FindFault class is in the .h file.

#include <iostream>
#include "FindFault.h"

//constructor
FindFault::FindFault()
{
	size = 0;
	capacity = 5;
	rightGuess = 0;
	wrongGuess = 0;
	faultify = new string[capacity];
}

//Destructor
FindFault::~FindFault()
{
	delete[] faultify;
	faultify = NULL;
}

//copy constructor
FindFault::FindFault(const FindFault &obj) {
	size = obj.size;
	capacity = obj.capacity;
	rightGuess = obj.rightGuess;
	wrongGuess = obj.wrongGuess;
	
	faultify = new string[capacity];

	for ( int i = 0; i < size; i++)
		faultify[i] = obj.faultify[i];
}

FindFault& FindFault::operator=(const FindFault &obj) {
	if (this != &obj) {
		size = obj.size;
		capacity = obj.capacity;
		rightGuess = obj.rightGuess;
		wrongGuess = obj.wrongGuess;

		faultify = new string[capacity];

		for ( int i = 0; i < size; i++)
			faultify[i] = obj.faultify[i];
	}

	return *this;
}

FindFault FindFault::operator+(const FindFault &obj) {
	FindFault newArray;

	newArray.resize();
	
	for (int i = 0; i < this->size; i++) {
		newArray.faultify[newArray.size] = this->faultify[i];
		newArray.size++;
	}

	for (int i = 0; i < obj.size; i++) {
		newArray.faultify[newArray.size] = obj.faultify[i];
		newArray.size++;
	}
	
	return newArray;
}

bool FindFault::operator==(const FindFault &obj) {
	for ( int i = 0; i < this->size; i++) {
		if (this->faultify[i] != obj.faultify[i])
			return false;
	}
	return true;
}

bool FindFault::operator!=(const FindFault &obj) {
	for ( int i = 0; i < this->size; i++) {
		if (this->faultify[i] != obj.faultify[i])
			return true;
	}
	return false;
}

void FindFault::resize() {
	//update capacity.
	capacity *= 2;

	//create new affar based on updated capacity
	string * tempArr = new string[capacity];
	
	//copy old array values to new array
	for (int i = 0; i < size; i++)
		tempArr[i] = faultify[i];

	// delete old array
	delete[] faultify;

	//reassing old array to new array.
	faultify = tempArr;
}

bool FindFault::insert(string faultWord, int cipher) {
	isOn = false;
	if (size >= capacity)
		return false;
	e.encrypt(faultWord, cipher);
	faultify[size] = e.getEncrypt();
	corrupt(size, e.getEncrypt());
	size++;
	return true;
	if (size >= capacity)
		return false;
	faultify[size] = e.getEncrypt();
	if (size >= capacity)
		return false;

	faultify[size] = e.getEncrypt();
	corrupt(size, faultify[size]);
	size++;
	return false;
}

string FindFault::getWord(int index) const {
	return faultify[index];
}

int FindFault::getSize() const {
	return this->size;
}

int FindFault::getCapacity() const {
	return capacity;
}

bool FindFault::corrupt(int index, string result) {
	isOn = true;
	corruptWord = "";
	if (index == 0 || index == 3) {
		for (unsigned int i = 0; i < result.length(); i++) {
			if (isupper(result[i]))
				corruptWord += "#";
			else
				corruptWord += "#";
		}
		faultify[index] = corruptWord;
		return true;
	}
	faultify[index] = result;
	return false;
}

void FindFault::setStats(bool guess) {
	if (guess == true) {
		rightGuess++;
	}
	else
		wrongGuess++;
}

int FindFault::getRightGuess() const {
	return rightGuess;
}

int FindFault::getWrongGuess() const {
	return wrongGuess;
}

void FindFault::reset() {
	isOn = false;
	rightGuess = 0;
	wrongGuess = 0;
}

bool FindFault::getState() {
	return isOn;
}
