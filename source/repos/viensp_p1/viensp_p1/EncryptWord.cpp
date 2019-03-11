//AUTHOR: Phillip Viens
//FILENAME: EncryptWord.cpp
//DATE: 9/29/2017
//REVISION HISTORY: 2nd revision
//REFERENCES:EncryptWord.h
//
//Description: -- Description for EncryptWord class is located in the .h file.
//
//Implementation Invariants: 
//Minimal: default for accessors generally is a value of 0.
//Problematic: getDecrypt will not print if there is no word that is encrypted.
//Unnecessary: non destructive is implied by constants. 


#include <iostream>
#include "EncryptWord.h"

using namespace std;


int EncryptWord::getCipher() const {
	return cipher;
}


void EncryptWord::setCipher(int cipher) {
	this->cipher = cipher;
}

int EncryptWord::getNumberOfGuesses() const {
	return numberOfGuesses;
}

void EncryptWord::setNumberOfGuesses(int numberOfGuesses) {
	this -> numberOfGuesses = numberOfGuesses;
}

int EncryptWord::getHighGuess() const {
	return highGuess;
}

void EncryptWord::setHighGuess(int guess) {
	if (guess > highGuess)
		highGuess = guess;
}

int EncryptWord::getLowGuess() const {
	return lowGuess;
}


void EncryptWord::setLowGuess(int guess) {
	if (lowGuess == 0)
		lowGuess = guess;
	if (guess < lowGuess)
		lowGuess = guess;
}

int EncryptWord::getSum() const {
	return sum;
}

void EncryptWord::sumOfGuess(int guess) {
	sum += guess;
}

void EncryptWord::sumAverage() {
	average = sum / numberOfGuesses;
}

int EncryptWord::getAverage() const {
	return average;
}

void EncryptWord::reset() {
	sum = 0;
	lowGuess = 0;
	highGuess = 0;
	average = 0;
	numberOfGuesses = 0;
	isOn = false;
	
}

void EncryptWord::encrypt(string word, int cipher) {
	result = "";
	isOn = true;

	for (int i = 0; i < word.length(); i++) {
		if (isupper(word[i]))
			result += char(int(word[i] + cipher - ASCIICAP) % 
				ALPHABETNUM + ASCIICAP);
		else
			result += char(int(word[i] + cipher - ASCII) % ALPHABETNUM 
				+ ASCII);
	}
}

string EncryptWord::getEncrypt() const {
	return result;
}

void EncryptWord::decrypt(string word) {
	decryptedWord = word;
}

string EncryptWord::getDecrypt() const {
	return decryptedWord;
}

bool EncryptWord::getState() {
	return isOn;
}
