//AUTHOR: Phillip Viens
//FILENAME: EncryptWord.h
//DATE: 9/29/2017
//REVISION HISTORY: 2nd Revision 
//REFERENCES:
//
//Description: For the find fault class I've created a program that calls a 
//series of encapsulated strings from the EncryptWord class. Using the driver
//file p2.cpp, A sentence is taken in placed into several indexes within an
//array. Each one of these strings are passed through the encrypt function
//within the EncryptedWord class called within the faultify function in 
//the FindFault class. The state of this class is considered to be off 
//until the first word the first word is taken in to the array initialized
//in the faultify array. Once the words are placed into an array an 
//encryptify array in the driver file. The array will then be passed through
//to the FindFault class. Inside the FindFault class a random number generator
//a 1 or a 0 which will activate a boolean function that states whether or 
//not each index is then corrupted. Once the words have been corrupted 
//using the driver file a user will have the ability
//to query whether or not a word is corrupt. Using the faultify array and
//the encryptify array. The strings in the sentence will be compared to 
//to the original encrypted word for differences in the encryptify word
//to faultify word. While the user guesses whether or not a word is 
//encrypted, both rightGuesses and wrongGuesses variables will increment
//keeping track of the total number of guesses. Then using the 
//guessPercent function 

#pragma
#include <iostream>
#include "EncryptWord.h"

class FindFault
{
public:
	FindFault(int);
	~FindFault();
	bool insert(string);

	string faultWord;

	//accessors
	string getWord(int) const;
	int getSize() const;
	int getCapacity() const;
	int rightGuess;
	int wrongGuess;

private:
	int size;
	int capacity;
	string * faultify;

	// suppress copying
	FindFault(const FindFault &);   //copy constructor
	FindFault& operator=(const FindFault &);   //overloaded = operator
	
};

