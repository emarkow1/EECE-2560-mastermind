//  mastermind.h
//  1-satbermacmar-1b

#ifndef mastermind_h
#define mastermind_h

#include <iostream>
#include "code.hpp"
#include "response.h"

using namespace std;

class Mastermind {
    public:
    Mastermind(int n, int m);

    Mastermind();

    Code humanGuess();

    Response getResponse(Code &guess);

    bool isSolved(Code &guess);

    void playGame();

    
    private:
    Code secretCode;
    const int n;
    const int m;
};


#endif