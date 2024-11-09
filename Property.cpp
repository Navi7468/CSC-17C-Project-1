#include "Property.h"
#include "Player.h"
#include <iostream>

// Default constructor
Property::Property()
    : owner(nullptr), name(""), position(0), houses(0), hasHotel(false), cost(0), baseRent(0),
      rentColorSet(0), rent1House(0), rent2Houses(0), rent3Houses(0), rent4Houses(0), rentHotel(0),
      housePrice(0), hotelPrice(0), mortgageValue(0), colorGroup(""), type(PropertyType::PROPERTY), mortgaged(false) {
}

// Constructor with position and colorGroup
Property::Property(int position, const PropertyType type, Player *owner, const std::string &name, int cost, int baseRent,
                   int rentColorSet, int rent1House, int rent2Houses, int rent3Houses, int rent4Houses, int rentHotel,
                   int housePrice, int hotelPrice, int mortgageValue, const std::string &colorGroup)
    : position(position), type(type), owner(owner), name(name), houses(0), hasHotel(false), cost(cost), baseRent(baseRent),
      rentColorSet(rentColorSet), rent1House(rent1House), rent2Houses(rent2Houses), rent3Houses(rent3Houses), rent4Houses(rent4Houses),
      rentHotel(rentHotel), housePrice(housePrice), hotelPrice(hotelPrice), mortgageValue(mortgageValue), colorGroup(colorGroup), mortgaged(false) {
}

// Constructor
Property::Property(
    const std::string& name,
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
    PropertyType type
) : name(name), cost(cost), baseRent(baseRent), rentColorSet(rentColorSet), rent1House(rent1House),
    rent2Houses(rent2Houses), rent3Houses(rent3Houses), rent4Houses(rent4Houses), rentHotel(rentHotel),
    housePrice(housePrice), hotelPrice(hotelPrice), mortgageValue(mortgageValue), type(type), mortgaged(false) {
}

// Ownership and purchase methods
bool Property::isOwned() const {
    return owner != nullptr;
}

void Property::setOwner(Player* newOwner) {
    owner = newOwner;
}

Player* Property::getOwner() const {
    return owner;
}

// Rent calculation based on development
int Property::calculateRent() const {
    if (mortgaged) {
        return 0;  // No rent if the property is mortgaged
    }
    if (hasHotel) {
        return rentHotel;
    }
    switch (houses) {
        case 0: return owner && owner->ownsColorGroup(colorGroup) ? rentColorSet : baseRent;
        case 1: return rent1House;
        case 2: return rent2Houses;
        case 3: return rent3Houses;
        case 4: return rent4Houses;
        default: return baseRent;
    }
}

// Building management
void Property::addHouse() {
    if (houses < 4 && !hasHotel) {
        houses++;
    } else if (houses == 4) {
        addHotel();
    }
}

void Property::addHotel() {
    if (houses == 4) {
        hasHotel = true;
        houses = 0;  // Reset houses to 0 if a hotel is added
    }
}

int Property::getHouseCount() const {
    return houses;
}

bool Property::hasHotelBuilding() const {
    return hasHotel;
}

// Mortgage management
void Property::mortgage() {
    if (!mortgaged && owner) {
        mortgaged = true;
        owner->receiveCash(mortgageValue);
    }
}

void Property::unmortgage() {
    if (mortgaged && owner) {
        int unmortgageCost = mortgageValue + mortgageValue / 10;  // 10% interest to unmortgage
        if (owner->payCash(unmortgageCost)) {
            mortgaged = false;
        } else {
            std::cout << owner->getName() << " doesn't have enough cash to unmortgage " << name << ".\n";
        }
    }
}

bool Property::isMortgaged() const {
    return mortgaged;
}

// Property info getters
std::string Property::getName() const {
    return name;
}

int Property::getCost() const {
    return cost;
}

int Property::getMortgageValue() const {
    return mortgageValue;
}

std::string Property::getColorGroup() const {
    return colorGroup;
}

PropertyType Property::getType() const {
    return type;
}
