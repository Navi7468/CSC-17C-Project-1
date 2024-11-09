#include "Game.h"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Game monopolyGame;
    monopolyGame.setupGame();

    // Start game loop
    while (!monopolyGame.checkWinCondition())
    {
        monopolyGame.playerTurn();
        
        break; // DELETE - For testing purposes (only one turn)
    }
    monopolyGame.declareWinner();

    return 0;
}