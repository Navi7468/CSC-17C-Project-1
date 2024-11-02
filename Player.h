#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include "Property.h"
#include "Deck.h"

class Player {
public:
    std::string name;
    int cash;
    int position;
    std::list<Property*> ownedProperties;

public:
    Player(const std::string& name, int startingCash);
    void takeTurn(std::map<int, Property>& board, Deck& deck);
    void buyProperty(Property& property);
    void payRent(Player& owner, int amout);
    std::string getName() const; 
}

#endif