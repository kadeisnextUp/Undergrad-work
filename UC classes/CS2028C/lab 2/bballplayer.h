//header file
#ifndef BBALLPLAYERH
#define BBALLPLAYERH

#include <iostream>
#include <string>
using namespace std;

class bball_player {
private:
    string player_name; int shots_taken; int shots_made; int passes_attempted; int passes_made;

public:
    bball_player(string player_name); bool pass_ball(); int take_shot(int points_scored); void player_stats() const; 
    string GetName() const;
    int getShotsMade() const; int getShotsTaken() const;int getPassesMade() const; int getPassesAttempted() const;
    void setShotsMade(int shot); void setShotsTaken(int shot); void setPassesMade(int pass); void setPassesAttempted(int pass);



};
#endif