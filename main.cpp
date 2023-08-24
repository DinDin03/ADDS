#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Player* player1 = new Human("Mei");
    Player* player2 = new Computer();

    Referee referee;

    // Get the moves from the players
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    // Display the chosen moves
    std::cout << player1->getName() << " chose " << move1->getName() << std::endl;
    std::cout << "Computer chose " << move2->getName() << std::endl;

    Player* winner = referee.refGame(player1, player2);

    if (!winner) {
        std::cout << "It's a Tie!" << std::endl;
    } else {
        std::cout << winner->getName() << " Wins!" << std::endl;
    }

    // Clean up memory
    delete player1;
    delete player2;
    delete move1; // Don't forget to delete the moves
    delete move2;

    return 0;
}
