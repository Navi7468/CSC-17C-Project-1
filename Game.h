#ifndef GAME_H
#define GAME_H

#include <queue>
#include <map>
#include "Player.h"
#include "Property.h"
#include "Deck.h"

class Game {
private:
    std::queue<Player*> playerQueue;
    std::map<int, Property> boardSpaces;
    Deck deck;

    void handlePayOtherPlayers(Player* currentPlayer, int amount);

public:
    // Constructor
    Game();

    // Core gameplay methods
    void setupGame();
    void playerTurn();
    int roleDice(Player* currentPlayer);

    // Win condition methods
    bool checkWinCondition();
    void declareWinner();

    // Getter for boardSpaces
    const std::map<int, Property>& getBoardSpaces() const;
};

#endif
