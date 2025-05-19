#ifndef SIDEPILE_H
#define SIDEPILE_H


#include <stdexcept>

class SidePile {
private:
    static const int MAX_CAPACITY = 5; 
    int cards[MAX_CAPACITY];           
    int top;                           

public:
    SidePile();

    // check if the side pile is empty
    bool isEmpty() const;

    // check if the side pile is full
    bool isFull() const;

    // add a card to the top of the side pile
    void push(int card);

    // remove and return the top card from the side pile
    int pop();

    // get the current number of cards in the side pile
    int getCount() const;
};

#endif // SIDEPILE_H
