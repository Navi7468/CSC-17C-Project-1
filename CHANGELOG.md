# Change Log

## [0.0.1](https://github.com/Navi7468/CSC-17C-Project-1/commit/b83911cca3ba60d1860f367f55520ed93f425b93) - Nov 2, 2024

### Initial Commit

Created Initial Commit of Game

#### Added

- **main.cpp**
  - Initial setup with includes for core components and standard libraries. Serves as the program's entry point.
- **Deck.cpp**
  - Implemented card shuffling and drawing mechanics for Chance and Community Chest decks.
- **Deck.h**
  - Defined the `Card` structure and `Deck` class with methods for shuffling and drawing cards.
- **Game.cpp**
  - Implemented game setup, player turn handling, win condition checks, and winner declaration.
- **Game.h**
  - Declared the `Game` class with methods for game setup, player turns, win condition checks, and winner declaration.
- **Player.cpp**
  - Implemented player actions, including taking turns, buying properties, and paying rent.
- **Player.h**
  - Declared the `Player` class with attributes for name, cash, position, and owned properties, as well as methods for taking turns, buying properties, paying rent, and retrieving the player's name.
- **Property.cpp**
  - Implemented property initialization, rent calculation, and ownership management.
- **Property.h**
  - Declared the `Property` class with attributes for name, cost, rent, and owner, along with methods for rent calculation and ownership management.

---

## [0.0.2]() - Nov 8, 2024 | (Not Commited Until Nov 9, 2024)

### Enhancements and Expanded Functionality

Expanded the game functionality with board data, player interactions, and enhanced gameplay mechanics.

#### Added

- **BoardData.h**
  - Defined `PropertyType` and `PropertyInfo` structures to represent board properties.
  - Initialized the game board with data for all spaces, including properties, railroads, utilities, and special spaces.

#### Changed

- **main.cpp**
  - Added the game loop setup to process player turns and declare the winner.
  - Implemented random number seeding for consistent game behavior.
- **Deck.h**
  - Reordered `CardType` enumeration and added comments for clarity.
- **Game.cpp**
  - Enhanced the game setup process with prompts for player count and names.
  - Introduced dice rolling mechanics to determine player order and handle doubles.
  - Added functionality to initialize board spaces using `BoardData.h`.
  - Updated `playerTurn` to handle player actions and doubles rolls.
  - Added a method to manage payments between players.
  - Improved win condition checks to account for player bankruptcy.
  - Implemented a getter for board spaces (`getBoardSpaces`).
- **Game.h**
  - Added `handlePayOtherPlayers` to manage payments between players.
  - Added `roleDice` to handle dice rolling for players.
  - Introduced a getter for board spaces (`getBoardSpaces`).
- **Player.cpp**
  - Added jail mechanics, including methods for handling jail turns and release.
  - Implemented dynamic menus for actions like property management and bankruptcy.
  - Added utilities for saving and using cards (`saveCard`, `useSavedCard`).
  - Enhanced cash and property management methods (`receiveCash`, `payCash`, `manageProperties`).
  - Improved turn mechanics with doubles roll tracking and player bankruptcy handling.
  - Enhanced getter and setter methods for player attributes.
- **Player.h**
  - Refactored player attributes for encapsulation.
  - Added methods and attributes for jail mechanics, card management, and property handling.
  - Enhanced gameplay logic with doubles roll tracking and bankruptcy handling.
  - Added dynamic menu support with `initializeMenu`.
- **Property.cpp**
  - Added detailed constructors to support various initialization needs.
  - Enhanced rent calculation to account for property development and mortgage status.
  - Added building management methods (`addHouse`, `addHotel`).
  - Implemented mortgage management with interest calculations for unmortgaging.
  - Introduced getters for key property details.
- **Property.h**
  - Refactored property attributes to improve encapsulation.
  - Added constructors for various initialization scenarios.
  - Enhanced building and mortgage management methods.
  - Improved getters for property details to align with board representation.

#### TODOs

- **Game.cpp**
  - Implement player input handling for dynamic gameplay options.

---