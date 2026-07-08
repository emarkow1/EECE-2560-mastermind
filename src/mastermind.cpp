//  mastermind.cpp
//  1-satbermacmar-1b


#include "mastermind.h"

Mastermind::Mastermind(int n, int m) : secretCode(n, m), n(n), m(m) {}

Mastermind::Mastermind() : secretCode(5, 7), n(5), m(7) {}

void Mastermind::printCode() const
{
    cout << "Secret Code: ";
    secretCode.print();
    cout << endl;
}

Code Mastermind::humanGuess()
{
    vector<int> guess();
    cout << "Enter your guess: ";
    cin >> input;
   

}

Response Mastermind::getResponse(const Code &guess) {
    int correct = secretCode.checkCorrect(guess);
    int incorrect = secretCode.checkIncorrect(guess);
    return Response(correct, incorrect);
}


bool Mastermind::isSolved(const Response &response) const{
    Response correct(n, 0);
    return correct == response;
}

void Mastermind::playGame() {
    secretCode.random();
    cout << "The secret code is: ";
    printCode();
    cout << endl;
    for (int x = 0; x < 10; x++) {
        Code breakerGuess = humanGuess();
        Response guessResponse = getResponse(breakerGuess);
        if (isSolved(guessResponse)) {
            cout << "You solved the code! Congratulations!" << endl;
            return;
        } else {
            cout << guessResponse << endl;
        }
    }
    cout << "Unfortunately you did not break the code. The secret code was: ";
    printCode();
}