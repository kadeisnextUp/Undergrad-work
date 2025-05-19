#include <string>
//VOWELS:  a, e, i, o, and u
char vowelList[] = { 'a','e','i','o','u' };
int vowelListSize = 5;
/*
*  is_vowel
*
*  checks to see if a letter is a vowel or not
*
*  input: a char that is the letter you want to check
*  output: a bool is returned and will be true if the char is a vowel or false if it
*  isn't
*/


bool is_vowel(char test) {
	bool check = false;
	int k;
	for (k = 0; k < vowelListSize; ++k) {
		if (test == vowelList[k]) {
			check = true;
		}


	}
	return check;
}

/* is_consonant
*
*  checks to see if a letter is a consonant or not
*
*  input: a char that is the letter you want to check
*  output: returns a bool that will be true if the letter is a consonant or false
*  if not
*
*/

bool is_consonant(char test) {
	bool check = true;
	int k;
	for (k = 0; k < vowelListSize; ++k) {
		if (test == vowelList[k]) {
			check = false;
		}
	}

	return check;
}

/*
*  ends_With_double_consonant
*
*  checks to see if the word ends with a double consonant
*
*  input: a string that is the word you want to check
*  output: a bool that will be true if the word ends with a double consonant
*  and false if not.
*
*/
bool ends_with_double_consonant(std::string test) {
	if (test.length() < 2) {
		return false;
	}

	char lastChar = test[test.length() - 1];
	char secondLastChar = test[test.length() - 2];

	return is_consonant(lastChar) && (lastChar == secondLastChar);
}

/*
*   ends_with_cvc
*
*	check to see if the last three letters of the word end in consonant, vowel, consonant
*
*
*   input: a string that is the word you want to check
*   output: a bool is returned that will be true if the word ends with "cvc"
*	or false if not
*
*/
bool ends_with_cvc(std::string test) {
	if (test.length() < 3) {
		return false; 
	}

	char lastChar = test[test.length() - 1];
	char secondLastChar = test[test.length() - 2];
	char thirdLastChar = test[test.length() - 3];


	return is_consonant(thirdLastChar) && is_vowel(secondLastChar) && is_consonant(lastChar);
}


/*
*   contains_vowel
*
*   input:a string that is the word you want to check
*   output: a bool is returned that will be true if the word contains
*   vowels and false otherwise
*
*/
bool contains_vowel(std::string test) {
	int length = test.length();
	bool check = false;
	int k;

	for (k = 0; k < length; ++k) {
		if (is_vowel(test[k]) == true) {
			check = true;
		}
	}

	return check;
}


/*
*
*   count_consonants_at_front
*
*   input: a string that is the word you want check
*	output: a int will be returned that will give the amount of
*	at the beginning of th word
*/

int count_consonants_at_front(std::string test) {
	int count = 0;
	int length = test.length();
	int k;

	for (k = 0; k < length; ++k) {
		if (is_consonant(test[k]) == true) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}


/*
*
*   count_vowels_At_back
*
*   input: a string that is the word you want to check
*	output: a int will be returned representing the amount of vowels
*	at the back of the word
*/
int count_vowels_at_back(std::string test) {
	int count = 0;
	int k;
	int length = test.length();

	for (k = length-1; k >= 0; --k) {
		if (is_vowel(test[k]) == true) {
			count++;
		}
		else {
			break;
		}
	}



	return count;
}

/*
*	ends_with
*
*	input: two strings that is the word you want to check
*	and the suffix
*	output: a bool is returned that will be true if the word contains the suffix
*	and false otherwise
*/
bool ends_with(std::string test, std::string suffix) {
	if (suffix.empty()) {
		return true;
	}

	if (test.length() < suffix.length()) {
		return false;
	}

	return test.substr(test.length() - suffix.length()) == suffix;
}


/*
*	new_ending
*
*	input: a string that will be changed at the end, a int that is the lenght of the suffix of the canidate,
*	and a string that is the suffix.
*	output: a string will be returned that has the new suffix to it
*
*/
std::string new_ending(std::string test, int suffixLength, std::string suffix) {
	return test.substr(0, test.length() - suffixLength) + suffix;
}