// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 1
// File contains functions for generateCode, printCode, setInput, checkCorrect
// and checkIncorrect

#include "Code.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

Code::Code(int n, int m) : n(n), m(m), code(n) {}

void Code::generateCode()
// Generates a random integer in the range [0, m - 1] for each index of the code
// vector with length n and assigns each index of the code
{
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        code[i] = rand() % m;
    }
}

void Code::printCode()
// Prints the secret code
{
    // Iterates through each index of the code
    for (int i = 0; i < n; i++)
    {
        // Ouputs each element of the code
        cout << code[i];
    }
    cout << endl;
}

void Code::setInput(Code& guess, vector<int> guesses)
// Takes a vector and sets the guess code object by index
{
    // Iterates through each index of the guess code
    for (int i = 0; i < n; i++)
    {
        // Sets the guess code object at each index
        guess.code[i] = guesses[i];
    }
}

int Code::checkCorrect(Code& guess)
// Takes a code object. Checks how many digits of the guess are in the same 
// location as the code. Assumes input is the correct length
{
    // Initalize count object to track number of matches
    int count = 0;

    // Iterates through the vectors and compares the values at each index,
    // incrementing count by 1 for each match

    for (int i = 0; i < n; i++)
    {
        // Check if code is the same at guess code at each index
        if (code[i] == guess.code[i])
        {
            // Increases number of matches found
            count++;
        }
    }
    return count;
}

int Code::checkIncorrect(Code& guess)
// Takes a code object. Checks how many digits of the guess are in the incorrect 
// location of the code without repeating digits. Assumes input is expected length
{
    // Create map of integers to integers
    map<int, int> mp;

    // Iterate through each vector to compare guess value to code at each index
    for (int i = 0; i < n; i++)
    {
        // Iterate through each value in the guess for comparison
        for (int j = 0; j < n; j++)
        {
            // Compare each value for matches except if they are in the same position
            // relatively in their vector

            if (guess.code[j] == code[i] && guess.code[j] != code[j])
            {
                // Store first appearance of a guess value with an incorrect position in the map
                mp[guess.code[j]] = 1;

                // Break when first match is found in incorrect position to not count repeats
                break;
            }
        }
    }
    // Returns the size of the map which refers to the occurrences of values in the 
    // incorrect position

    return mp.size();
}
