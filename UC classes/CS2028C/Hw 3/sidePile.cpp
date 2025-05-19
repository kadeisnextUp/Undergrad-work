#include "sidePile.h"

// constructor 
SidePile::SidePile() : top(-1) {}

bool SidePile::isEmpty() const {
    return top == -1;
}

bool SidePile::isFull() const {
    return top == MAX_CAPACITY - 1;
}

void SidePile::push(int card) {
    if (isFull()) {
        throw std::overflow_error("Side pile is full - cannot push more than 5 cards");
    }
    // increment top first, then store the card
    cards[++top] = card; 
}

int SidePile::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Side pile is empty - no cards to pop");
    }
    // return current top, then decrement
    return cards[top--]; 
}

//count is index plus 1
int SidePile::getCount() const {
    return top + 1; 
}