//
//  code.hpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//
// This header file declares the 'Code' class, including its private member
// variables and public member functions.
// It also includes the libraries needed within the 'Code' class declaration.


// ensures header file is included only once
// if not defined, then define (prevents redefinition of code_hpp)
#ifndef code_hpp
#define code_hpp

// includes C standard input/output library
#include <stdio.h>

// includes vector container library
#include <vector>

#include <random>
// include random library

// includes input/output streams
#include <iostream>

// includes the find() algorithm 
// which is utilized to compare "Code" object values
#include <algorithm>

// defines usage of std library globally
using namespace std;

// creating class "Code"
class Code
{
public:

    // in a public section. these public member functions can be called
    // outside of class

    // creates a new object that stores n and m (length and range)
    Code(int n, int m);

    // creates a Code object that stores the already formed randomly generated
    // secret code vector with length and range
    Code(int n, int m, vector<int> t);

    // uses random function to generate the secret code
    void random();

    // compares secret code with "Code" class object "guess" and returns the
    // number of digits that are correctly present and in the right position
    int checkCorrect(Code const& guess) const;

    // compares secret code with "Code" class object "guess" and returns the
    // number of digits that are correctly present but in the wrong position
    int checkIncorrect(Code const& guess) const;

private:
    
    // ensures n, m, and secret code cannot be accessed directly by the user
    // through keeping them in the private section of the class.
    const int n;
    const int m;
    vector<int> code;

}; // end Code

#endif /* code_hpp */