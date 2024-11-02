#include "Property.h"

Property::Property(const std::string& name, int cost, int rent) : name(name), cost(cost), rent(rent), owner(nullptr) {}

int Property::calculateRent() const { return rent; }

void Property::setOwner(Player* newOwner) {
    owner = newOwner;
}