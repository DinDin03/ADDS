#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
public:
    Computer();
    Move* makeMove() override;
    std::string getName() override;

private:
    std::string name;
};

#endif // COMPUTER_H
