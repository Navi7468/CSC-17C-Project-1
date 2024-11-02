#include "Game.h"
#include <iostream>

Game::Game() {
    setupGame();
}

void Game::setupGame() {

}

void Game::playerTurn() {
    Player* currentPlayer = playerQueue.front();
    playerQueue.pop();

    currentPlayer->takeTurn(boardSpaces, deck);

    playerQueue.push(currentPlayer);
}

bool Game::checkWinCondition() {
    int activePlayers = 0;
    for (const auto& player : playerQueue) {
        if (player->cash > 0) activePlayers++;
    }
    return activePlayers == 1;
}

void Game::declareWinner() {
    std::cout << "The winner is " << playerQueue.front()->getName() << "!\n";
}