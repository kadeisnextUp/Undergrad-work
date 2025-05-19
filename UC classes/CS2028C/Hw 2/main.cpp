#include "Player.h"
#include "Wheel.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

/* All code was developed by Kaden Sawyer, Javon Kimbrough, and Kira Brown-Johnson
*/
using namespace std;

//fucntions to help out with gameplay
//stall for time
static void sleep(float seconds) {
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while (clock() < startClock + secondsAhead);
    return;
}

static bool y_or_n_check(char& checker) {
    return (checker == 'y' || checker == 'n');
}



int main() {
    //random numbers every time the program runs
    srand(time(0));
    //variables 
    int startingAmount;
    int betAmount;
    char difficultyMode;
    string wagerChoice;
    char continuePlaying;
    int wheelSize;

    cout << "Welcome to the all new autonomous Roulette wheel!" << endl;
    //stall for time
    sleep(2);
    cout << "You have chosen to test your luck" << endl;
    //stall for time
    sleep(2);
	cout << "May the odds be ever in your favor" << endl;
    sleep(2);

    // Difficulty selection
    cout << "Select mode: easy (e) or hard (h)?" << "\n";
    cin >> difficultyMode; 

    // Check for correct input
    while (difficultyMode != 'e' && difficultyMode != 'E' && difficultyMode != 'h' && difficultyMode != 'H') {
        cout << "Incorrect mode. Please enter 'e' for easy or 'h' for hard mode: ";
        cin >> difficultyMode;
    }

    cout << "You selected " << (difficultyMode == 'h' || difficultyMode == 'H' ? "Hard" : "Easy") << " mode.\n";

    // Player's starting amount
    cout << "Enter your starting amount: ";
    cin >> startingAmount;

    Player player(startingAmount);
    // Pointer to hold either either Wheel object
    Wheel* houseWheel = nullptr;  

    
    cout << "Enter the number of values on the wheel (min 6, max 20): ";
    cin >> wheelSize;

    // Validate input
    while (wheelSize < 6 || wheelSize > 20) {
        cout << "Invalid input. Enter a value between 6 and 20: ";
        cin >> wheelSize;
    }

    //Create player wheel using user-defined size
    Wheel playerWheel(1, wheelSize);

    //house wheel created with user-defined size
    if (difficultyMode == 'h' || difficultyMode == 'H') {
        houseWheel = new HardModeWheel(1, wheelSize);
        cout << "Hard mode selected!" << endl;
    }
    else {
        houseWheel = new Wheel(1, wheelSize);
        cout << "Easy mode selected" << endl;
    }
    // The game will run as long as the player has a balance of at least $6
    while (player.getMoney() >= 6) {
        cout << "Current Money: $" << player.getMoney() << endl;
        cout << "Enter your bet amount (The minimum is $6 and the max is $20): ";
        cin >> betAmount;

        // Check the bet amount
        while (betAmount < 6 || betAmount > 20 || betAmount > player.getMoney()) {
            cout << "Invalid bet. Please enter a value between $6 and $20, and not exceeding your current money." << endl;
            cin >> betAmount;
        }

        // Spin
        playerWheel.spin();
        int playerBall = playerWheel.getValue();
        cout << "Your ball landed on: " << playerBall << endl;

        // Player chooses to keep, double, or halve the wager
        do {
            cout << "Do you want to double, halve, or keep your wager the same? (Enter 'double', 'halve', or 'keep'): ";
            cin >> wagerChoice;

            if ((wagerChoice == "keep") || (wagerChoice == "double") || (wagerChoice == "halve")) {
                break; 
            }
            //check input
            else {
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
        } while (true);

        //Spin the wheel and calculate the result
        if (wagerChoice == "keep") {
            houseWheel->spin();
            int houseBall = houseWheel->getValue();
            cout << "House's ball landed on: " << houseBall << endl;

            if (playerBall > houseBall) {
                cout << "You win!" << endl;
                player.updateMoney(betAmount); // Player wins the bet amount
            }
            else {
                cout << "House wins!" << endl;
                player.updateMoney(-betAmount); // Player loses the bet amount
            }
        }
        //Double wager 
        else if (wagerChoice == "double") {
            houseWheel->spin();
            int houseBall1 = houseWheel->getValue();
            cout << "House rolled a " << houseBall1 << endl;

            if (playerBall > houseBall1) {
                houseWheel->spin();
                int houseBall2 = houseWheel->getValue();
                cout << "House rolled a " << houseBall2 << endl;

                if (playerBall > houseBall2) {
                    cout << "You win!" << endl;
                    player.updateMoney(betAmount * 2); // Player wins double the bet
                }
                else {
                    cout << "House wins!" << endl;
                    player.updateMoney(-betAmount * 2); // Player loses double the bet
                }
            }
            else {
                cout << "House wins!" << endl;
                player.updateMoney(-betAmount * 2); // Player loses double the bet
            }
        }
        //Halve wager 
        else if (wagerChoice == "halve") {
            houseWheel->spin();
            int houseBall1 = houseWheel->getValue();
            cout << "House rolled a " << houseBall1 << endl;

            if (playerBall > houseBall1) {
                cout << "You win!" << endl;
                player.updateMoney(betAmount / 2); // Player wins half the bet
            }
            else {
                houseWheel->spin();
                int houseBall2 = houseWheel->getValue();
                cout << "House rolled a " << houseBall2 << endl;

                if (playerBall > houseBall2) {
                    cout << "You win!" << endl;
                    player.updateMoney(betAmount / 2); // Player wins half the bet
                }
                else {
                    cout << "House wins!" << endl;
                    player.updateMoney(-betAmount / 2); // Player loses half the bet
                }
            }
        }

        //Asking the player if they want to continue
        do {
            cout << "Do you want to continue playing? (y/n): ";
            cin >> continuePlaying;

            if (continuePlaying == 'y' || continuePlaying == 'n') {
                break;
            }
            else {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        } while (true);

        if (continuePlaying == 'n') {
            cout << "Thank you for trying out the new autonomous roulette wheel!" << endl;
            sleep(2);
            break;
        }
        else if (continuePlaying == 'y' && player.getMoney() < 6) {
            cout << "You no longer have money to play the game" << endl;
            sleep(2);
            cout << "Thank You!!!" << endl;
        }
    }

    cout << "Thank you for playing! Your final balance is: $" << player.getMoney() << endl;

  
    delete houseWheel;

    return 0;
}
