//
//  code.cpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//
// This file contains the implementation of the "Code" class member functions.
// It also defines the constructors that initialize
// the member variables of the class.

#include "code.hpp"

// initializer list. stores the integer values of n and m to the code object's
// member variables n and m (representing length and range)
Code::Code(int n, int m) : n(n), m(m)
{
}

// second constructor for when secret code is known. stores secret code to the
// code object's member variable along with n and m
Code::Code(int n, int m, vector<int> t) : n(n), m(m), code(t)
{
}

// generate a random code that is n digits long and is between 0 and m-1
void Code::random()
{

    // randomly generate a number for each digit in the code and making it n
    // length
    for (int i = 0; i < n; i++)
    {

        // adds newly random generated integer to the end of the vector (growing
        // it until i = n)
        code.push_back(rand() % m);
    }

    // print out the code for testing
    for (int i = 0; i < n; i++)
    {
        cout << code[i];
    }
} // end random

// checkCorrect checks how many digits are correct and in the correct position.
// initializes checkCorrect function of class 'code' that will return an int
// value of r1 (amount correct) using secret code and user guess
int const Code::checkCorrect(Code const& guess)
{

    // initializes default value for amount of numbers guessed correctly (0)
    int amountCorrect = 0;

    // check each digit in the code to see if it is the same as the guess in the
    // same position
    for (int i = 0; i < n; i++)
    {
        if (code[i] == guess.code[i])
        {
            // if correct guess, add 1 to amountCorrect to imply correct choice
            amountCorrect += 1;
        }
    }

    // return int value of how many are correct
    return amountCorrect;
} // end checkCorrect

// checkIncorrect counts the number of correct numbers in incorrect positions.
// initializes checkIncorrect function of class 'code' that will return an int
// value of amount digits that are correct but in wrong sequence
int const Code::checkIncorrect(Code const& guess)
{

    // copy of original code to modify
    Code tempCode = *this;

    // stores guess in tempGuess with class 'code' to compare with original
    // class 'Code' secret sequence
    Code tempGuess = guess;
    int amountIncorrect = 0;

    // First replace all correct positions with -1 to indicate a correct guess
    for (int i = 0; i < n; i++)
    {
        if (code[i] == tempGuess.code[i])
        {
            tempCode.code[i] = -1;
            tempGuess.code[i] = -1;
        }
    }

    // Now check for incorrect positions, ignoring entries now marked as -1
    for (int i = 0; i < n; i++)
    {
        if (tempGuess.code[i] != -1)
        {

            // See if there are any correct values in incorrect positions using
            // find() in order to seek out specific digit within sequence
            auto it = std::find(tempCode.code.begin(), tempCode.code.end(),
                tempGuess.code[i]);

            // If find did find a matching value
            if (it != tempCode.code.end())
            {
                amountIncorrect++;

                // Ensure no double counts by replacing value in tempCode with -1
                // (as it will not be a proper user input).
                *it = -1;

                // Replace value in tempGuess with -1
                tempGuess.code[i] = -1;
            }
        } //end if
    }

    return amountIncorrect;
} // end checkIncorrect
