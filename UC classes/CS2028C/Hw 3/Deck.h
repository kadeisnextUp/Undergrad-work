#ifndef DECK_H 
#define DECK_H 

#include <iostream> 

struct cardNode {
	int cardValue;
	cardNode* next;
};

class Deck {
private:
	cardNode* front;
	cardNode* rear; 
	int size;

public:
	Deck();
	~Deck();
	void push(int card);
	int pop();
	int getSize() const;
	void display() const;
};

#endif
