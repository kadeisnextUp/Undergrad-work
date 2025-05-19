

#ifndef PLAYER_H
#define PLAYER_H
#include "Wheel.h"
#include <iostream>

class Player
{
private:
	Wheel wheel;
	int money;

public:
    //Constructor of player initializing the money
    Player(int starting_amount);

    //getters and setters
    void setMoney(int amount);

    
    int getMoney() const;   

    //Updates the money amount after a round is completed
    void updateMoney(int amount);
};
#endif
