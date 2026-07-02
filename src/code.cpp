//
//  code.cpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//

#include <algorithm>

#include "code.hpp"

Code::Code(int n, int m) : n(n), m(m) {
}
Code::Code(int n, int m, vector<int> t) : n(n), m(m), code(t){
}


void Code::random() {
    for (int i = 0; i < n; i++) {
        code.push_back(rand() % m);
    }
    for (int i = 0; i < n; i++) {
        cout << code[i];
    }
};
int const Code::checkCorrect(Code &guess){
    int amountCorrect = 0;
    for (int i = 0; i < n; i++) {
        if (code[i] == guess.code[i]) {
            amountCorrect += 1;
        }
    }
    return amountCorrect;
};
int const Code::checkIncorrect(Code guess) {
    // Count the number of correct numbers in incorrect positions
    Code tempCode = *this; // copy of original code to modify
    int amountIncorrect = 0;
    // First replace all correct positions with -1 to indicate a correct guess
    for (int i = 0; i < n; i++)
    {
        if (code[i] == guess.code[i]) {
            tempCode.code[i] = -1;
            guess.code[i] = -1;
        }
    }
    // Now check for incorrect positions, ignoring entries now marked as -1
    for (int i = 0; i < n; i++)
    {
        if (guess.code[i] != -1)
        {
            // See if there are any correct values in incorrect positions
            auto it = std::find(tempCode.code.begin(), tempCode.code.end(), guess.code[i]);
            // If find did find a matching value
            if (it != tempCode.code.end())
            {
                amountIncorrect++;
                // Ensure no double counts
                // Replace value in tempCode with -1
                *it = -1;
                // Replace value in guess with -1
                guess.code[i] = -1;
            }
        }
    }
    return amountIncorrect;
};

