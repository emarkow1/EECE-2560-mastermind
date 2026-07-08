
#ifndef mastermind_h
#define mastermind_h

#include "code.hpp"
#include "response.h"

class Mastermind {
    public:
    Mastermind mastermind(int n, int m);

    Mastermind mastermind();

    Code humanGuess();

    Response getResponse(Code &guess);

    bool isSolved(Code &guess);

    void playGame();

    
    private:
    Code secretCode();
};


#endif