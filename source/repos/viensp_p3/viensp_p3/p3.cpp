//AUTHOR: Phillip Viens
//FILENAME: p3.cpp
//DATE: 10/31/2017
//REVISION HISTORY: 
//REFERENCES:
//
//Description: For p3 class we've utilized both the FindFault and EncryptWord 
//class to test the new function created including the new overloaded operartors
//that allow you to compare two instances of objects and add them both. For the 
//Encrypt wor class we've gone a head created two sets of tests. The first test
//checks to ensure that the == overloaded operator is functioning correctly in
// the EncryptWord class. The second set of tests checks to ensure that the !=
//overloaded operator in the EncryptWord class is functioning correctly. These
//do so by testing whether or no the + overloaded operator is functioning 
//correctly by creating a new cipher shift. Then we run the hard coding both
//different words and multiple objects of different words to check whether or 
//they are recoginzing the difference between words. I decided to do minimal 
//tests on the other functions. I also decided to hard code most of the testing
//design for this class to allow minimal input bye the application tester.
//Next I tested the FindFault class and its new overloaded operators by creating
//test set 3 and 4. Set 3 was desinged to create two different arrays to test the
//and compare them side by side. This will test true if all words in the array are
//of the same size and characters are of the same ASCII value. The second test was
//run to ensure that if any one of the words were different in the array that it 
//that the != overloaded operator would retunr a false reading flag for the isEqual
//boolean. I also decided to test the + overloaded operator which takes both arrays
//from two equally sized objects and combines the to an array double the size. 
//
//Class Invariants: This class will determine the state of Both EncryptWord and FindFault
//class with the instatiation of objects.

#include <iostream>
#include "FindFault.h"

using namespace std;

//instations of EncryptWord class
EncryptWord firstE;
EncryptWord secondE;
EncryptWord thirdE;
EncryptWord fourthE;
EncryptWord fifthE;
EncryptWord sixthE;

//instatiaon of FindFault class
FindFault firstF;
FindFault secondF;
FindFault thirdF;
FindFault fourthF;
FindFault fifthF;
FindFault sixthF;

int cipher1 = 4;
int cipher2 = 4;
int newCipher;
string word;
string word1 = "thanks";
string word2 = "thanks";
string word3 = "welcome";
string word4 = "everyone";


void welcome();
void enterWords();
void enter2ndWords();
void printArray(FindFault &);
void goodbye();

int main() {
	welcome();

	//first set tests
	firstE.setCipher(cipher1);
	secondE.setCipher(cipher2);
	firstE.encrypt(word1, cipher1);
	secondE.encrypt(word2, cipher2);

	cout << "cipher1: " << firstE.getCipher() << endl;
	cout << "word1: " << firstE.getEncrypt() << endl;
	cout << "cipher2: " << secondE.getCipher() << endl;
	cout << "word2: " << secondE.getEncrypt() << endl;

	//adding the first and second objects.
	thirdE = secondE + firstE;
	cout << "New EncryptWord Cipher: " << thirdE.getCipher() << endl;

	if (secondE == firstE)
		cout << "Word 1 and word 2 are equal to each other" << endl;
	if (secondE != firstE)
		cout << "Word 1 and Word 2 are not equal to each other" << endl;

	//second set tests
	fourthE.setCipher(cipher1);
	fifthE.setCipher(cipher2);
	fourthE.encrypt(word3, cipher1);
	fifthE.encrypt(word4, cipher2);

	cout << "cipher1: " << fourthE.getCipher() << endl;
	cout << "word1: " << fourthE.getEncrypt() << endl;
	cout << "cipher2: " << fifthE.getCipher() << endl;
	cout << "word2: " << fifthE.getEncrypt() << endl;

	//adding the first and second objects.
	sixthE = fifthE + fourthE;
	cout << "New EncryptWord Cipher: " << sixthE.getCipher() << endl;

	if (fifthE == fourthE)
		cout << "Word 1 and word 2 are equal to each other" << endl;
	if (fifthE != fourthE)
		cout << "Word 1 and Word 2 are not equal to each other" << endl;
	
	//third set
	enterWords();
	enter2ndWords();
	
	cout << "Here is firstF" << endl;
	printArray(firstF);
	
	cout << "Here is secondF" << endl;
	printArray(secondF);

	thirdF = secondF + firstF;
	cout << endl << "Here is thirdF" << endl;
	cout << endl << endl;

	if (secondF == firstF)
		cout << "Array 1 and 2 are equal to each other" << endl;
	if (secondF != firstF)
		cout << "Array 1 and 2 are not equal to each other" << endl;
	printArray(thirdF);

	//fourth set
	enterWords();
	enterWords();

	cout << "Here is firstF" << endl;
	printArray(fourthF);

	cout << "Here is secondF" << endl;
	printArray(fifthF);

	sixthF = fifthF + fourthF;
	cout << endl << "Here is sixthF" << endl;
	cout << endl << endl;

	if (fifthF == fourthF)
		cout << "Array 1 and 2 are equal to each other" << endl;
	if (fifthF != fourthF)
		cout << "Array 1 and 2 are not equal to each other" << endl;
	printArray(sixthF);


	
	return 0;
}

void welcome() {
	cout << "We will be testing these functions!" << endl;
}

void goodbye() {
	cout << "Goodbye!" << endl;
}


void enterWords() {
	int cipher = 5;
	cout << "Unencrypted Words" << endl;
	word = "Hello";
	cout << word << endl;
	firstF.insert(word, cipher);
	word = "Thanks";
	cout << word << endl;
	firstF.insert(word, cipher);
	word = "Thats";
	cout << word << endl;
	firstF.insert(word, cipher);
	word = "Casper";
	cout << word << endl;
	firstF.insert(word, cipher);
	word = "Jealous";
	cout << word << endl;
	firstF.insert(word, cipher);
	cout << endl;
}

void enter2ndWords() {
	int cipher = 5;
	cout << "Unencrypted Words" << endl;
	word = "Phillip";
	cout << word << endl;
	secondF.insert(word, cipher);
	word = "Jared";
	cout << word << endl;
	secondF.insert(word, cipher);
	word = "Drews";
	cout << word << endl;
	secondF.insert(word, cipher);
	word = "VeeVee";
	cout << word << endl;
	secondF.insert(word, cipher);
	word = "Perry";
	cout << word << endl;
	secondF.insert(word, cipher);
	cout << endl;
}

void printArray(FindFault &object) {
	cout << "Encrypted Array" << endl;
	for ( int i = 0; i < object.getSize(); i++) {
		cout << object.getWord(i) << endl;
	}
}
