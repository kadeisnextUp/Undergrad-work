#include "bballplayer.h"
#include <cstdlib> // random library
#include <ctime>   // time library

// Constructor 
bball_player::bball_player(string player_name)
    :player_name(player_name),
    shots_taken(0),
    //typically make less shots than you take
    shots_made(0),
    passes_attempted(0),
    passes_made(0)
{
}

// PassBall
bool bball_player::pass_ball() {
    passes_attempted++;

    int pass_percentage = (passes_attempted == 1) ? 70 : (passes_made * 100) / passes_attempted;
    int randomNum = rand() % 100 + 1;

    if (randomNum <= pass_percentage) {
        passes_made++;
        return true;
    }
    return false;
}

// TakeShot
int bball_player::take_shot(int points_scored) {
    if (points_scored < 1 || points_scored > 3) return 0;

    shots_taken++;

    int maxRandomRange = (points_scored == 1) ? 70 : (points_scored == 2) ? 100 : 125;
    int randomNum = rand() % maxRandomRange + 1;

    //shooting percentage
    int shoot_percentage = (shots_taken == 0) ? 0 : (shots_made * 100) / shots_taken;

    if (randomNum <= shoot_percentage) {
        shots_made++;
        cout << player_name << " hits a " << points_scored << "-point shot!" << endl;  //
       
        return points_scored;
    }
    else {
        cout << player_name << " missed a " << points_scored << "-point shot :(" << endl;
    }



    return 0;
}

// getters and setters
string bball_player:: GetName() const {
    return player_name;
}

int bball_player::getShotsMade() const {
    return shots_made;
}
int bball_player::getShotsTaken() const {
    return shots_taken;
}
int bball_player::getPassesMade() const {
    return passes_made;
}
int bball_player::getPassesAttempted() const {
    return passes_attempted;
}

void bball_player::setShotsMade(int shot) {
    shots_made = shot;
}
void bball_player::setShotsTaken(int shot) {
    shots_taken = shot;
}
void bball_player::setPassesMade(int pass) {
    passes_made = pass;
}
void bball_player::setPassesAttempted(int pass) {
    passes_attempted = pass;
}

