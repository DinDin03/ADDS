#include "Human.h"
#include <iostream>

Human::Human(std::string name) : name(name) {}

Move* Human::makeMove() {
    std::string move;
    std::cout << "Enter move: ";
    std::cin >> move;

    if (move == "Rock") return new Rock();
    if (move == "Paper") return new Paper();
    if (move == "Scissors") return new Scissors();
    if (move == "Robot") return new Robot();
    if (move == "Monkey") return new Monkey();
    if (move == "Pirate") return new Pirate();
    if (move == "Ninja") return new Ninja();
    if (move == "Zombie") return new Zombie();

    return nullptr; // Invalid move
}

std::string Human::getName() {
    return name;
}
