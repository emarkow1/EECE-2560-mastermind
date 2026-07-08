//  mastermind.cpp
//  1-satbermacmar-1b


#include "mastermind.h"

Mastermind::Mastermind(int n, int m) : secretCode(n, m), n(n), m(m) {}

Mastermind::Mastermind() : secretCode(5, 7), n(5), m(7) {}
