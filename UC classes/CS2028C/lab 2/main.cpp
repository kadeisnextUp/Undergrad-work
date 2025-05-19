#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include "bballplayer.h" // header file
using namespace std;

// Kaden Sawyer and Kira Brown-Johnson worked on every part of this lab


void opponentSim(bball_player& oppPlayer, int& team2Score, int& possession2) {
	int shot;
	int scores;
	int offRebound;
	if (possession2 < 30) {
		bool endPossession = false;
		//opponent possession
		while (!endPossession) {
			cout << oppPlayer.GetName() << " has the ball" << endl;
			shot = rand() % 3 + 1; // Randomly select 1, 2, or 3-point shot
			cout << oppPlayer.GetName() << " shoots and..." << endl;

			// 60% chance to make the shot
			if (rand() % 10 < 6) { 
				cout << oppPlayer.GetName() << " scores " << shot << " point(s)!" << endl;
				team2Score += shot;
				possession2++;
				//possession ends
				endPossession = true;
			}
			// Shot missed
			else { 
				cout << "He misses!!" << endl;
				if (rand() % 2 == 0) { // 50% chance of offensive rebound
					cout << "The Musketeers got the rebound." << endl;
				}
				else {
					cout << "The Bearcats got the rebound." << endl;
					possession2++;
					endPossession = true;
				}
			}
		}
	}
}

void printStats(bball_player team[]) {
	cout << "Showing team stats: " << endl;
	for (int k = 0; k < 5; k++) {
		cout << team[k].GetName() << endl;
		cout << "Shots Taken: " << team[k].getShotsTaken() << endl;
		cout << "Shots Made: " << team[k].getShotsMade() << endl;
		cout << "Passes Attempted: " << team[k].getPassesAttempted() << endl;
		cout << "Passes Made: " << team[k].getPassesMade() << endl;
		cout << endl;
	}
}

//this fucntion will make sure the user inputs are valid and will not continue code until it is valid
void checkInput(int start, int limit, int& input) {
	while (input < start || input > limit) {
		cout << "Invalid input. Enter a number between " << start << " and " << limit << ": ";
		cin >> input;  // Always use `cin` only if an invalid input was entered

	}
}

					
int main() {
	// for different random numbers every time the code is ran
	srand(time(0));

	// names of random NBA players
	// two arrays of basketball player objects
	 bball_player team1[5] = {
		bball_player("Bronny James"),
		bball_player("Anthony Edwards"),
		bball_player("Jaysom Tatum"),
		bball_player("Jimmy Butler"),
		bball_player("Anthony Davis"),
		};

	bball_player team2[5] = {
		bball_player("Allen Iverson"),
		bball_player("Michael Jordan"),
		bball_player("Lamelo Ball"),
		bball_player("Lebron James"),
		bball_player("Tim Duncan"),
		};
	//generate stats so the game can actually continue
	int count = 0;
	while (count < 10) {
		int shotTaken = rand() % 101;
		int shotsMade = (shotTaken > 0) ? rand() % shotTaken : 0;
		int passesAttempted = rand() % 21;
		int passesMade = (passesAttempted > 0) ? rand() % passesAttempted : 0;
		if (count <= 4) {
			//team 1 random stats
			team1[count].setShotsTaken(shotTaken);
			team1[count].setShotsMade(shotsMade);
			team1[count].setPassesAttempted(passesAttempted);
			team1[count].setPassesMade(passesMade);
		}
		else {
			//team 2 random stats 
			team2[count - 5].setShotsTaken(shotTaken);
			team2[count - 5].setShotsMade(shotsMade);
			team2[count - 5].setPassesAttempted(passesAttempted);
			team2[count - 5].setPassesMade(passesMade);
		}
		count++;
	}

	
	//input test file
	//file name is wrong on purpose chnage to appropriate text file name
	ifstream inputFile("shortput.txt");
	//if there is a file open it. if not take manual input
	//declare inputsource as a reference so it can be reassigned when the file runs out of lines
	istream* inputSource = inputFile.is_open() ? &inputFile : &cin;

	cout << "The teams have been chosen we have the Cincinnati Bearcats (you) vs the Xavier Musketeers (not you)" << endl;
	cout << "Tipoff begins and the Bearcats get the ball first!" << endl << endl;

	//start the game
	int possession1 = 0;
	int possession2 = 0;
	int team1Score = 0;
	int team2Score = 0;
	while (possession1 < 30 and possession2 < 30) {
		int currentPossession = rand() % 5;
		int opponentPossession = rand() % 5;
		int userInput = 0;
		bool endPossesion = false;
		bball_player& currPlayer = team1[currentPossession];
		bball_player& oppPlayer = team2[opponentPossession];
		cout << "Bearcats possession # " << possession1 << endl;
		cout << "Musketeers possession # " << possession2 << endl;
		while (endPossesion == false) {
			cout << currPlayer.GetName() << " has the ball. Do you want to shoot(1), pass(2), see the stats(3), see the score(4)" 
				<< endl;
			// Only switch to cin if EOF is truly reached
			if (!(*inputSource >> userInput)) {
				if (inputSource->eof()) {
					cout << "End of file reached. Switching to manual input." << endl;
					inputFile.close();
					inputSource = &cin;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					cout << "Invalid input detected. Skipping..." << endl;
					inputSource->clear();
					inputSource->ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}


			//check input
			checkInput(1, 4, userInput);
			if (userInput == 1) {
				int shot = 0;
				int scores = 0;
				int oppScores = 0;
				cout << "What do you want the value of the shot to be? (1, 2 or 3)" << endl;
				*inputSource >> shot;
				//check input
				checkInput(1, 3, shot);

				scores = currPlayer.take_shot(shot);
				if (scores == 0) {
					int offRebound = rand() % 2;
					if (offRebound == 1) {
						cout << "The Bearcats got the rebound." << endl;
					}
					else {
						cout << "The other team got the rebound." << endl;
						// other team has possesion
						possession1++;
						endPossesion = true;
						opponentSim(oppPlayer, team2Score, possession2);
					}

				}
				else {
					team1Score += scores;
					possession1++;
					// other team has possesion
					endPossesion = true;
					opponentSim(oppPlayer, team2Score, possession2);

				}
			}
			else if (userInput == 2) {
				bool successfulPass = false;

				userInput = currentPossession;
				cout << "Who do you want to pass to (enter a number 1-5)? 0: Bronny James 1: Anthony Edwards 2: Jaysom Tatum ";
				cout << "3: Jimmy Butler 4: Anthony Davis" << endl;
				while (userInput == currentPossession && (userInput >= 0 && userInput <=4)) {
					*inputSource >> userInput;
					checkInput(0, 4, userInput);
				}

				successfulPass = currPlayer.pass_ball();
				if (successfulPass == true) {
					cout << "The pass was completed." << endl;
					cout << team1[userInput].GetName() << " has the ball." << endl;
					currPlayer = team1[userInput];
				}
				else {
					//random real life action that would happen in a game
					int turnover = rand() % 2;
					endPossesion = true;
					if (turnover == 0) {
						cout <<currPlayer.GetName() << " over throws the ball and causes a turnover" << endl;
					}
					else {
						cout << team1[userInput].GetName() << " has butter fingers and couldn't catch the pass casuing a turnover" << endl;
					}
					possession1++;
					//other team has possession
					opponentSim(oppPlayer, team2Score, possession2);


				}
			}
			else if (userInput == 3) {
				printStats(team1);
			}
			else if (userInput == 4) {
				cout << "Bearcats: " << team1Score << " Musketeers: " << team2Score << endl;
				cout << "The Bearcats have " << (30 - possession1) << " possesions left" << " and the Musketeers have ";
				cout << (30 - possession2) << " possesion left" << endl;
			}
			else {
				cout << "Error you entered the wrong number pick a number 1-4 to choose the next action..." << endl;
			}
		}
		

	}
	
	cout << "And that's time the game is over." << endl;
	cout << "Final score: Bearcats " << team1Score << "- Musketeers " << team2Score << endl;

}






