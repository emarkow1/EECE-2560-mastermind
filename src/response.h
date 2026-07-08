//
//  response.h
//  1-satbermacmar-1b
//
//  Created by Jake Berman on 7/8/26.
//

#ifndef response_h
#define response_h

#include <iostream>
using namespace std;

class Response {
    public:
    Response(int correct, int incorrect);
    int getCorrect() const {return correct;};
    int getIncorrect() const {return incorrect;};
    void setCorrect(int correctValue) {correct = correctValue;};
    void setIncorrect(int incorrectValue) {incorrect = incorrectValue;};
    
    private:
        int correct;
        int incorrect;
};

bool operator==(const Response &lhs, const Response &rhs);
ostream &operator<<(ostream &os, const Response &response);

#endif
