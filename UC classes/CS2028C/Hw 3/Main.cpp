#include <iostream>
#include "Deck.h"
#include "SidePile.h"
#include <cstdlib>
#include <ctime>
// for input validation
#include <limits> 

void playGame(int style);
void displayGameState(const Deck& playerDeck, const Deck& computerDeck,
    const SidePile& playerSidePile, const SidePile& computerSidePile);

// helper function to check if deck is empty
bool isDeckEmpty(const Deck& deck) {
    return deck.getSize() == 0;
}

int main() {
    int style;
    std::cout << "Welcome to I-Declare-War!\n";
    std::cout << "Choose style of play:\n1. Play until out of cards\n2. Play for fixed rounds\n";

    //input validation
    while (!(std::cin >> style) || (style != 1 && style != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter 1 or 2: ";
    }

    srand(static_cast<unsigned>(time(0)));
    playGame(style);
    return 0;
}

void displayGameState(const Deck& playerDeck, const Deck& computerDeck,
    const SidePile& playerSidePile, const SidePile& computerSidePile) {
    std::cout << "\nCurrent Game State:\n";
    std::cout << "Player - Deck: " << playerDeck.getSize()
        << " cards, Side Pile: " << playerSidePile.getCount() << "/5\n";
    // computer side pile not shown to player
    std::cout << "Computer - Deck: " << computerDeck.getSize()
        << " cards\n";
}

void playGame(int style) {
    Deck playerDeck, computerDeck;
    SidePile playerSidePile, computerSidePile;

    // initialize decks with random cards 
    for (int i = 0; i < 10; ++i) {
        playerDeck.push(rand() % 10 + 1);
        computerDeck.push(rand() % 10 + 1);
    }

    int rounds = 0;
    int maxRounds = (style == 2) ? 20 : 0; 
    bool gameOver = false;

    std::cout << "\nGame Started!\n";
    displayGameState(playerDeck, computerDeck, playerSidePile, computerSidePile);

    // gameplay
    while (!gameOver) {
        rounds++;
        std::cout << "\n=== Round " << rounds << " ===\n";

        // player's turn
        int playerCard;
        if (isDeckEmpty(playerDeck)) {
            if (playerSidePile.isEmpty()) {
                std::cout << "Player has no cards left! Computer wins!\n";
                gameOver = true;
                break;
            }
            playerCard = playerSidePile.pop();
            std::cout << "Player drew from side pile: " << playerCard << "\n";
        }
        else {
            playerCard = playerDeck.pop();
            std::cout << "Player drew from deck: " << playerCard << "\n";

            // player decides to push to side pile or keep
            int choice;
            std::cout << "Do you want to:\n1. Play this card\n2. Push to side pile (draw new card)\n";
            std::cout << "Enter choice (1 or 2): ";

            while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter 1 or 2: ";
            }

            if (choice == 2) {
                try {
                    playerSidePile.push(playerCard);
                    std::cout << "Card pushed to side pile. Drawing new card...\n";
                    if (!isDeckEmpty(playerDeck)) {
                        playerCard = playerDeck.pop();
                        std::cout << "New card drawn: " << playerCard << "\n";
                    }
                    else {
                        std::cout << "No more cards in deck! Using side pile card.\n";
                        playerCard = playerSidePile.pop();
                    }
                }
                catch (const std::overflow_error& e) {
                    std::cout << "Cannot push to side pile: " << e.what() << "\n";
                }
            }
        }

        // computer's turn 
        int computerCard;
        if (isDeckEmpty(computerDeck)) {
            if (computerSidePile.isEmpty()) {
                std::cout << "Computer has no cards left! Player wins!\n";
                gameOver = true;
                break;
            }
            computerCard = computerSidePile.pop();
            std::cout << "Computer drew from side pile\n";
        }
        else {
            computerCard = computerDeck.pop();
            std::cout << "Computer drew from deck\n";

            // computer strategy (30% chance to push to side pile if not full)
            if (!computerSidePile.isFull() && (rand() % 100 < 30)) {
                try {
                    computerSidePile.push(computerCard);
                    if (!isDeckEmpty(computerDeck)) {
                        computerCard = computerDeck.pop();
                        std::cout << "Computer pushed a card to side pile and drew a new one\n";
                    }
                    else {
                        computerCard = computerSidePile.pop();
                    }
                }
                catch (...) {
                    // if the push fails, computer keeps original card
                }
            }
        }

        // round winner
        std::cout << "Player plays: " << playerCard << " vs Computer plays: " << computerCard << "\n";

        if (playerCard > computerCard) {
            std::cout << "Player wins the round!\n";
            // adding cards to player's deck
            playerDeck.push(playerCard);
            playerDeck.push(computerCard);
        }
        else if (computerCard > playerCard) {
            std::cout << "Computer wins the round!\n";
            // adding cards to computer's deck
            computerDeck.push(computerCard);
            computerDeck.push(playerCard);
        }
        else {
            std::cout << "Tie! Computer wins by default.\n";
            computerDeck.push(computerCard);
            computerDeck.push(playerCard);
        }

        displayGameState(playerDeck, computerDeck, playerSidePile, computerSidePile);

        //check game end conditions
        if (style == 2 && rounds >= maxRounds) {
            std::cout << "\nGame over after " << maxRounds << " rounds!\n";
            if (playerDeck.getSize() + playerSidePile.getCount() >
                computerDeck.getSize() + computerSidePile.getCount()) {
                std::cout << "Player wins with more cards!\n";
            }
            else {
                std::cout << "Computer wins with more cards!\n";
            }
            gameOver = true;
        }
        else if (isDeckEmpty(playerDeck) && playerSidePile.isEmpty()) {
            std::cout << "Player has no cards left! Computer wins!\n";
            gameOver = true;
        }
        else if (isDeckEmpty(computerDeck) && computerSidePile.isEmpty()) {
            std::cout << "Computer has no cards left! Player wins!\n";
            gameOver = true;
        }
    }
}