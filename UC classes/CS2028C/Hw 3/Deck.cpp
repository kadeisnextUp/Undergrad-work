#include "deck.h" 

//The constructor 
Deck::Deck() : front(nullptr), rear(nullptr), size(0) {}

//The destructor 
Deck::~Deck() {
    while (front != nullptr) {
        cardNode* temp = front;
        front = front->next;
        delete temp;
    }
}

//This will add the card to the back of the deck 
void Deck::push(int card) {
    cardNode* newCard = new cardNode;
    newCard->cardValue = card;
    newCard->next = nullptr;
    if (rear) {
        rear->next = newCard;
    }
    else {
        front = newCard; // New card for the empty deck 
    }
    rear = newCard; // Update to the new card 
    size++;
}

//Removes the card from the front of the deck 
int Deck::pop() {
    if (front == nullptr) return -1; // Empties the Deck 
    int cardValue = front->cardValue;
    cardNode* temp = front;
    front = front->next;
    delete temp;
    size--;
    if (front == nullptr) rear = nullptr; // Empties the Deck 
    return cardValue;
}

// This will get the size of the deck 
int Deck::getSize() const {
    return size;
}

// This will display the number of cards 
void Deck::display() const {
    std::cout << "Deck size: " << size << std::endl;
}
