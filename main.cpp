#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Player* player1 = new Human("Mei");
    Player* player2 = new Computer();

    Referee referee;

    Player* winner = referee.refGame(player1, player2);

    if (!winner) {
        std::cout << "It's a Tie!" << std::endl;
    } else {
        std::cout << winner->getName() << " Wins!" << std::endl;
    }

    delete player1;
    delete player2;

    return 0;
}
