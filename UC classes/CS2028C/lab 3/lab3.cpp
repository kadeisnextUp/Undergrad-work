#include <iostream>
#include "Measurement.h"
using namespace std;

//All code was developed by Javon Kimbrough, Kira Brown Johnson, and Kaden Sawyer

int main() {
   
    int x, y, z;
    string operation;
    string input;
    int rand_val1, rand_val2, rand_val3;
    

    cout << "Please enter your littles value: " << endl;
    cin >> x ;
    cout << "Please enter your lots value: " << endl;
    cin >> y ;
    cout << "Please enter your heaps value: " << endl;
    cin >> z ;
    Measurement userInput(x, y, z);
    bool cont_loop = true;
    while (cont_loop) {
    cout << "Please choose which operator you would like to use: +, -, *, /, or ==: " << endl;
    cin >> operation;

    
    cout << "Please enter any other values that you may want to use in this calculation: " << endl;
    cout << "Please enter the littles value: " << endl;
    cin >> rand_val1;
    cout << "Please enter the lots value: " << endl;
    cin >> rand_val2;
    cout << "Please enter the heaps value: " << endl;
    cin >> rand_val3;
    Measurement random(rand_val1, rand_val2, rand_val3);
    if (operation == "+") {
        userInput + random;
    }
    else if (operation == "-") {
        userInput - random;
    }
    else if (operation == "*") {
        userInput * random;
    }
    else if (operation == "/") {
        userInput / random;
    }
    else if (operation == "==") {
        bool check = userInput == random;
        cout << check << endl;
    }

    
    cout <<"The current distance is "<< string(userInput) << endl;
    cout << "The distance in meters: " << userInput.inMeters() << " meters" << endl;
    
  cout << "Do you wish to continue? (enter yes or no)" << endl;
  cin >> input;
  
   if (input == "no") {
    cont_loop = false; // Exit the loop
    } else if (input == "yes") {
        cont_loop = true; // Continue the loop
    } else {
 cout << "Invalid input, please enter 'yes' or 'no'." << endl;
        }
    }

    return 0;
}
