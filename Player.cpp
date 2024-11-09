#include <iostream>
#include <functional>
#include "Player.h"
#include "Property.h"
#include "Deck.h"
#include "Game.h"

// Constructor
Player::Player(const std::string &name, int startingCash, Game *gameInstance)
    : name(name), cash(startingCash), position(0), inJail(false), jailTurns(0), doublesCount(0), gameInstance(gameInstance) {}

// Core gameplay methods
void Player::takeTurn(std::map<int, Property> &board, Deck &deck)
{

    // TODO - Refactor this method to use a dynamic menu system 
    if (inJail)
    {
        // Handle if the player is in jail
        jailTurns++;
        std::cout << name << " is in jail (Turn " << jailTurns << " in jail).\n";

        if (jailTurns == 3)
        {
            std::cout << name << " has been in jail for 3 turns and is now released.\n";
            releaseFromJail();
        }
        else
        {
            std::cout << "Would you like to roll for doubles or pay $50 to get out of jail? (r/p): ";
            char choice;
            std::cin >> choice;
            if (choice == 'r')
            {
                int roll = gameInstance->roleDice(this);
                if (doublesCount == 1)
                { // If they roll doubles, they get out of jail
                    std::cout << "You rolled doubles and are released from jail!\n";
                    releaseFromJail();
                }
                else
                {
                    std::cout << "You did not roll doubles.\n";
                }
            }
            else if (choice == 'p')
            {
                if (cash >= 50)
                {
                    cash -= 50;
                    releaseFromJail();
                }
                else
                {
                    std::cout << "You don't have enough money to pay to get out of jail.\n";
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }

    bool firstTurn = true;
    bool playerTurn = true;

    while (playerTurn)
    {
        displayInfo(firstTurn);

        // Dynamic option menu
        std::map<int, std::pair<std::string, std::function<void()>>> options;
        int optionIndex = 1;

        // TODO - Simplify this menu system
        // Add dynamic options based on the game state
        if (firstTurn)
        {
            options[optionIndex++] = {
                "Roll dice",
                [&]()
                {
                    int roll = gameInstance->roleDice(this);
                    if (doublesCount == 3) {
                        std::cout << "You rolled doubles three times in a row! Go to Jail!\n";
                        goToJail();
                        playerTurn = false;
                    } 
                    
                    position = (position + roll) % board.size();
                    Property &currentSpace = board[position];
                    std::cout << "You landed on " << currentSpace.getName() << ".\n";
                    handleSpace(currentSpace, deck);
                    firstTurn = false;
                }};
        }
        else if (doublesCount > 0)
        {
            options[optionIndex++] = {
                "Roll dice again",
                [&]()
                {
                    int roll = gameInstance->roleDice(this);
                    if (doublesCount == 3)
                    {
                        std::cout << "You rolled doubles three times in a row! Go to Jail!\n";
                        goToJail();
                        playerTurn = false;
                    }
                    position = (position + roll) % board.size();
                    Property &currentSpace = board[position];
                    std::cout << "You landed on " << currentSpace.getName() << ".\n";
                    handleSpace(currentSpace, deck);
                }};
        }
        else
        {
            options[optionIndex++] = {
                "End turn",
                [&]()
                {
                    std::cout << "Ending your turn.\n";
                    playerTurn = false;
                }};
        }

        options[optionIndex++] = {
            "Manage properties",
            [&]()
            {
                std::cout << "Managing properties...\n";
                manageProperties();
            }};

        options[optionIndex++] = {
            "Declare bankruptcy",
            [&]()
            {
                std::cout << "Are you sure you want to declare bankruptcy? (y/n): ";
                char confirm;
                std::cin >> confirm;
                if (confirm == 'y')
                {
                    declareBankruptcy();
                    playerTurn = false; // End the turn
                }
                else
                {
                    std::cout << "Bankruptcy cancelled.\n";
                }
            }};

        options[optionIndex++] = {
            "Display player info",
            [&]()
            {
                displayInfo();
            }};

        // Display the options 
        std::cout << "What would you like to do?" << std::endl;
        for (const auto &option : options)
        {
            std::cout << option.first << ". " << option.second.first << std::endl;
        }

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        auto it = options.find(choice);
        if (it != options.end())
        {
            // Execute the selected action
            it->second.second();
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }

        firstTurn = false;
    }
}

void Player::handleSpace(Property &space, Deck &deck)
{
    if (space.getType() == PropertyType::SPECIAL)
    {
        // TODO - Handle special spaces (Go, Jail, Tax etc.)
    }
    else if (space.getOwner() == nullptr)
    {
        // TODO - Unowned property logic
    }
    else if (space.getOwner() != this)
    {
        // TODO - Pay rent logic
    }
    else
    {
        std::cout << "You own this property.\n";
    }
}

void Player::buyProperty(Property &property)
{
    if (cash >= property.getCost() && !property.isOwned())
    {
        cash -= property.getCost();
        property.setOwner(this);
        ownedProperties.push_back(&property);
        std::cout << name << " bought " << property.getName() << " for $" << property.getCost() << std::endl;
    }
    else
    {
        std::cout << name << " doesn't have enough cash to buy " << property.getName() << " or it is already owned." << std::endl;
    }
}

void Player::payRent(Player &owner, int amount)
{
    if (cash >= amount)
    {
        cash -= amount;
        owner.receiveCash(amount);
        std::cout << name << " paid $" << amount << " in rent to " << owner.getName() << "." << std::endl;
    }
    else
    {
        std::cout << name << " does not have enough cash to pay rent." << std::endl;
    }
}

// Jail-related methods
void Player::goToJail()
{
    inJail = true;
    jailTurns = 3;
    position = 10;
    std::cout << name << " is sent to jail!" << std::endl;
}

void Player::releaseFromJail()
{
    inJail = false;
    jailTurns = 0;
    std::cout << name << " is released from jail!" << std::endl;
}

bool Player::isInJail() const
{
    return inJail;
}

// Card management
void Player::saveCard(const Card &card)
{
    savedCards.push(card);
    std::cout << name << " saved a card: " << card.description << std::endl;
}

bool Player::useSavedCard()
{
    if (!savedCards.empty())
    {
        savedCards.pop();
        std::cout << name << " used a saved card." << std::endl;
        return true;
    }
    return false;
}

// Cash management
void Player::receiveCash(int amount)
{
    cash += amount;
}

bool Player::payCash(int amount)
{
    if (cash >= amount)
    {
        cash -= amount;
        return true;
    }
    return false;
}

// Property management
bool Player::ownsColorGroup(const std::string &colorGroup) const
{
    int count = 0;
    for (const auto &property : ownedProperties)
    {
        if (property->getColorGroup() == colorGroup)
        {
            count++;
        }
    }
    return false; // TODO - Fix placeholder value
}

void Player::manageProperties()
{
    // TODO - Implement property management logic
}

// Bankruptcy
void Player::declareBankruptcy()
{
    // TODO - Implement bankruptcy logic
}

// Getters and setters
void Player::displayInfo(bool isFirstTurn) const
{
    std::string padding = "    "; // 4 space "padding"
    std::string turnText = name + "'s turn.";
    std::string cashLine = padding + "Cash: $" + std::to_string(cash) + padding;
    std::string positionLine = padding + "Position: " + gameInstance->getBoardSpaces().at(position).getName() + padding;

    // Calculate the maximum length of the lines
    int maxLength = std::max({turnText.length(), cashLine.length(), positionLine.length()});

    // Create dashLine of appropriate length
    std::string dashLine(maxLength, '-');

    if (isFirstTurn)
    {
        // Center turnText within the dashLine
        int totalPadding = maxLength - turnText.length();
        int leftPadding = totalPadding / 2;
        std::string centeredTurnText = std::string(leftPadding, ' ') + turnText;

        std::cout << std::endl;
        std::cout << centeredTurnText << std::endl; // Centered turnText
    }

    // Display player info
    std::cout << dashLine << std::endl;     // Matching dashLine
    std::cout << positionLine << std::endl; // Indented Position line
    std::cout << cashLine << std::endl;     // Indented Cash line
    std::cout << dashLine << std::endl;     // Matching dashLine
}

std::string Player::getName() const
{
    return name;
}

int Player::getCash() const
{
    return cash;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(int newPosition)
{
    position = newPosition;
}

void Player::resetDoublesCount()
{
    doublesCount = 0;
}

void Player::incrementDoublesCount()
{
    doublesCount++;
}

int Player::getDoublesCount() const
{
    return doublesCount;
}