#ifndef DECK_H
#define DECK_H

#include <stack>
#include <string>
#include <array>
#include <random>

enum class CardType {
    MOVE_TO_POSITION,
    COLLECT_MONEY,
    PAY_MONEY,
    MOVE_BACK,
    GO_TO_JAIL,
    GET_OUT_OF_JAIL,
    PROPERTY_REPAIRS,
    PAY_PLAYERS
}

struct Card {
    std::string description;
    CardType type;
    int value;
}

class Deck {
private:
    std::stack<Card> chanceDeck;
    std::stack<Card> communityChestDeck;

public:
    Deck();
    void shuffleDecks();
    std::string drawChanceCard();
    std::string drawCommunityChestCard();
}

#endif