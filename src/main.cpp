//
//  main.cpp
//  1-satbermacmar-1b
//
//  Created by Jake Berman on 7/1/26.
//
// This file is what obtains the settings for the Mastermind game and creates a
// Mastermind object. Starts the game.

// includes C++ input/output stream library
#include <iostream>

// Include the necessary header files for the "Code" and "Mastermind" classes,
// as well as the "Response" class.
#include "code.hpp"
#include "mastermind.h"
#include "response.h"

// Included for input validation functions
#include <limits>

using namespace std;

// obtains the code length and digit range then creates a mastermind object and
// starts the game.
int main()
{  
    
    // creates integer variables n and m to store the length and range of the
    // code.
    int n, m;
    cout << "Welcome to Mastermind! Please enter the code length desired: ";

    // Checks to see if the input is a valid integer or is less than or equal
    // to 0. If not clear the input buffer and input again.
    while (!(cin >> n) || n <= 0)
    {
        cout << "Please enter a valid integer above 0 for your desired "
        "code length: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "and the range of digits you'd like: ";

    // Checks to see if the input is a valid integer or is less than or equal
    // to 0. Again, clear input buffer if invalid input and input again.
    while (!(cin >> m) || m <= 0)
    {
        cout << "Please enter a valid integer above 0 for your desired range "
        "of digits: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // creates a Mastermind object with the user input n and m
    Mastermind game1(n, m);

    // starts the game by calling Mastermind class function playGame()
    game1.playGame();

    return 0;
} // end main