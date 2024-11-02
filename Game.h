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

public:
    Game();
    void setupGame();
    void playerTurn();
    bool checkWinCondition();
    void declareWinner();

};

#endif