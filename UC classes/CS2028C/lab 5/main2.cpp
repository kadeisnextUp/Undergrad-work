#include <iostream>
#include <vector>
#include <stdexcept> // Needed for exception handling
#include "EntertainmentCollection.h"
using namespace std;


// Custom exception for a full shelf
class ShelfFullException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: The shelf is full. Cannot add anything else.";
    }
};

// Custom exception for an empty shelf
class ShelfEmptyException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: The shelf is empty. Cannot remove anything.";
    }
};

//video game class
class VideoGame {
public:
    string title;
    VideoGame(string t) : title(t) {}

    //get video game title
    string getTitle() {
        return title;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nMedia Shelf Menu:\n";
    cout << "1. Add Media\n";
    cout << "2. Remove Media\n";
    cout << "3. Count Media\n";
    cout << "4. Display Media\n";
    cout << "5. Exit\n";
}

int main() {
    int maxObjects;
    cout << "The maximum items that can be held is 10." << endl;
    EntertainmentCollection<VideoGame> myShelf; // Create a template onject
    int choice;
    string gameTitle;
    VideoGame* tempPoint = nullptr;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

        try {
            switch (choice) {
            case 1:
                cout << "Enter media title: ";
                getline(cin, gameTitle);
                tempPoint = new VideoGame(gameTitle);

                myShelf.add(tempPoint);
                break;
            case 2:
                myShelf.remove();
                break;
            case 3:
                cout << "Total items on shelf: " << myShelf.getCollection_num() << endl;
                break;
            case 4:
                myShelf.displayCollection();
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