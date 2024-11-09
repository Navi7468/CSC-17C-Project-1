#ifndef BOARD_DATA_H
#define BOARD_DATA_H

#include <string>

class Player;

enum class PropertyType {
    PROPERTY,
    RAILROAD,
    UTILITY,
    SPECIAL
};

struct PropertyInfo {
    int pos;
    PropertyType type;
    Player* owner;
    std::string name;
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
};

// Information for each space on the board
const PropertyInfo boardData[] = {
    {0, PropertyType::SPECIAL, nullptr, "Go", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {1, PropertyType::PROPERTY, nullptr, "Mediterranean Avenue", 60, 2, 4, 10, 30, 90, 160, 250, 50, 50, 30, "brown"},
    {2, PropertyType::SPECIAL, nullptr, "Community Chest", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {3, PropertyType::PROPERTY, nullptr, "Baltic Avenue", 60, 4, 8, 20, 60, 180, 320, 450, 50, 50, 30, "brown"},
    {4, PropertyType::SPECIAL, nullptr, "Income Tax", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {5, PropertyType::RAILROAD, nullptr, "Reading Railroad", 200, 25, 50, 100, 200, 0, 0, 0, 100, 100, 0, "railroad"},
    {6, PropertyType::PROPERTY, nullptr, "Oriental Avenue", 100, 6, 12, 30, 90, 270, 400, 550, 50, 50, 50, "light-blue"},
    {7, PropertyType::SPECIAL, nullptr, "Chance", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {8, PropertyType::PROPERTY, nullptr, "Vermont Avenue", 100, 6, 12, 30, 90, 270, 400, 550, 50, 50, 50, "light-blue"},
    {9, PropertyType::PROPERTY, nullptr, "Connecticut Avenue", 120, 8, 16, 40, 100, 300, 450, 600, 50, 50, 60, "light-blue"},
    {10, PropertyType::SPECIAL, nullptr, "Jail (Just Visiting)", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {11, PropertyType::PROPERTY, nullptr, "St. Charles Place", 140, 10, 20, 50, 150, 450, 625, 750, 100, 100, 70, "magenta"},
    {12, PropertyType::UTILITY, nullptr, "Electric Company", 150, 0, 0, 0, 0, 0, 0, 0, 75, 75, 0, "utility"},
    {13, PropertyType::PROPERTY, nullptr, "States Avenue", 140, 10, 20, 50, 150, 450, 625, 750, 100, 100, 70, "magenta"},
    {14, PropertyType::PROPERTY, nullptr, "Virginia Avenue", 160, 12, 24, 60, 180, 500, 700, 900, 100, 100, 80, "magenta"},
    {15, PropertyType::RAILROAD, nullptr, "Pennsylvania Railroad", 200, 25, 50, 100, 200, 0, 0, 0, 100, 100, 0, "railroad"},
    {16, PropertyType::PROPERTY, nullptr, "St. James Place", 180, 14, 28, 70, 200, 550, 750, 950, 100, 100, 90, "orange"},
    {17, PropertyType::SPECIAL, nullptr, "Community Chest", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {18, PropertyType::PROPERTY, nullptr, "Tennessee Avenue", 180, 14, 28, 70, 200, 550, 750, 950, 100, 100, 90, "orange"},
    {19, PropertyType::PROPERTY, nullptr, "New York Avenue", 200, 16, 32, 80, 220, 600, 800, 1000, 100, 100, 100, "orange"},
    {20, PropertyType::SPECIAL, nullptr, "Free Parking", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {21, PropertyType::PROPERTY, nullptr, "Kentucky Avenue", 220, 18, 36, 90, 250, 700, 875, 1050, 150, 150, 110, "red"},
    {22, PropertyType::SPECIAL, nullptr, "Chance", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {23, PropertyType::PROPERTY, nullptr, "Indiana Avenue", 220, 18, 36, 90, 250, 700, 875, 1050, 150, 150, 110, "red"},
    {24, PropertyType::PROPERTY, nullptr, "Illinois Avenue", 240, 20, 40, 100, 300, 750, 925, 1100, 150, 150, 120, "red"},
    {25, PropertyType::RAILROAD, nullptr, "B. & O. Railroad", 200, 25, 50, 100, 200, 0, 0, 0, 100, 100, 0, "railroad"},
    {26, PropertyType::PROPERTY, nullptr, "Atlantic Avenue", 260, 22, 44, 110, 330, 800, 975, 1150, 150, 150, 130, "yellow"},
    {27, PropertyType::PROPERTY, nullptr, "Ventnor Avenue", 260, 22, 44, 110, 330, 800, 975, 1150, 150, 150, 130, "yellow"},
    {28, PropertyType::UTILITY, nullptr, "Water Works", 150, 0, 0, 0, 0, 0, 0, 0, 75, 75, 0, "utility"},
    {29, PropertyType::PROPERTY, nullptr, "Marvin Gardens", 280, 24, 48, 120, 360, 850, 1025, 1200, 150, 150, 140, "yellow"},
    {30, PropertyType::SPECIAL, nullptr, "Go to Jail", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {31, PropertyType::PROPERTY, nullptr, "Pacific Avenue", 300, 26, 52, 130, 390, 900, 1100, 1275, 200, 200, 150, "green"},
    {32, PropertyType::PROPERTY, nullptr, "North Carolina Avenue", 300, 26, 52, 130, 390, 900, 1100, 1275, 200, 200, 150, "green"},
    {33, PropertyType::SPECIAL, nullptr, "Community Chest", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {34, PropertyType::PROPERTY, nullptr, "Pennsylvania Avenue", 320, 28, 56, 150, 450, 1000, 1200, 1400, 200, 200, 160, "green"},
    {35, PropertyType::RAILROAD, nullptr, "Short Line", 200, 25, 50, 100, 200, 0, 0, 0, 100, 100, 0, "railroad"},
    {36, PropertyType::SPECIAL, nullptr, "Chance", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {37, PropertyType::PROPERTY, nullptr, "Park Place", 350, 35, 70, 175, 500, 1100, 1300, 1500, 200, 200, 175, "blue"},
    {38, PropertyType::SPECIAL, nullptr, "Luxury Tax", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""},
    {39, PropertyType::PROPERTY, nullptr, "Boardwalk", 400, 50, 100, 200, 600, 1400, 1700, 2000, 200, 200, 200, "blue"},
    {40, PropertyType::SPECIAL, nullptr, "Jail", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""}
};

#endif
