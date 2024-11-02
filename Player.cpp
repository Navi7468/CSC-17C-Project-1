Player::Player(const std::string& name, int startingCash) : name(name), cash(startingCash), position(0) {}

void Player::takeTurn(std::map<int, Property>& board, Deck& deck) {

    Card chanceCard = deck.drawChanceCard();
    std::cout << name << " drew a Chance card: " << chanceCard.description << std::endl;

    switch (chanceCard.type) {
        case CardType::COLLECT_MONEY:
            
            break;
        case CardType::MOVE_TO_POSITION:
            
            break;
        case CardType::COLLECT_MONEY:
            
            break;
        case CardType::PAY_MONEY:
            
            break;
        case CardType::MOVE_BACK:
            
            break;
        case CardType::GO_TO_JAIL:
            
            break;
        case CardType::GET_OUT_OF_JAIL:
            
            break;
        case CardType::PROPERTY_REPAIRS:
            
            break;
        case CardType::PAY_PLAYERS:
            
            break;
    }

}

void Player::buyProperty(Property& property) {
    if (cash >= property.getCost()) {
        cash -= property.getCost();
        ownedProperties.push_back(&property);
        property.setOwner(this);
        std::cout << name << " bought " << property.name << " for $" << property.cost << ".\n";
    }
}

void Player::payRent(Player& owner, int amount) {
    if (cash >= amount) {
        cash -= amount;
        owner.cash += amount;
    }
}

std::string Player::getName() const { 
    return name; 
}