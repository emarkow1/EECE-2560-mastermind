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
int const Code::checkIncorrect(Code &guess) {
    
    return 0;
};

