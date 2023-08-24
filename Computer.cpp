#include "Computer.h"

Computer::Computer() : name("Computer") {}

char Computer::makeMove() {
    return 'R'; // Computer always plays Rock
}

std::string Computer::getName() {
    return name;
}
