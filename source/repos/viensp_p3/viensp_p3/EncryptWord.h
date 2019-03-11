//AUTHOR: Phillip Viens
//FILENAME: EncryptWord.h
//DATE: 10/31/2017
//REVISION HISTORY: 2nd Revision 
//REFERENCES:
//
//Description: -- Description for EncryptWord class
//For this class values entered by the programmer in the main
//will be used to create a caesar cipher. This program has three states.
//The first state "off" is assumed when no entered values exist in the
//EncryptedWord class doesn't have a ceasarShift value. While the
//EncryptedClass is in it's "off" state there are no strings to be ciphered.
//Using the random int generated in the cipherShift function from main, the
//class switches to an "on" state. In this state the encrypt function takes
//takes the word entered by the user and checks for both lower and upper case
//letters. Adding the value given by the cipherShift function to characters
//ASCII value, the word is then shifted to reveal the scrambled version of the
//given word. The user is then prompted in the main class to guess the value of
//the cipherShift. It is with intent for the EncryptWord class to determine the
//state of the game. When the stats have been reset a flag is placed and the 
//game switches to an "off" state. Currently the program stays in "on"
//until the user has guessed the correct value of the cipherShift. Currently a
//Pseudo random integer is being generated so for testing purposes I've printed
//the value of the random int generated to expedite the process of testing.
//While the user guesses the cipherShift the numberOfGuesses is incremented.
//The value of the users guess is is also recorded and using the highGuess
//function checks to see if it is the highest guess. Using lowGuess function
//the class checks to see if the value is 0 or lower than the previous guess.
//In the sumOfGuess function the sum of all guesses is recorded.
//In the sumAverage function the value of sum is divided by numberOfGuesses to
//calculate the average of the sumOfGuesses. We've now added three new funcitons
//overloaded operators +, ==, !=. + adds the two cipher shift values of different 
//objects and then re instantiates that value in a new object.
//
//Assumptions: For this class it is assumed that the programmer or user will be
//entering strings containing only alpha numeric characters and no white spaces.
//It is also assumed that the values entered for the guesses will be whole
//positive ints. The current program will cut off at any white space
//entered for string word. It will also cause an infinite loop any time non
//int values are entered while guessing. 
//If the guess is incorrect it is assumed that the user will continue to play 
//the game until the correct value is entered.
//
//Interface invariants: 
//Minimal: Cannot use getters when variables in setters have not
//been implemented. Cannot encrypt the word until word and cipher have been 
// given. Cannot get a decrypt word when no word has been added. 
//
//Problematic: If getters are called when no data or variables have been
//established the statistics including number of guesses, highGuess, lowGuess
//sum, average, cipher will all default to 0. In addition the getDecrypt 
//function will return a blank space. 
//
//Unceccessary: all necessary items are passed. 
//
//Class invarients: This class stands alone and does not depend on any other 
//class to be implemented in order to work. 





//class invariants

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class EncryptWord
{
private:
	int ASCIICAP = 65;      //Maximum ascii number for Cap letter shift
	int ASCII = 97;         //Maximum ascii number for lower letter shift.
	int ALPHABETNUM = 26;   //number of letters in the alphabet.
	int cipher;             //value of the cipher shift.
	int numberOfGuesses;    //number of times user has guessed.
	int highGuess;          //highest guess by user.
	int lowGuess;           //lowest guess by user.
	int average;            //average amount of guesses for user.
	int sum;                //sum of all the guesses.
	string result;          //string for the encrypted word. 
	string decryptedWord;   //unencrypted word
	bool isOn;      //initializes the state of the game to off.
	bool isEqual;
public:

	//constructor
	EncryptWord();

	//copy constructor
	EncryptWord(const EncryptWord &);

	//assignment operator
	EncryptWord& operator=(const EncryptWord &);

	EncryptWord operator+(const EncryptWord &); 
	//description: overloaded + operator adds the cipher shift value of both
	//given words and the creates a new cipher shift value that gets reassigned
	//to the encrypt functions.
	//preconditions: Two objects of the EncryptWord class do need to be establihed
	//inorder for you to get a new value of the cipher shift.
	//reassigns the cipher shift value of the EncryptWord class.

	bool operator==(const EncryptWord &);
	//description: overloaded == operator checks words in two objects of the 
	//EncryptWord class to see if the words are equal to each other before
	//encryption.
	//preconditions: two objects of the EncryptWord class need to be instantiated
	//inorder for this function to operate normally.
	//postconditions: two objects will be compared and a boolean value will be
	//given depending upon the objects match.

	bool operator!=(const EncryptWord &);
	//description: overloaded != operator checks words in two objects of the
	//EncryptWord class to see if the words are not equal to each other before
	//encryption.
	//preconditions: two objects of the EncryptWord class need to be instantiated
	//inorder for this function to operate normally.
	//postconditions: tow objects will be compared and a boolean value will ve 
	//given depending upon the obects match.

	int getCipher() const;
	//description: The getCipher function returns the value of the 
	//cipherShift if called upon by the programmer
	//preconditions: The only precondition of this function is that 
	//the cipherShift needs to exist at this point otherwise it will
	//return 0.
	//postcondtions: The output will be given of th cipher value.
	//The state of this class is now on once the because the given
	//can be encrypted.

	void setCipher(int cipher);
	//description: The setCipher function passes the cipher value
	//from the driver function
	//preconditions: In oder for this function to work you need to 
	// have a cipher value generated or declared. 
	//postcondtions: Once this has been set the encryptWord funciton
	//will be able to work. 

	int getNumberOfGuesses() const;
	//description: The getNumberOfGuesses returns the number of guesses
	//incremented automatically by the driver file.
	//preconditions: None
	//as it will return a zero of the number of guesses hasn't incremented.
	//postcondtions: returns the currenct number of guesses.

	void setNumberOfGuesses(int numberOfGuesses);
	//description: The setNumberOfGuesses sets the current number of guesses.
	//preconditions: None
	//postcondtions: setNumberOfGuesses to the new incremented number specified
	//in the driver file.

	int getHighGuess() const;
	//description: The getHighGuess returns the current high guess.
	//preconditions: None (will return 0 by default)
	//postcondtions: returns the most recent highGuess value.

	void setHighGuess(int highGuess);
	//description: The setHighGuess function checks to see if the current
	//guess is larger than the highest guess that is currently set.
	//preconditions: None
	//postcondtions: if current guess is highest sets the guess otherwise 
	//postconditions are none.

	int getLowGuess() const;
	//description: The getHighGuess function returns the current value of
	//lowGuess.
	//preconditions: None (will return 0 by default)
	//postcondtions: returns the current value of lowGuess.

	void setLowGuess(int lowGuess);
	//description: The setLowGuess function checks to see if the current
	//guess lower than what is already set as lowGuess value.
	//preconditions: None
	//postcondtions: If current guess is lower than the value already declared
	//it sets the current value. 

	int getSum() const;
	//description: The getSum function returns the current sum of guesses for incase
	//the user would like the output of this information.
	//preconditions: None (will return 0 by default)
	//postcondtions: returns the current state of the total sum of guesses.

	void sumOfGuess(int guess);
	//description: the sumOfGuess function totals the sum of guess the user has
	//inputed. This is for the sumAverage function. 
	//preconditions: Needs to have at least one guess. If both sum 
	//and numberOfGuesses are at zero there will be nothing to divide by
	//and function will not implement.
	//postcondtions: returns the sum of guesses for the sumAverage function.

	int getAverage() const;
	//description: the getAverage function returns the average set in the 
	//sumAverage funciton.
	//preconditions: None (will return 0 by default) 
	//postcondtions:

	void sumAverage();
	//description: the sumAverage fucntion sets the average of guesses for 
	//preconditions: all guesses need to be in positive integers or the average
	//will be calculated incorrectly.
	//postcondtions: calculates the average using the given sum and numberOfGuesses

	void encrypt(string word, int cipher);
	//description: The encrypt function takes the given word and given cipher
	//value and using the cipher using the ascii value of both upper and lower 
	//case letters and builds a new string shifting the letters forward to the 
	//given positions.
	//preconditions: the given word and cipher need to be established at this point
	// otherwise the function has nothing to encrypt.
	//postcondtions: creates a string called result that takes the given word and 
	//shifts it to the a new string with the give cipher value. State of the game
	//is flagged as on. 

	string getEncrypt() const;
	//description: The getEncrypt function returns the encrypted word. 
	//precondtions: There needs to be a word that has been given by the user
	// and then encrypted by the encrypt function otherwise it will not have
	// and result to display.
	//postcondtions: returns the encrypted word. 

	void decrypt(string word);
	//description: creates a decrypted copy of the word.
	//preconditions: None
	//postconditions: decryptedWord is created.

	string getDecrypt() const;
	//description: returns decryptedWord.
	//preconditions: If a word has not been created and 
	//called in the decrypt function this will display a blank space.
	//postconditions: returns a decrypted copy of the word specified by
	//the user

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

};

