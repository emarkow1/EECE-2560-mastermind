//
//  code.cpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//



#include "code.hpp"

Code::Code(int n, int m) : n(n), m(m) {
}
Code::Code(int n, int m, vector<int> t) : n(n), m(m), code(t){
}

// Generate a random code that is n digits long and is between 0 and m-1
void Code::random() {
    //Randomly generate a number for each digit in the code and making it n length
    for (int i = 0; i < n; i++) {
        code.push_back(rand() % m);
    }
    //print out the code for testing
    for (int i = 0; i < n; i++) {
        cout << code[i];
    }
};
// Check how many digits are correct and in the correct position
int const Code::checkCorrect(Code const &guess){
    int amountCorrect = 0;
    //check each digit in the code to see if it is the same as the guess in the same possition
    for (int i = 0; i < n; i++) { 
        if (code[i] == guess.code[i]) {
            amountCorrect += 1;
        }
    }
    //return int value of how many are correct
    return amountCorrect;
};
int const Code::checkIncorrect(Code const &guess) {
    // Count the number of correct numbers in incorrect positions
    Code tempCode = *this; // copy of original code to modify
    Code tempGuess = guess;
    int amountIncorrect = 0;
    // First replace all correct positions with -1 to indicate a correct guess
    for (int i = 0; i < n; i++)
    {
        if (code[i] == tempGuess.code[i]) {
            tempCode.code[i] = -1;
            tempGuess.code[i] = -1;
        }
    }
    // Now check for incorrect positions, ignoring entries now marked as -1
    for (int i = 0; i < n; i++)
    {
        if (tempGuess.code[i] != -1)
        {
            // See if there are any correct values in incorrect positions
            auto it = std::find(tempCode.code.begin(), tempCode.code.end(), tempGuess.code[i]);
            // If find did find a matching value
            if (it != tempCode.code.end())
            {
                amountIncorrect++;
                // Ensure no double counts
                // Replace value in tempCode with -1
                *it = -1;
                // Replace value in guess with -1
                tempGuess.code[i] = -1;
            }
        }
    }
    return amountIncorrect;
};

