//  response.h
//  1-satbermacmar-1b
// 
// This file contains the declaration of the "Response" class
// which includes its private member variables, public member functions,
// and overloaded operators.


// ensures header file is included only once
// if not defined, then define (prevents redefinition of response_hpp)
#ifndef response_h
#define response_h

// includes C standard input/output library
#include <iostream>

// defines usage of std library globally
using namespace std;

// creating class "Response"
class Response {
    public:
        // creates a new object that stores # correct and incorrect 
        Response(int correct, int incorrect);

        // returns number correct stored in the Response object
        int getCorrect() const {return correct;}; 

        // returns number incorrect stored in the Response object
        int getIncorrect() const {return incorrect;}

        // defines a new value for the number correct in the Response object
        void setCorrect(int correctValue) {correct = correctValue;};

        // defines a new value for the number incorrect in the Response object
        void setIncorrect(int incorrectValue) {incorrect = incorrectValue;};
    
    private:
        // ensures the number correct and incorrect cannot be access directly
        // by the user through keeping them in the private section of the class
        int correct;
        int incorrect;
};

// Overload the operator == for comparison between Response objects
bool operator==(const Response &lhs, const Response &rhs);

// Overload the operator << to print Response objects
ostream &operator<<(ostream &os, const Response &response);

#endif
