#include "Deck.h"

template <size_t N>
void shuffleArray(std::array<std::string, N>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
}

Deck::Deck() {
    shuffleDecks();
}

void Deck::shuffleDecks() {
    std::array<Card, 15> chanceCards = { 
        Card{"Advance to Boardwalk", CardType::MOVE_TO_POSITION, 39},
        Card{"Advance to Go (Collect $200)", CardType::MOVE_TO_POSITION, 0},
        Card{"Advance to Illinois Avenue. If you pass Go, collect $200", CardType::MOVE_TO_POSITION, 24},
        Card{"Advance to St. Charles Place. If you pass Go, collect $200", CardType::MOVE_TO_POSITION, 11},
        Card{"Advance to the nearest Railroad", CardType::MOVE_TO_POSITION, -1},
        Card{"Advance token to nearest Utility", CardType::MOVE_TO_POSITION, -1},
        Card{"Bank pays you dividend of $50", CardType::COLLECT_MONEY, 50},
        Card{"Get Out of Jail Free", CardType::GET_OUT_OF_JAIL, 0},
        Card{"Go Back 3 Spaces", CardType::MOVE_BACK, 3},
        Card{"Go to Jail. Go directly to Jail, do not pass Go, do not collect $200", CardType::GO_TO_JAIL, 10},
        Card{"Make general repairs on all your property", CardType::PROPERTY_REPAIRS, -1},
        Card{"Speeding fine $15", CardType::PAY_MONEY, 15},
        Card{"Take a trip to Reading Railroad. If you pass Go, collect $200", CardType::MOVE_TO_POSITION, 5},
        Card{"You have been elected Chairman of the Board. Pay each player $50", CardType::PAY_PLAYERS, 50},
        Card{"Your building loan matures. Collect $150", CardType::COLLECT_MONEY, 150}
    };
    std::array<Card, 16> communityChestCards = {
        Card{"Advance to Go (Collect $200)", CardType::MOVE_TO_POSITION, 0},
        Card{"Bank error in your favor. Collect $200", CardType::COLLECT_MONEY, 200},
        Card{"Doctor’s fee. Pay $50", CardType::PAY_MONEY, 50},
        Card{"From sale of stock you get $50", CardType::COLLECT_MONEY, 50},
        Card{"Get Out of Jail Free", CardType::GET_OUT_OF_JAIL, 0},
        Card{"Go to Jail. Go directly to jail, do not pass Go, do not collect $200", CardType::GO_TO_JAIL, 10},
        Card{"Holiday fund matures. Receive $100", CardType::COLLECT_MONEY, 100},
        Card{"Income tax refund. Collect $20", CardType::COLLECT_MONEY, 20},
        Card{"It is your birthday. Collect $10 from every player", CardType::COLLECT_MONEY, 10},
        Card{"Life insurance matures. Collect $100", CardType::COLLECT_MONEY, 100},
        Card{"Pay hospital fees of $100", CardType::PAY_MONEY, 100},
        Card{"Pay school fees of $50", CardType::PAY_MONEY, 50},
        Card{"Receive $25 consultancy fee", CardType::COLLECT_MONEY, 25},
        Card{"You are assessed for street repair. $40 per house. $115 per hotel", CardType::PROPERTY_REPAIRS, -1},
        Card{"You have won second prize in a beauty contest. Collect $10", CardType::COLLECT_MONEY, 10},
        Card{"You inherit $100", CardType::COLLECT_MONEY, 100}
    };

    shuffleArray(chanceCards);
    shuffleArray(communityChestCards);

    for (const auto& card : chanceCards) {
        chanceDeck.push(card);
    }
    for (const auto& card : communityChestCards) {
        communityChestDeck.push(card);
    }
}

Card Deck::drawChanceCard() {
    if (chanceDeck.empty()) return Card{"No more Chance cards.", CardType::COLLECT_MONEY, 0};
    Card card = chanceDeck.top();
    chanceDeck.pop()
    return card;
}

Card Deck::drawCommunityChestCard() {
    if (communityChestDeck.empty()) return Card{"No more Community Chest cards.", CardType::COLLECT_MONEY, 0};
    Card card = communityChestDeck.top();
    communityChestDeck.pop();
    return card;
}