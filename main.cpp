#include <iostream>
#include <vector>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    std::vector<Player*> players;

    // Add players to the vector
    players.push_back(new Human("Mei"));
    players.push_back(new Computer());
    // Add more players as needed

    // Create the referee
    Referee referee;

    // Play the game for all players
    for (size_t i = 0; i < players.size(); ++i) {
        for (size_t j = i + 1; j < players.size(); ++j) {
            Player* player1 = players[i];
            Player* player2 = players[j];

            // Play the game and get the winner
            Player* winner = referee.refGame(player1, player2);

            // Check for a winner and display the result
            if (!winner) {
                std::cout << "It's a Tie!" << std::endl;
            } else {
                std::cout << winner->getName() << " Wins!" << std::endl;
            }
        }
    }

    // Clean up allocated memory
    for (Player* player : players) {
        delete player;
    }

    return 0;
}
