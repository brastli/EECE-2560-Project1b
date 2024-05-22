// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 1
// Main program file for project 1

#include <iostream>
#include <vector>
#include "Code.h"

using namespace std;

int main() {
        int n = 5;
    int m = 7;

    // Generates a secret code randomly
    Code code(n, m);
    code.generateCode();

    // Prints the secret code
    cout << "Secret code: ";
    code.printCode();

    // Initializes three sample vectors
    vector<vector<int>> sample_guesses = {{5, 0, 3, 2, 6}, {2, 1, 2, 2, 2}, {1, 3, 3, 4, 5}};

    // Loops through the sample guess vector and creates a new code object for each one, comparing each to the code
    for(const auto& guess_values : sample_guesses)
    {
        Code guess(n, m);
        guess.setInput(guess, guess_values);
        cout << "R: " << code.checkCorrect(guess) << ", " << code.checkIncorrect(guess) << endl;
    }
    
    Mastermind game;
    game.playGame();
    return 0;
}


