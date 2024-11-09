#ifndef DECK_H
#define DECK_H

#include <stack>
#include <string>
#include <array>
#include <random>
#include <algorithm>

enum class CardType {
    MOVE_TO_POSITION, // Move to a specific position on the board (always forwards. if the player passes Go, they collect $200)
    MOVE_BACK, // Move backwards a certain number of spaces
    COLLECT_MONEY, // Collect money from the bank 
    PAY_MONEY, // Pay money to the bank
    GO_TO_JAIL, // Go directly to jail
    GET_OUT_OF_JAIL, // Get out of jail free
    PROPERTY_REPAIRS, // Pay for property repairs
    PAY_PLAYERS // Pay other players
};

struct Card {
    std::string description;
    CardType type;
    int value;
};

class Deck {
private:
    std::stack<Card> chanceDeck;
    std::stack<Card> communityChestDeck;

public:
    Deck();
    void shuffleDecks();
    Card drawChanceCard();
    Card drawCommunityChestCard();
};

#endif