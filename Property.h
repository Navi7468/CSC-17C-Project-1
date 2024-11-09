#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "BoardData.h"

class Player;

class Property
{
private:
    int position;
    PropertyType type;
    Player *owner;
    std::string name;
    int houses;
    bool hasHotel;
    int cost;
    int baseRent;
    int rentColorSet;
    int rent1House;
    int rent2Houses;
    int rent3Houses;
    int rent4Houses;
    int rentHotel;
    int housePrice;
    int hotelPrice;
    int mortgageValue;
    std::string colorGroup;
    bool mortgaged;

public:
    // Constructor
    Property();
    Property(int position, const PropertyType type, Player *owner, const std::string &name, int cost, int baseRent,
             int rentColorSet, int rent1House, int rent2Houses, int rent3Houses, int rent4Houses, int rentHotel,
             int housePrice, int hotelPrice, int mortgageValue, const std::string &colorGroup);

    Property(
        const std::string &name,
        int cost,
        int baseRent,
        int rentColorSet,
        int rent1House,
        int rent2Houses,
        int rent3Houses,
        int rent4Houses,
        int rentHotel,
        int housePrice,
        int hotelPrice,
        int mortgageValue,
        PropertyType type);

    // Ownership and purchase
    bool isOwned() const;
    void setOwner(Player *newOwner);
    Player *getOwner() const;

    // Rent calculation
    int calculateRent() const;

    // Building management
    void addHouse();
    void addHotel();
    int getHouseCount() const;
    bool hasHotelBuilding() const;

    // Property info getters
    std::string getName() const;
    int getCost() const;
    int getMortgageValue() const;
    std::string getColorGroup() const;
    PropertyType getType() const;

    // Mortgage management
    void mortgage();
    void unmortgage();
    bool isMortgaged() const;
};

#endif
