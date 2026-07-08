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
    int getCorrect() {return corret;};
    int getIncorrect() {return incorrect;};
    void setCorrect(int correct);
    void setIncorrect(int incorrect);
    
    private:
             int corret;
             int incorrect;
};

#endif
