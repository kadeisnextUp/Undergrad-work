#include "DoubleLinkedList.h"
#include "Part.h"
#include <iostream>
#include <string>
#include <ctime> // for date handling in Available()

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nMENU:\n"
        << "1. Add Part\n"
        << "2. Get/Remove Part\n"
        << "3. Check If List is Empty\n"
        << "4. Get List Size\n"
        << "5. Check If Part is in List\n"
        << "6. See Next Part\n"
        << "7. See Previous Part\n"
        << "8. See Part at Index\n"
        << "9. Reset SeeNext pointer\n"
        << "10. Display All Parts (ASCII Visualization)\n"
        << "11. Exit\n"
        << "Enter your choice: ";
}

// Function to run the test program
void TestProgram() {
    DoubleLinkedList<Part> partsList;
    int choice, sku, qty, index, days;
    string desc, uom;
    double price;
    Part* partPtr = nullptr;

    while (true) {
        displayMenu();
        cin >> choice;

        try {
            switch (choice) {
            case 1: // Add Part
                cout << "Enter SKU: ";
                cin >> sku;
                cout << "Enter Description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Unit of Measure (UOM): ";
                cin >> uom;
                cout << "Enter Quantity On Hand: ";
                cin >> qty;
                cout << "Enter days required to reorder: ";
                cin >> days;

                partsList.addItem(new Part(sku, desc, price, uom, qty,days));
                cout << "Part added successfully.\n";
                break;

            case 2: // Get/Remove Part
                cout << "Enter SKU to remove: ";
                cin >> sku;
                partPtr = partsList.getItem(new Part(sku, "", 0.0, ""));
                if (partPtr != nullptr) {
                    cout << "Removed Part: " << partPtr->GetPartInfo() << endl;
                    delete partPtr; // Remember to delete the pointer returned by getItem
                }
                else {
                    cout << "Part not found.\n";
                }
                break;

            case 3: // Check if empty
                cout << (partsList.IsEmpty() ? "List is empty.\n" : "List is not empty.\n");
                break;

            case 4: // Get size
                cout << "List contains " << partsList.size() << " parts.\n";
                break;

            case 5: // Check if in list
                cout << "Enter SKU to check: ";
                cin >> sku;
                cout << (partsList.IsInList(new Part(sku, "", 0.0, ""))) ? "Part is in the list.\n" : "Part not found.\n";
                break;

            case 6: // See Next
                partPtr = partsList.seeNext();
                if (partPtr != nullptr) {
                    cout << "Next Part: " << partPtr->GetPartInfo() << endl;
                }
                else {
                    cout << "Reached end of list or list is empty.\n";
                }
                break;

            case 7: // See Previous
                partPtr = partsList.seePrev();
                if (partPtr != nullptr) {
                    cout << "Previous Part: " << partPtr->GetPartInfo() << endl;
                }
                else {
                    cout << "Reached beginning of list or list is empty.\n";
                }
                break;

            case 8: // See At
                cout << "Enter index (0-based): ";
                cin >> index;
                partPtr = partsList.seeAt(index);
                if (partPtr != nullptr) {
                    cout << "Part at index " << index << ": " << partPtr->GetPartInfo() << endl;
                }
                break;

            case 9: // Reset
                partsList.reset();
                cout << "SeeNext pointer reset to beginning of list.\n";
                break;

            case 10: // Display all parts (ASCII Visualization)
            {
                // First reset the seeNext pointer
                partsList.reset();

                cout << "\n===== PARTS LIST VISUALIZATION =====\n";
                partPtr = partsList.seeNext();
                while (partPtr != nullptr) {
                    partPtr->Display();
                    partPtr = partsList.seeNext();
                }
                // Reset again after display
                partsList.reset();
                cout << "===== END OF LIST =====\n";
            }
            break;

            case 11: // Exit
                return;

            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

int main() {
    TestProgram();
    return 0;
}