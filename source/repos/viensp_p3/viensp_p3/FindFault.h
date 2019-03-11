//AUTHOR: Phillip Viens
//FILENAME: EncryptWord.h
//DATE: 10/31/2017
//REVISION HISTORY: 
//REFERENCES:
//
//Description: For the find fault class I've created a program that calls a 
//series of encapsulated strings from the EncryptWord class. Using the driver
//file p2.cpp, A variety of unEncrypted words placed into several indecies of
//an array. Using the insert function  Each one of these strings are passed 
//through the encrypt function within the EncryptedWord class called 
//within the insert function in the FindFault class. The state of this class 
//is considered to be off until the first word the first word is called by 
//the corrupt function in the faultify array. Once the words are encrypted 
//the state remains on until the user has found all the faulted strings and 
//the program resets. Inside the FineFault class I've created a function 
//called corrupt which sets indexes 0 and 3 to corrupt the strings in the 
//array. I was going to have the function generate a random digit but for 
//the sense of testing and expediency for application programmer I've decided 
//a fixed corruption would be more ideal. Once the words have been corrupted 
//using the driver file a user will have the ability to query whether or not 
//a word is corrupt. Once the words have been encrypted, corrupted and placed.
//The user using the driver file will then be asked if each encrypted word is 
//corrupt. During this time all rightGuesses and WrongGuesses will be 
//incremented in the setStats keeping track of the total number of right and 
//wrong guesses.
//
//Dependencies: In order for this class to function it needs to used with the
//EncryptWord class. In oder to corrupt words and place them into the array
// the words are encrypted using the encrypt function in the EncryptWord class
//and then called back into the array. With out this class the program will not
//compile as it will be missing key functionality.
//
//Assumptions: For this class it is assumed that the programmer or user will be
//entering strings containing only alpha numeric characters. The driver
//file has already preselected 5 words to be put inside the array so the user
//really shouldn't have any input at that point. 
//No other words will be accepted. As it currently stands the array is set
//with a capacity of 5. If this the user or application progammer wants to
//have larger arrays the capacity will need to be changed in order to 
//accomidate a larger array. I decided since this was testing the function
//of creating an array and encapsulating objects fron another class it would
//more efficient to not worry about dynamically implementing an array.
//The current program will cut off at any white space
//entered for string word and move on to entering the next string
// int to the specified array This will continue to do so until the 
//array has reached its capacity or there are no other strings left to read
//whichever come first. It will also cause an infinite loop any time non
//int values are entered while guessing. 
//If the guess is incorrect it is assumed that the user will continue to play 
//the game until the correct value is entered. We've now added three new functions
//We've added the overloaded +,==,!=,. The + overlaoded operator allows us to take
//two seperate objects of arrays of equal lengths and add them together into a new
//resized array object. The == & != fucntions go through the entirety of both 
//arrays checking to ensure that they either are or are not equal.
//
//Interface invariants: 
//Minimal: Cannot use getters when variables in setters have not
//been implemented. Cannot encrypt the word until word and cipher have been 
// given. Cannot get a decrypt word when no word has been added. It is important
//for the user of this program that application programmer only uses two arrays of
//equal length to ensure that the objects don't go over the arrays size causing
//a failed program.
//
//Class Invariants: In order for this class to work you the state of EncryptWord
//needs to be on. In order to do this FindFault needs to take in a word from the
//driver class and then send it to the EncryptWord class to be encrypted and then
//brought back inorder to be corrupted.

//class invarients

#include <iostream>
#include "EncryptWord.h"
class FindFault
{
public:
	EncryptWord e;
	int rightGuess;
	int wrongGuess;
	int index;
	string faultWord;
	string corruptWord;
	bool isCorrupt;
	bool isOn;

	
	FindFault();                               //constructor
	~FindFault();                              //destructor
	FindFault(const FindFault &);              //copy constructor
	FindFault& operator=(const FindFault &);   //overloaded = operator
	FindFault operator+ (const FindFault &);   //overloaded + operator
	bool operator== (const FindFault &);       //overloaded == operator
	bool operator !=(const FindFault &);       //overloaded != operator
	
	void resize();
	//description: Resizes the capacity of the array and the copies the
	//contents over into a new array while deleting the old one.
	//preconditions: a capacity needs to be esablished as the array
	//will double in size from it previous capacity.
	//postconditions: Will double the size of the array. 

	bool insert(string, int);
	//description: checks to ensure that the array is not filled. Then takes
	//result variable from encrypted words and inserts words into array. Then 
	//using the corrupt function corrupts the corresponding words.
	//precondition: Array needs to be either empty or not full. State is 
	//considered Off
	//postcondition: State is now on once the array has been filled with 
	//encrypted words. 


	//accessors
	string getWord(int) const;
	//description: returns the string in specified index
	//preconditions: None
	//postcondtions: returns the word while remaining in an on state

	int getSize() const;
	//description: returns the current size of the array
	//preconditions: None
	//postcondtions: returns the size of the array doesn't affect state.

	int getCapacity() const;
	//description: returns the capacity of the array
	//preconditions: An array needs to be initialized
	//postcondtions: returns the capacity Doesn't change the state

	void setStats(bool guess);
	//description: This function checks to see whether or not the guess the user
	// places is correct or not. If it is correct then the rightGuess variable
	//is incremented. If it's incorrect the wrongGuess variable is incremented. 
	//preconditions: None. State of the program is set to On.
	//postconditions: the stats are updated. The state of the program remains On.

	int getRightGuess() const;
	//description: This function returns the total number of times the user
	//guessed right.
	//preconditions: None.
	//postconditions: state is Off

	int getWrongGuess() const;
	//description: This function returns the total number of times the user
	//guessed wrong.
	//preconditions: None.
	//postconditions: state is Off

	void reset();
	//description: the reset function sets all of the currenct statistics to 0.
	//preconditions: None will work whether or not there are current set values.
	//postcondtions: all of the current states of variable statistics will return
	//as 0. Sets the isOn flag to false, stating that game is no longer in the on 
	//state.

	bool getState();
	//description: returns the current state of the game. 
	//preconditions: Flag is initialized to off.
	//postcondtions: Flag changes to On when flagged to do so by encrypt function. 


private:
	int size;           //size variable that keeps track of the elements in array
	int capacity;       //max capacity set for the array.
	string * faultify;  //instantiates the faultify string array.

	bool corrupt(int index, string result);
	//description: checks the index of the current array and 
	//preconditions: Array needs to be not full State is On.
	//postconditions: corrupts every 3 word. State is still On.



};


