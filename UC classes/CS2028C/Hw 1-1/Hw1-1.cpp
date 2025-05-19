#include <iostream>
#include <fstream>
#include <sstream> //string stream library --> used stack overflow for finding this library
#include <string>
#include <iomanip>
using namespace std;
/* this program will take in a file, read the contents, create and output two files with card catalog
* info and statsistical info
* Kaden Sawyer and Kira Brown-Johnson worked on this
*/ 

/* structure for card catalog
* Title
* author
* word count
* line count
*/
struct bookName {

	string title;
	string author_name;
	int word_count = 0;
	double letter_frequency[26] = { 0 };
	int line_count = 0;
};

int main() {
	ifstream bookFile;
	string fileName;
	bool run = true;
	ofstream cardCatalog, stats;
	
	char answer;

	while (run == true) {
		bookName input;
		double total_letters = 0;
		//ask user for input name of file
		// now attempt to open it 
		while (bookFile.is_open() == false) {
			cout << "Enter the name of the file:" << endl;
			cin >> fileName;
			cout << " Attempting to open file..." + fileName << endl;
			bookFile.open(fileName, ios::in);
			if (bookFile) {
				cout << "File opened succescully!" << endl;
			}
			else {
				cout << "File does not exist please enter a correct name.\n";
				bookFile.clear();
			}
		}
		getline(bookFile, input.title); //gets title
		getline(bookFile, input.author_name); //gets author
		string line;
			while (getline(bookFile, line)) { //while book is open do this
				input.line_count++;
				stringstream ss(line);
				string word;

				while (ss >> word) { //while there are lines, count words
					input.word_count++;
				}
				//letter total
				for (char letter : line) {

					if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
						//lowercase to count
						letter = tolower(letter);
						input.letter_frequency[letter - 'a']++;
						total_letters++;
					}
					



				}
			}

			





			//save structure information to file
			cardCatalog.open("CardCatalog.txt", ios::app);
			cardCatalog << "Title: " << input.title << endl;
			cardCatalog << "Author: " << input.author_name << endl;
			cardCatalog << "Word count: " << input.word_count << endl;
			cardCatalog << "Line count: " << input.line_count << endl;
			cardCatalog << endl;
			cardCatalog.close();

			cout << "Do you want to see the letter frequency? (y/n)" << endl;
			cin >> answer;
			// makes lowercase letter uppercase
			answer = toupper(answer);
			if (answer == 'Y') {
				/* go through letter_Num, get value and divde by total letter to get frequency and then 
				* output that percentage
				*/

				for (int k = 0; k < 26; ++k) {
					if (input.letter_frequency[k] >= 0) {
						double frequency = (input.letter_frequency[k] / total_letters) * 100; // Frequency as a percentage
						cout << fixed << setprecision(4);
						cout << static_cast<char>('a' + k) << ":" << frequency << "%" <<endl;
					}
				}
			}
			cout << "Do you want to process another book? (y/n)" << endl;
			cin >> answer;
			answer = toupper(answer);

			if (answer == 'N') {
				run = false;
				cout << "Closing file and ending program now." << endl;
			}
			//loop back through if true
			//close file to be opened again if the answer was Y
			bookFile.close();
	}
	
	
	return 0;
	}



	








