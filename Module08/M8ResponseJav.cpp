#include <iostream>
#include <cstdlib>
#include <ctime>

struct Player {
    std::string name;
    int attempts = 5;
};

struct Game {
    int secretNumber = rand() % 100 + 1;

    Game() { srand(time(0)); }

    bool isCorrectGuess(int guess) {
        return guess == secretNumber;
    }

    void giveHint(int guess) {
        std::cout << (guess < secretNumber ? "Higher!\n" : "Lower!\n");
    }
};

int main() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Player player { playerName };
    Game game;

    int guess;
    while (player.attempts > 0) {
        std::cout << "Guess the number (1-100): ";
        std::cin >> guess;

        if (game.isCorrectGuess(guess)) {
            std::cout << "Congratulations! You guessed the number!\n";
            return 0;
        } {
            game.giveHint(guess);
            player.attempts--;
            std::cout << "Attempts left: " << player.attempts << "\n";
        }
    }

    std::cout << "Out of attempts! Better luck next time!\n";
    return 0;
}