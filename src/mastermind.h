//  mastermind.h
//  1-satbermacmar-1b
//
// This file contains the declaration of the "mastermind" class
// which stores integers n and m (the length and range).

// ensures header file is included only once
// if not defined, then define (prevents redefinition of mastermind_hpp)
#ifndef mastermind_h
#define mastermind_h

// includes input/output streams
#include <iostream>

// includes code class
#include "code.hpp"

// includes response class
#include "response.h"

// defines usage of std library globally
using namespace std;

// creating class "Mastermind"
class Mastermind {
    public:
        // Constructor 1 
        // Creates a new object that stores n and m (length and range)
        Mastermind(int n, int m);

        // Constructor 2
        // Creates a new object with no given n and m (length and range)
        // Default n = 5, m = 10
        Mastermind();

        // prints secret code for easy comparison checks
        void printCode() const;
    
        // creates humanGuess object to get guess from user
        Code humanGuess();

        // Compares the user's guess to the secret code and returns result as a
        // Response object
        Response getResponse(const Code &guess);

        // compares user's guess with the secret code and returns T/F boolean
        bool isSolved(const Response &response) const;
        
        // Initializes a new Mastermind game session with a random secret code
        // for the user to play and try and guess a randomly generated
        // secret code in 10 guesses or less
        void playGame();

    
    private:
        // ensures secretCode, n, and m cannot be accessed directly by the user
        // through keeping them in a the private section of the class
        Code secretCode;
        const int n;
        const int m;
};


#endif