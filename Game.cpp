#include "Game.h"
#include "BoardData.h"
#include "Property.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <limits>

Game::Game()
{
    // Ask for number of players
    int numPlayers;
    do
    {
        std::cout << "Please enter the number of players (2-8): ";
        std::cin >> numPlayers;

        if (std::cin.fail() || numPlayers < 2 || numPlayers > 8)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. ";
        }
    } while (numPlayers < 2 || numPlayers > 8);

    // Ask for player names
    for (int i = 0; i < numPlayers; i++)
    {
        std::string name;
        std::cout << "Please enter the name of player " << i + 1 << ": ";
        std::cin >> name;

        Player *player = new Player(name, 1500, this);
        playerQueue.push(player);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    // Ask players to roll dice to determine order
    std::cout << "\nRolling dice to determine player order...\n";
    std::map<int, Player *> playerOrder;

    for (int i = 0; i < numPlayers; i++)
    {
        Player *currentPlayer = playerQueue.front();
        playerQueue.pop();

        std::cout << currentPlayer->getName() << ", ";
        int roll = roleDice(currentPlayer);
        std::cout << currentPlayer->getName() << " rolled a " << roll << ".\n";

        // Ensure unique keys in the map by adding a small offset if the roll is the same
        while (playerOrder.find(roll) != playerOrder.end())
        {
            roll++;
        }

        playerOrder[roll] = currentPlayer;
    }

    int order = 1;
    std::cout << "\nPlayer order is as follows:\n";
    for (auto it = playerOrder.rbegin(); it != playerOrder.rend(); ++it)
    {
        std::cout << order++ << ". " << it->second->getName() << std::endl;
        playerQueue.push(it->second);
    }
}

void Game::setupGame()
{
    // Use boardData to initialize boardSpaces with Property instances
    for (const auto &propertyInfo : boardData)
    {
        boardSpaces[propertyInfo.pos] = Property(
            propertyInfo.pos,
            propertyInfo.type,
            propertyInfo.owner,
            propertyInfo.name,
            propertyInfo.cost,
            propertyInfo.baseRent,
            propertyInfo.rentColorSet,
            propertyInfo.rent1House,
            propertyInfo.rent2Houses,
            propertyInfo.rent3Houses,
            propertyInfo.rent4Houses,
            propertyInfo.rentHotel,
            propertyInfo.housePrice,
            propertyInfo.hotelPrice,
            propertyInfo.mortgageValue,
            propertyInfo.colorGroup
        );
    }

    // Shuffle decks
    deck.shuffleDecks();
}

void Game::playerTurn()
{
    Player *currentPlayer = playerQueue.front();
    playerQueue.pop();

    currentPlayer->resetDoublesCount();
    currentPlayer->takeTurn(boardSpaces, deck);

    playerQueue.push(currentPlayer);
}

int Game::roleDice(Player *currentPlayer)
{
    std::cout << "Press Enter to roll dice...";
    std::cin.get();

    // Roll two dice
    // int die1 = 5; // DEBUG - Force a specific roll
    // int die2 = 5; // DEBUG - Force a specific roll
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int roll = die1 + die2;

    std::cout << "You rolled a " << die1 << " and a " << die2 << ". Total: " << roll << std::endl;

    if (die1 == die2)
    {
        currentPlayer->incrementDoublesCount();
        std::cout << "You rolled doubles! You get to roll again." << std::endl;
    }

    return roll;
}

void Game::handlePayOtherPlayers(Player *currentPlayer, int amount)
{
    std::queue<Player *> tempQueue = playerQueue;

    while (!tempQueue.empty())
    {
        Player *playerPtr = tempQueue.front();
        tempQueue.pop();

        if (playerPtr != currentPlayer)
        { // Avoid paying oneself
            currentPlayer->payCash(amount);
            playerPtr->receiveCash(amount);
            std::cout << currentPlayer->getName() << " pays $" << amount << " to " << playerPtr->getName() << ".\n";
        }
    }
}

bool Game::checkWinCondition()
{
    int activePlayers = 0;
    std::queue<Player *> tempQueue = playerQueue;

    while (!tempQueue.empty())
    {
        Player *player = tempQueue.front();
        tempQueue.pop();

        if (player->getCash() > 0)
            activePlayers++;
    }

    return activePlayers == 1;
}

void Game::declareWinner()
{
    std::cout << "The winner is " << playerQueue.front()->getName() << "!\n";
}

const std::map<int, Property>& Game::getBoardSpaces() const {
    return boardSpaces;
}