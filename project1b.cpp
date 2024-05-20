#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Response {
private:
    int correct;
    int incorrect;

public:
    Response(int correct, int incorrect) : correct(correct), incorrect(incorrect) {}

    int getCorrect() const {
        return correct;
    }

    int getIncorrect() const {
        return incorrect;
    }

    friend std::ostream& operator<<(std::ostream& os, const Response& response) {
        os << "(" << response.correct << ", " << response.incorrect << ")";
        return os;
    }
};

class Mastermind {
private:
    std::vector<int> secretCode;
    int n;
    int m;
public:
    Mastermind(int n = 5, int m = 10) : n(n), m(m) {
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            secretCode.push_back(rand() % m);
        }
    }

    void printSecretCode() const {
        for (int num : secretCode) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> humanGuess() {
        std::vector<int> guess;
        int temp;
        for (int i = 0; i < n; ++i) {
            std::cin >> temp;
            guess.push_back(temp);
        }
        return guess;
    }

    Response getResponse(const std::vector<int>& guess) {
        int correct = 0, incorrect = 0;
        std::vector<bool> secretChecked(n, false), guessChecked(n, false);


        for (int i = 0; i < n; ++i) {
            if (guess[i] == secretCode[i]) {
                correct++;
                secretChecked[i] = guessChecked[i] = true;
            }
        }


        for (int i = 0; i < n; ++i) {
            if (!guessChecked[i]) {
                for (int j = 0; j < n; ++j) {
                    if (!secretChecked[j] && guess[i] == secretCode[j]) {
                        incorrect++;
                        secretChecked[j] = true;
                        break;
                    }
                }
            }
        }

        return Response(correct, incorrect);
    }

    bool isSolved(const Response& response) {
        return response.getCorrect() == n;
    }

    void playGame() {
        int guessCount = 0;
        printSecretCode(); 

        while (guessCount < 10) {
            std::cout << "Enter your guess: ";
            std::vector<int> guess = humanGuess();
            Response response = getResponse(guess);
            std::cout << response << std::endl;

            if (isSolved(response)) {
                std::cout << "Congratulations! You've cracked the code!" << std::endl;
                return;
            }
            guessCount++;
        }

        std::cout << "Sorry, you didn't guess the code in 10 tries. You lose." << std::endl;
    }
};

int main() {
    Mastermind game;
    game.playGame();
    return 0;
}


