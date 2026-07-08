//
//  response.cpp
//  1-satbermacmar-1b
//
//  Created by Jake Berman on 7/8/26.
//

#include "response.h"

Response::Response(int correct, int incorrect) : correct(correct), incorrect(incorrect) {
}

bool operator==(const Response &lhs, const Response &rhs) {
    return lhs.getCorrect() == rhs.getCorrect() && lhs.getIncorrect() == rhs.getIncorrect();
}

ostream &operator<<(ostream &os, const Response &response) {
    os << "Correct: " << response.getCorrect() << ", Incorrect: " << response.getIncorrect();
    return os;
}