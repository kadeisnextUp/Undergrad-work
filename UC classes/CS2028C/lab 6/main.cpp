// Include necessary libraries for input/output, file handling, and string manipulation
#include <iostream>   // Provides standard input and output operations (cin, cout, endl)
#include <fstream>    // Enables file input and output operations (ifstream, ofstream)
#include <sstream>    // Allows for string stream operations, useful for parsing text
#include "Stack.h"   // Assuming you have implemented Stack from Task 1
#include "Queue.h"   // Assuming you have implemented Queue from Task 2

// Use the standard namespace to avoid prefixing std:: before common functions
using namespace std;

// Function to reverse the letters in a word using a stack
string reverseWord(const string& word) {
    Stack<char> charStack(word.length()); // Create a stack with enough space for the word

    // Push each character of the word onto the stack
    for (char ch : word) {
        charStack.push(new char(ch)); // Store each character in the stack
    }

    string reversedWord;
    // Pop characters from the stack to get them in reverse order
    while (charStack.length() !=0 ) {
        reversedWord += *charStack.pop(); // Add the reversed character to the new word
    }

    return reversedWord; // Return the reversed word
}

// Function to process text: reverses letters in each word but keeps word order
string processText(const string& input) {
    stringstream ss(input); // String stream to read words
    string word;
    queue<string> wordQueue(100); // Create a queue to maintain word order

    // Read each word, reverse it, and enqueue it
    while (ss >> word) { // Extract words from input
        wordQueue.enqueue(new string(reverseWord(word))); // Store reversed word in queue
    }

    string result;
    // Dequeue words to maintain original order
    while (wordQueue.length() != 0) {
        result += *wordQueue.dequeue() + " "; // Get words back in order
    }

    return result; // Return processed text
}

// Function to handle file input
void processFile() {
    string filename;
    ifstream file;

    // Prompt user for a valid file and keep asking until a valid file is provided
    while (true) {
        cout << "Enter the filename: ";
        cin >> filename;
        file.open(filename);
        if (file) break; // If file opens successfully, break the loop
        cout << "File not found. Try again.\n";
    }

    string line, finalOutput;
    // Read the file line by line
    while (getline(file, line)) {
        finalOutput += processText(line) + "\n"; // Process each line and store output
    }
    file.close(); // Close the file

    cout << "Processed text:\n" << finalOutput << endl; // Display final output
}

// Function to handle user input from the command line
void processCommandLine() {
    cin.ignore(); // Clear any previous input in the buffer
    cout << "Enter a line of text: ";
    string input;
    getline(cin, input); // Get the full line of input from the user

    cout << "Processed text:\n" << processText(input) << endl; // Display processed output
}

int main() {
    while (true) { // Infinite loop to keep asking user until they choose to exit
        cout << "Choose input method:\n";
        cout << "1. Read from a file\n2. Enter text manually\n3. Exit\nChoice: ";
        int choice;
        cin >> choice;

        try {
            if (choice == 1) {
                processFile(); // Process text from a file
            }
            else if (choice == 2) {
                processCommandLine(); // Process text entered manually
            }
            else if (choice == 3) {
                cout << "Exiting program.\n";
                break; // Exit loop and end program
            }
            else {
                cout << "Invalid choice. Try again.\n"; // Handle invalid inputs
            }
        }
        catch (const exception& e) {
            cout << "An error occurred: " << e.what() << endl; // Handle any unexpected errors
        }
    }

    return 0; // End program
}
