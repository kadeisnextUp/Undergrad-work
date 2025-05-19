#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* this program will take in a file, read the contents, create and output two files with card catalog
* info and statsistical info
*/ 

/* structure for card catalog
* Title
* author
* word count
* line count
*/

int main() {
	ifstream bookFile;
	string bookName;
	bool run;
	char answer;
	ofstream cardCatalog, stats;

	// start a loop to get the name
	//ask user for input name of file
	// now attempt to open it 
	cout << " Attempting to open file... \n";
	bookFile.open(bookName, ios::in);
	if (bookFile.fail()) {
		cout << "File does not exist please enter a correct name. \n";
		cout << "Name of file: ";
		cin >> bookName;
	}
	else {
		cout << "File opened successfully!";
	}

	// end loop

	//save structure information to file
	cardCatalog.open("CardCatalog.txt", ios::app);
	cardCatalog <<"Title: " << file.title << endl;
	cardCatalog <<"Author: " << file.author << endl;
	cardCatalog << "Word count: " << file.word_count << endl;
	cardCatalog << "Line count: " << file.line_count << endl;

	cout << "Do you want to process another book? (y/n)" << endl;
	cin >> answer;
	// makes lowercase letter uppercase
	answer -= 32;
	if (answer == 'N') {
		run = false;
	}
	//loop back through if true








}