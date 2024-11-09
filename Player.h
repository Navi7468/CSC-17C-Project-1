#ifndef PLAYER_H
#define PLAYER_H

#include "Property.h"
#include "Deck.h"
#include <map>
#include <string>
#include <list>
#include <stack>
#include <functional>

class Game;

class Player {
private:
    std::string name;
    int cash;
    int position;
    bool inJail;
    int jailTurns;
    int doublesCount;
    std::list<Property*> ownedProperties;
    std::stack<Card> savedCards;
    Game* gameInstance;

    void initializeMenu(std::map<int, std::function<void()>>& options, bool isFirstTurn, std::map<int, Property>& board, Deck& deck);
    void handleSpace(Property& space, Deck& deck);

public:
    // Constructor
    Player(const std::string& name, int startingCash, Game* gameInstance);

    // Core gameplay methods
    void takeTurn(std::map<int, Property>& board, Deck& deck);
    void buyProperty(Property& property);
    void payRent(Player& owner, int amount);

    // Jail-related methods
    void goToJail();
    void releaseFromJail();
    bool isInJail() const;

    // Card management
    void saveCard(const Card& card);
    bool useSavedCard();

    // Cash management
    void receiveCash(int amount);
    bool payCash(int amount);

    // Property management
    bool ownsColorGroup(const std::string& colorGroup) const;
    void manageProperties();

    // Bankruptcy
    void declareBankruptcy();

    // Display info
    void displayInfo(bool isFirstTurn = false) const;

    // Getters and setters
    std::string getName() const;
    int getCash() const;
    int getPosition() const;
    void setPosition(int newPosition);

    // Accessors and mutators for doubles count
    void resetDoublesCount();
    void incrementDoublesCount();
    int getDoublesCount() const;
};

#endif
