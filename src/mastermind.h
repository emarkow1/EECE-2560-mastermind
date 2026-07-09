//  mastermind.h
//  1-satbermacmar-1b

/*
This header file declared the 'Mastermind' class, including its private member
variables and public member functions. It also includes the libraries needed 
within the 'Mastermind' class declaration.
*/

// ensures header file is included only once
// if not defined, then define (prevents redefinition of mastermind_h)
#ifndef mastermind_h
#define mastermind_h

// includes input/output streams
#include <iostream>

// includes the 'Code' class header file
#include "code.hpp"

// includes the 'Response' class header file
#include "response.h"

// defines usage of std library globally
using namespace std;

//creating class "Mastermind"
class Mastermind {
    public:

    // in a public section. these public member functions can be called
    // outside of class

    // creates a new object that stores n and m (length and range)
    Mastermind(int n, int m);

    // creates a default mastermind object that stores the default 
    // length of 5 and range of 10
    Mastermind();

    // prints the secret code
    void printCode() const;
    
    // takes in a guess from the user checks the input is correct
    // and returns a Code object
    Code humanGuess();

    // takes in a guess and then returns a response object
    // containing the number of correct and incorrect digits in the guess
    Response getResponse(const Code &guess);

    // Checks to see if a guess has been solved by passing in a response.
    bool isSolved(const Response &response) const;

    // Starts the game and loops through the game until the user guesses the code
    // or doesn't and looses after 10 gueses.
    void playGame();

    
    private:

    // ensures n, m, and secret code cannot be accessed directly by the user
    // through keeping them in the private section of the class.
    Code secretCode;
    const int n;
    const int m;
}; // end Mastermind


#endif /* mastermind_h */