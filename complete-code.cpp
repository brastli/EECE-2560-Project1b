// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 1
// File contains functions for humanGuess, isSolved, getResponse, playGame
// 


#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Class representing the response for a guess
class Response {
private:
    int correct;    // Number of correct guesses in the correct position
    int incorrect;  // Number of correct guesses in the incorrect position

public:
    // Constructor initializing the response with correct and incorrect counts
    Response(int correct, int incorrect) : correct(correct), incorrect(incorrect) {}

    // Method to get the number of correct guesses
    int checkCorrect() const {
        return correct;
    }

    // Method to get the number of incorrect guesses
    int checkIncorrect() const {
        return incorrect;
    }

    // Overloading the << operator for easy printing of the response
    friend ostream& operator<<(ostream& os, const Response& response) {
        os << "(" << response.correct << ", " << response.incorrect << ")";
        return os;
    }
};

// Class representing the Mastermind game
class Mastermind {
private:
    vector<int> secretCode; // The secret code to be guessed
    int n;                  // Length of the secret code
    int m;                  // Range of values in the secret code

public:
    // Constructor initializing the game with code length n and range m
    Mastermind(int n = 5, int m = 10) : n(n), m(m) {
        srand(time(0)); // Seed the random number generator
        for (int i = 0; i < n; ++i) {
            secretCode.push_back(rand() % m); // Generate random secret code
        }
    }

    // Method to print the secret code (for debugging)
    void printSecretCode() const {
        for (int num : secretCode) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Method to get a guess from the user
    vector<int> humanGuess() {
        vector<int> guess;
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            guess.push_back(temp); // Read user's guess
        }
        return guess;
    }

    // Method to compare the guess to the secret code and generate a response
    Response getResponse(const vector<int>& guess) {
        int correct = 0, incorrect = 0;
        vector<bool> secretChecked(n, false), guessChecked(n, false);

        // Check for correct positions
        for (int i = 0; i < n; ++i) {
            if (guess[i] == secretCode[i]) {
                correct++;
                secretChecked[i] = guessChecked[i] = true;
            }
        }

        // Check for correct numbers in incorrect positions
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

        // Return the response
        return Response(correct, incorrect);
    }

    // Method to check if the game is solved
    bool isSolved(const Response& response) {
        return response.checkCorrect() == n;
    }

    // Method to play the game
    void playGame() {
        int guessCount = 0;
        printSecretCode(); // Print secret code for debugging

        // Allow up to 10 guesses
        while (guessCount < 10) {
            cout << "Enter your guess: ";
            vector<int> guess = humanGuess(); // Get user's guess
            Response response = getResponse(guess); // Get response for the guess
            cout << response << endl; // Print the response

            // Check if the game is solved
            if (isSolved(response)) {
                cout << "Congratulations! You've cracked the code!" << endl;
                return;
            }
            guessCount++;
        }

        // If the user fails to guess in 10 tries
        cout << "Sorry, you didn't guess the code in 10 tries. You lose." << endl;
    }
};

int main() {
    Mastermind game; // Create a Mastermind game instance
    game.playGame(); // Start the game
    return 0;
}
