#include "Computer.h"
#include <cstdlib> // For rand
#include <ctime>   // For seeding rand

Computer::Computer() : name("Computer") {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

Move* Computer::makeMove() {
    int randomMove = std::rand() % 8; // Generates a random number between 0 and 7

    switch (randomMove) {
        case 0: return new Rock();
        case 1: return new Paper();
        case 2: return new Scissors();
        case 3: return new Robot();
        case 4: return new Monkey();
        case 5: return new Pirate();
        case 6: return new Ninja();
        case 7: return new Zombie();
    }

    return nullptr; // Invalid move
}

std::string Computer::getName() {
    return name;
}
