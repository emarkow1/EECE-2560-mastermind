//
//  response.h
//  Proj1Mastermind
//
//  Created by Jake Berman on 7/8/26.
//

#ifndef response_h
#define response_h

class response {
    public:
    response(int correct, int incorrect);
    int getCorrect() {return correct;};
    int getIncorrect() {return incorrect;};
    void setCorrect(int correctValue) {correct = correctValue;};
    void setIncorrect(int incorrectValue) {incorrect = incorrectValue;};
    
    private:
        int correct;
        int incorrect;
};

#endif
