#include <iostream>
#include <vector>
#include <stdexcept> // Needed for exception handling
#include "lab5_task1.h"


using namespace std;

// Custom exception for a full shelf
class ShelfFullException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: The shelf is full. Cannot add more movies.";
    }
};

// Custom exception for an empty shelf
class ShelfEmptyException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: The shelf is empty. Cannot remove movies.";
    }
};


// Function to display the menu
void displayMenu() {
    cout << "\nMovie Shelf Menu:\n";
    cout << "1. Add Movie\n";
    cout << "2. Remove Movie\n";
    cout << "3. Count Movies\n";
    cout << "4. Display Movies\n";
    cout << "5. Exit\n";
}

int main() {
    int maxMovies;
    cout << "The max amount of movies on the shelf is 10." << endl;
    Shelf myShelf; // Create a Shelf object
    int choice;
    string movieTitle;
    Movie* tempPoint = nullptr;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

        try {
            switch (choice) {
            case 1:
                cout << "Enter movie title: ";
                getline(cin, movieTitle);
                tempPoint = new Movie(movieTitle);

                myShelf.add(tempPoint);
                break;
            case 2:
                myShelf.remove();
                break;
            case 3:
                cout << "Total movies on shelf: " << myShelf.getMovies_num() << endl;
                break;
            case 4:
                myShelf.displayMovies();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const exception& e) {
            cout << e.what() << endl; // Catch and display exceptions
        }
    } while (choice != 5);

    return 0;
}