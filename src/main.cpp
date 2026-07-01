//
//  main.cpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//

#include <iostream>
#include "code.hpp"
int main(int argc, const char * argv[]) {
    srand(time(NULL));

    vector<int> t = {2, 1, 0, 2, 1};
    vector<int> x = {2, 2, 0, 1, 2};
    Code test(5, 3, t);
    Code guess(5, 3, x);
    //test.random();
    cout << test.checkCorrect(guess) << endl;
    return EXIT_SUCCESS;
}


