//
//  code.hpp
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/1/26.
//

//ensures header file is included only once
#ifndef code_hpp //if not defined, then define (prevents redefinition of code_hpp)
#define code_hpp

<<<<<<< HEAD
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
=======
#include <stdio.h> //includes C standard input/output library (I AM UNSURE IF WE NEED THIS (we have iostream). GO OVER TOGETHER)
#include <vector> //includes vector container library
#include <cstdlib> //includes functions such as rand() within library
#include <ctime> //includes time() so we can use along with rand() for random number generator
#include <iostream> //includes input/output streams
#include <algorithm> //COME BACK TO THIS
>>>>>>> 7446c28 (Added extensive comments to code.cpp and code.hpp files. No changes to main.cpp)

using namespace std; //defines usage of std library globally


<<<<<<< HEAD
class Code {
    public:
    Code(int n, int m);
    Code(int n, int m, vector<int> t);
    void random();
    int const checkCorrect(Code const &guess);
    int const checkIncorrect(Code const &guess);
    
    private:
=======
class Code { //creating class 'code'
public: //in a public section. these public member functions can be called outside of class
    Code(int n, int m); //creates a new object that stores n and m (length and range)
    Code(int n, int m, vector<int> t); //code object stores the already formed randomly generated secret code vector with length and range
    void random(); //uses random function to generate the secret code
    int const checkCorrect(Code const& guess); 
    int const checkIncorrect(Code const& guess);

private: //ensures n, m, and secret code can not be accessed by user and hidden in a private session.
>>>>>>> 7446c28 (Added extensive comments to code.cpp and code.hpp files. No changes to main.cpp)
    int n;
    int m;
    vector<int> code;

};

//the vector cant be private because we need to input the guess unless we add a function to do that 

#endif /* code_hpp */