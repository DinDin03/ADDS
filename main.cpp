#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Player* player1 = new Human("Mei");
    Player* player2 = new Computer();

    Referee referee;

    char move1 = player1->makeMove();
    char move2 = player2->makeMove();

    std::cout << "Player 1 (" << player1->getName() << ") chose: " << move1 << std::endl;
    std::cout << "Player 2 (" << player2->getName() << ") chose: " << move2 << std::endl;

    Player* winner = referee.refGame(player1, player2);

    if (winner == nullptr) {
        std::cout << "It's a Tie!" << std::endl;
    } else {
        std::cout << winner->getName() << " Wins!" << std::endl;
    }

    delete player1;
    delete player2;

    return 0;
}
