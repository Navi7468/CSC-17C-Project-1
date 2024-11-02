#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

class Player;

class Property {
public:
    std::string name;
    int cost;
    int rent;
    Player* owner;

    Property(const std::string& name, int cost, int rent);
    int calculateRent() const;
    void setOwner(Player* newOwner);
}

#endif