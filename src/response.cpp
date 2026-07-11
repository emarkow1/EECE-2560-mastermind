//  response.cpp
//  1-satbermacmar-1b
//
// This file contains the implementation of the "response" class
// which stores the # correct and incorrect as well as defines
// the overloaded operators == and << to compare and print responses

#include "response.h"

// Constructor to initialize the # correct and incorrect to Response object
Response::Response(int correct, int incorrect) : correct(correct), incorrect(incorrect) {
}

// == overload operator to compare responses and return boolean result
bool operator==(const Response &lhs, const Response &rhs) {
    return lhs.getCorrect() == rhs.getCorrect() && lhs.getIncorrect() == rhs.getIncorrect();
}

// << overload operator to print # correct and incorrect for a Response object
ostream &operator<<(ostream &os, const Response &response) {
    os << "Correct: " << response.getCorrect() << ", Incorrect: " << response.getIncorrect();
    return os;
}