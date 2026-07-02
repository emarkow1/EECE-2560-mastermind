//
//  code.hpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//

#ifndef code_hpp
#define code_hpp

#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;


class Code {
    public:
    Code(int n, int m);
    Code(int n, int m, vector<int> t);
    void random();
    int const checkCorrect(Code const &guess);
    int const checkIncorrect(Code const &guess);
    
    private:
    int n;
    int m;
    vector<int> code;
    
};

//the vector cant be private because we need to input the guess unless we add a function to do that 

#endif /* code_hpp */
