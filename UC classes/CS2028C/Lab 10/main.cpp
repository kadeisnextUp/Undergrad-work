#include "HashTable.h"
#include "Student.h"
#include "ChainedHashTable.h"
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <ctime> // for date handling in Available()

using namespace std;

//probe comparison functions
// generate random MNumber (example: M12345678)
int generateRandomMNumber() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(10000000, 99999999);
    return dis(gen);
}

void runPerformanceTest(int tableSize) {
    HashTable linearTable(tableSize);
    ChainedHashTable chainedTable(tableSize);

    // add 50 random students
    for (int i = 0; i < 50; i++) {
        int mNumber = generateRandomMNumber();
        Student* student = new Student("First", "Last", mNumber, "CS");
        linearTable.addItem(student);
        chainedTable.addItem(student);
    }

    // test GetItem on the same student (last inserted)
    int testMNumber = generateRandomMNumber();
    Student testStudent("Test", "Student", testMNumber, "CS");
    linearTable.addItem(new Student(testStudent));
    chainedTable.addItem(new Student(testStudent));

    // reset count
    linearTable.resetProbeCount();
    chainedTable.resetComparisonCount();

    // perform lookups
    linearTable.getItem(testMNumber);
    chainedTable.getItem(testMNumber);

    // output 
    cout << "| " << setw(8) << tableSize << " | "
        << setw(14) << linearTable.getProbeCount() << " | "
        << setw(18) << chainedTable.getComparisonCount() << " |\n";
}

// Function to display the menu
void displayMenu() {
    cout << "\nMENU:\n"
        << "1. Add Student\n"
        << "2. Remove Student\n"
        << "3. Get Student\n"
        << "4. Check table length\n"
        << "5. Probe compariosn \n"
        << "6. Exit\n"
        << "Enter your choice: ";
}

// Function to run the test program
void TestProgram() {
    HashTable linearTable;
    ChainedHashTable chainedTable;
    int choice,mNumber ,tableChoice;
    string fName,lName,num,major;
    Student* result = nullptr;
    cout << "Select Hash Table Type:\n";
    cout << "1. Linear Probing\n";
    cout << "2. Chained Hashing\n";
    cout << "Enter choice: ";
    cin >> tableChoice;
    cin.ignore();

    while (true) {
        bool useLinear = (tableChoice == 1);
        displayMenu();
        cin >> choice;
        cin.ignore(); 
       

        switch (choice) {
        case 1: //add Student
            cout << "Enter First Name: ";
            getline(cin, fName);
            cout << "Enter Last Name: ";
            getline(cin, lName);
            cout << "Enter MNumber: (only digits) ";
            getline(cin, num);
            try {
                mNumber = stoi(num);
            }
            catch (const invalid_argument&) {
                cout << "Invalid MNumber. Please enter digits only.\n";
                break;
            }

            cout << "Enter Major: ";
            getline(cin, major);
            if (useLinear) {
                linearTable.addItem(new Student(fName, lName, mNumber, major));
            }
            else {
                chainedTable.addItem(new Student(fName, lName, mNumber, major));
            }
            
            cout << "Student added successfully.\n";
            break;

        case 2: //remove Student
            cout << "Enter MNumber to remove: ";
            getline(cin, num);
            try {
                mNumber = stoi(num);
            }
            catch (const invalid_argument&) {
                cout << "Invalid MNumber. Please enter digits only.\n";
                break;
            }
            if (useLinear) {
                result = linearTable.removeItem(mNumber);
            }
            else {
                //debugging
                if (result != nullptr) {
                    cout << "student found befor removing \n";
                }
                result = chainedTable.removeItem(mNumber);
            }
   
            if (result != nullptr) {
                cout << "Removed Student: ";
                result->getInfo();
                delete result; // clean up memory
            }
            else {
                cout << "Student not found.\n";
            }
            break;

        case 3: //get Student
            cout << "Enter MNumber to find: ";
            
            getline(cin, num);

            try {
                mNumber = stoi(num);
            }
            catch (const invalid_argument&) {
                cout << "Invalid MNumber. Please enter digits only.\n";
                break;
            }

            if (useLinear) {
                result = linearTable.getItem(mNumber);
            }
            else {
                result = chainedTable.getItem(mNumber);
            }
            if (result != nullptr) {
                cout << "Found Student: ";
                result->getInfo();
            }
            else {
                cout << "Student not found.\n";
            }
            break;

        case 4: //get Length
            if (useLinear) {
                cout << "Current number of students in table: " << linearTable.getLength() << endl;
                break;
            }
            else {
                cout << "Current number of students in table: " << chainedTable.getLength() << endl;
                break;
            }
            

        case 5: //probe comparison
            // table display
            cout << "| Table Size | Linear Probing | Chained Comparisons |\n";
            cout << "|------------|-----------------|---------------------|\n";

            // Test with different table sizes
            runPerformanceTest(100);
            runPerformanceTest(150);
            runPerformanceTest(200);
            runPerformanceTest(250);
            return;

        case 6:
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }

   
    
}

int main() {
    srand(time(0));
    TestProgram();
    return 0;
}