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

<<<<<<< HEAD

    Code secretCode(5, 7);
    cout << "Secret Code: ";
    secretCode.random();
    
    Code guess1(5, 7, {5,0,3,2,6});
    Code guess2(5, 7, {2,1,2,2,2});
    Code guess3(5, 7, {1,3,3,4,5});
  
    cout << endl << "Guess 1: " << secretCode.checkCorrect(guess1) << " " << secretCode.checkIncorrect(guess1) << endl;
    cout << "Guess 2: " << secretCode.checkCorrect(guess2) << " " << secretCode.checkIncorrect(guess2) << endl;
    cout << "Guess 3: " << secretCode.checkCorrect(guess3) << " " << secretCode.checkIncorrect(guess3) << endl;
=======
    vector<int> t = {2, 1, 0, 2, 1}; 
    vector<int> x = {2, 2, 0, 1, 2};
    Code test(5, 3, t);
    Code guess(5, 3, x);
    //test.random();
    cout << test.checkCorrect(guess) << endl;
>>>>>>> 7446c28 (Added extensive comments to code.cpp and code.hpp files. No changes to main.cpp)
    return EXIT_SUCCESS;
}


