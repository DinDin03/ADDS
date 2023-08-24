#include "Referee.h"
#include "Move.h"
#include <iostream>

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    if (!move1 || !move2) {
        // Invalid move(s), return nullptr
        delete move1;
        delete move2;
        return nullptr;
    }

    // Display the chosen moves
    std::cout << player1->getName() << " chose " << move1->getName() << std::endl;
    std::cout << player2->getName() << " chose " << move2->getName() << std::endl;

    // Compare moves to determine the winner
    if (move1->getName() == move2->getName()) {
        delete move1;
        delete move2;
        return nullptr; // It's a tie
    } else if (
        (move1->getName() == "Rock" && (move2->getName() == "Scissors" || move2->getName() == "Monkey")) ||
        (move1->getName() == "Paper" && (move2->getName() == "Rock" || move2->getName() == "Pirate")) ||
        (move1->getName() == "Scissors" && (move2->getName() == "Paper" || move2->getName() == "Zombie")) ||
        (move1->getName() == "Monkey" && (move2->getName() == "Pirate" || move2->getName() == "Ninja")) ||
        (move1->getName() == "Robot" && (move2->getName() == "Monkey" || move2->getName() == "Pirate")) ||
        (move1->getName() == "Pirate" && (move2->getName() == "Zombie" || move2->getName() == "Robot")) ||
        (move1->getName() == "Ninja" && (move2->getName() == "Zombie" || move2->getName() == "Paper")) ||
        (move1->getName() == "Zombie" && (move2->getName() == "Rock" || move2->getName() == "Scissors"))
    ) {
        delete move1;
        delete move2;
        return player1; // Player 1 wins
    } else {
        delete move1;
        delete move2;
        return player2; // Player 2 wins
    }
}
