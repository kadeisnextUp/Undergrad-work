#include "Player.h"

Player::Player(int initialMoney) : money(initialMoney) {}

/*Function definition to set the money of the player equal to the amount given*/
void Player::setMoney(int amount) {
    money = amount;
}
/*Function definition to get the money of the user */
int Player::getMoney() const {
    return money;
}
/*Function definition to update the money of the user*/
void Player::updateMoney(int amount) {
/*Adds(or Subtracts) the amount of money made or lost that round to money*/
    money += amount;
}


