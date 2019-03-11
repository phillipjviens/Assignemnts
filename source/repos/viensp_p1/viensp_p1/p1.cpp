//AUTHOR: Phillip J Viens
//FILENAME: p1.cpp
//DATE: 9/29/2017
//REVISION HISTORY: 2nd Revision
//REFERENCES:

//Description: --Description for p1 class.
//For p1.cpp the user is brought through a series of prompts that tests
//the functionality of the EncryptedWord class. Using a welcome function,
//the programmer is presented with a short description including directions
//of how to execute the functionality of the program. At this point the state
//of the EncryptedWord class is toggled off. All of the statistics variables
//in the EncryptedWord class are set to 0. Next using the enterWord function
//the user is instructed to enter a string to be encrypted. Next the 
//cipherShift function generates an integer to be called by the setCipher 
//function in the EncryptedWord class. Once this process has executed the 
//state of the EncryptedWord class is now on and the guessCipher function
//prompts the user to guess the integer generated in the guessShift function.
//At this point the user is to continue following the onscreen directions
//to enter an integer until the correct guess has been entered. During the on
//state of the EncryptedWord class the tallyStats function is called repeatedly
//keeping track of the continuous statistics of the game. This keeps track the
//number of guesses, the highest guess by the user, the lowest guess by the 
//user, and the average number the user input in integers. Once the correct 
//integer has been guessed. A message congratulating the user on guessing 
//the correct is printed along with the decrypted word. 
//Next the The EncryptedWord function reset is called and the statistics 
//of the users guesses are set to 0 for the future games. The state of the 
//class is now reset and then set to off. The statistics are printed once again
//to test the the reset function. It is the intent to show the functionality
//of the EncryptWord class. In the implemention of the main driver I've clearly
//output the the results of the ceasarShift to allow the programmer to test the 
//functionality of the program. This is for testing purposes. Ive also included 
//two extra objects for use incase there are other files that are need be 
//tested. 
//
//Assumptions: For thesting driver it is assumed that the user will be 
//implementing tests using alphanumeric charachters and other characters.
//The function does not read white space and will cut off before the next
//string is read. The test will run if numbers are entered and 
//will give an output with an alphanumeric ascii value. 
//For guessing the the output of the cipherShift it is assumed that
//only positive integers will be input by the user to guess. The program 
//will run if negative integers are input by the user but the statistics
//will most likely not be correct. If anything besides an integer is put
//in the input value game will have an infinitloop error and will crash.
//This does include floating and double integers. It is also assumed that 
//the user will guess using a integer that is greater than 0. The program
//will run if the integer is zero with no problem however it will skew
//it will not be recorded as the lowest guess if that is infact true. 
//
//Class Invariants:
//Minimal: Stats hold a defualt value of zero. string word allows characters 
//from 0 to size up until the first whitespace. State of the EncryptWord class
//is determined by whether or not a word is currently encrypted. reset is 
//called once cipherShift has been guessed. 
//Problematic: will encrypt numbers and characters to a alphanumeric number.
//Unnecessary: users input on numberOfGuesses is not required. 



#include <iostream>
#include <cstdlib>
#include "EncryptWord.h"
//#include "FindFault.h"
#include <string>

using namespace std;

EncryptWord e;              //object for EncryptedWord class
EncryptWord f;              //2nd object for EncryptWord class
EncryptWord g;              //3rd object for EncryptWord class

int cipher;                 //value generated for user.
int guess;                  //Users input for guess
int numberOfGuesses;        //number of guesses for user.
string play;                //user input for game repeat variable.
string word;                //word entered by user.
char input;                 //input variable for the repeat of game.


//Functional Prototypes

void welcome();
//description: This function displays a short hello message.
//input: No user input.
//processing: cout
//output: Short welcome messaging describing guessing game
//to user.


string enterWord();
//description: This function displays a message telling the user to enter a word
//for the EncryptWord class.
//input: user is asked to input a string consisting of at least 5 characters.
//processing: checks for a string of 5 characters or longs. Has the user try
//again until process does not fail. 
//output: returns the value of the string. cout directions telling user to 
//input a word.

int cipherShift(EncryptWord &);
//description: This function creates a random integer then using arithmetic.
//takes the remainder of the integer divided by 10.
//input: No user input. Input is a pseudo random number generated by c++.
//processing: generates random number for cipher variable
//output: returns a cipher variable for word encryption.

void guessShift();
//description: This function has the user guess the shift value
//This function continues to repeat until the correct integer 
//has been guessed. It is assumed that the user/programmer will enter 
//only whole positive ints. Program will not work characters 
//other than ints are entered. 
//input: positive whole integer to guess the value of the cipherShift.
//processing: processes the users input for cipherShift guess.
//output: outputs directions for the user's guess including an error
//message that is displayed if guess in in accurate. 

void tallyStats(EncryptWord &);
//description: This function increments the number of guesses. Then 
//calling functions setNumberOfGuesses, setHighGuess, setLowGuess, 
//sumOfGuess, and sumAverage in the EncryptedWord.cpp file, it tally's
// the games' statistics. 
//input: No user input.
//processing: increments numberOfGuesses variable and sets all other variables
//output: current guess and numberOfGuesses. No printed output.

void printDecrypt(EncryptWord &);
//description: This function displays a congratulatory message as well as the 
//result of the decrypted word.
//input: No user input.
//processing: decrypted word from EncrytWord.cpp
//output: short congratulatory message along with the decrypted word. 


void printStats(EncryptWord &);
//description: This function displays the games guessing statistics.
//input: No user input
//processing: statistical variables from the EncryptWord.cpp file.
//output: final statistics of the guessing game.

void printState(EncryptWord &);
//description: This function displays the current state of the game.
//On/Off.
//input: No user input. 
//processing: Checks for a true or false flag from the EncryptWord.cpp file.
//output: displays On or Off state of the game. 

void goodbye();
//description: This function displays a short goodbye message.
//input: No user input
//processing: cout
//output: short Goodbye message
 
int main()
{	
	welcome();
	do {
		printState(e);
		numberOfGuesses = 0;
		e.reset();
		enterWord();
		cipherShift(e);
		guessShift();
		printDecrypt(e);
		printState(e);
		printStats(e);
		e.reset();
		printState(e);
		printStats(e);
		cout << endl << "Would you like to play again (y=yes): ";
		cin >> play;
		input = char(int(play[0]));
	} while (input == 'Y' || input == 'y');
	goodbye();
    return 0;
}

void goodbye() {
	cout << endl << "Thanks for playing this super fun little";
	cout << endl << "guess game! Have a great day!";
}

void welcome() {
	cout << endl << "Welcome to my Caesar Cipher!" << endl;
	cout << "In this project you will be given a series of instructions" << endl;
	cout << "First you will enter a word that is at least 5 letters long";
	cout << endl << "Then the word will be shifted a certain number of letters";
	cout << endl << "Forward." << endl;
	cout << "It'll be your job to guess how many letters forward the word has";
	cout << endl << "shifted.";
	cout << endl << "Once you've guessed the correct value for the shift";
	cout << endl << "You've Won!";
	cout << endl << "Feel free to play as many times as you'd like but remember";
	cout << endl << "If you are in a group take turns and have fun!";

}

string enterWord() {
	cout << "Please enter a word that has at least 5 letters." << endl;
	cin >> word;
	if (word.length() < 5) {
		do {
			cout << "Please try again!" << endl;
			cin >> word;
		} while (word.length() < 5);
	}
	return word;
}

int cipherShift(EncryptWord &e) {
	cipher = rand() % 10+1;
	cout << endl << "The word has shiftedby: " << cipher << endl;
	e.encrypt(word, cipher);
	e.decrypt(word);
	e.getState();
	printState(e);
	cout << endl << "Your Word:             " << word << endl;
	cout << "Your Word encrypted:   " << e.getEncrypt() << endl << endl;
	return cipher;
}

void tallyStats(EncryptWord &e) {
	numberOfGuesses++;
	e.setNumberOfGuesses(numberOfGuesses);
	e.setHighGuess(guess);
	e.setLowGuess(guess);
	e.sumOfGuess(guess);
	e.sumAverage();
}

void guessShift() {
	printState(e);
	cout << "The word has now been encrypted using a Caeser Cipher!" << endl;
	cout << "It's your job to guess how many letters it's shifted." << endl;
	cout << endl << "When you're ready guess an integer." << endl << endl;
	printState(e);
	cout << "Enter a guess: ";
	cin >> guess;
	cout << endl;
	tallyStats(e);
	if (guess != cipher) {
		do {
			printState(e);
			cout << "Guess Again: ";
			cin >> guess;
			cout << endl;
			tallyStats(e);
		} while (guess != cipher);
	}
} 

void printStats(EncryptWord &e) {
	cout << "Number of Guesses:   " << e.getNumberOfGuesses() << endl;
	cout << "High Guess:          " << e.getHighGuess() << endl;
	cout << "Low Guess:           " << e.getLowGuess() << endl;
	cout << "Sum Of Guess:        " << e.getSum() << endl;
	cout << "Guess Average:       " << e.getAverage() << endl << endl;
}

void printDecrypt(EncryptWord &e) {
	cout << "Congatulations you guessed it!" << endl;
	cout << endl << "Here is the decrypted word: " << e.getDecrypt() << endl;
	cout << endl;
}

void printState(EncryptWord &e) {
	if (e.getState() == true)
		cout << "Current State: On" << endl;
	else
		cout << "Current State: Off" << endl;
}

