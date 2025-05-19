#include "BinarySearchTree.h"
#include "Word.h"
#include <fstream>
#include <sstream>
#include <cctype>

int main() {
    BinarySearchTree<Word> tree;
    ifstream bookFile;
    string fileName;
    bool run = true;

    while (run) {
        cout << "Enter the name of the file:\n";
        cin >> fileName;
        bookFile.open(fileName);
        if (!bookFile) {
            cerr << "File could not be opened.\n";
            bookFile.clear();
            continue;
        }

        string title, author;
        getline(bookFile, title);
        getline(bookFile, author);

        string line;
        while (getline(bookFile, line)) {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                // Remove punctuation
                word.erase(remove_if(word.begin(), word.end(), [](char c) {
                    return ispunct(c);
                    }), word.end());

                // Lowercase
                transform(word.begin(), word.end(), word.begin(), ::tolower);

                // Try to find and update word in the tree
                Word temp(word);
                Word* existing = tree.find(temp);
                if (existing)
                    existing->count++;
                else
                    tree.insert(temp);
            }
        }

        bookFile.close();

        // Menu loop
        char choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Search for a word\n";
            cout << "2. Print words ascending\n";
            cout << "3. Print words descending\n";
            cout << "4. View tree size\n";
            cout << "5. Remove a word\n";
            cout << "6. Empty tree\n";
            cout << "7. Exit\n";
            cin >> choice;

            if (choice == '1') {
                string query;
                cout << "Enter word to search: ";
                cin >> query;
                Word* result = tree.find(Word(query));
                if (result)
                    cout << result->word << " found with count: " << result->count << endl;
                else
                    cout << query << " not found.\n";
            }
            else if (choice == '2') {
                tree.getAllAscending();
            }
            else if (choice == '3') {
                tree.getAllDescending();
            }
            else if (choice == '4') {
                cout << "Tree size: " << tree.size() << endl;
            }
            else if (choice == '5') {
                string toRemove;
                cout << "Enter word to remove: ";
                cin >> toRemove;
                try {
                    tree.checkRemove(Word(toRemove));
                    cout << "Removed.\n";
                }
                catch (const exception& e) {
                    cout << e.what() << endl;
                }
            }
            else if (choice == '6') {
                tree.~BinarySearchTree(); // call manually
                cout << "Tree cleared.\n";
            }

        } while (choice != '7');

        cout << "Process another file? (y/n)\n";
        char again;
        cin >> again;
        run = (toupper(again) == 'Y');
    }

    return 0;
}
