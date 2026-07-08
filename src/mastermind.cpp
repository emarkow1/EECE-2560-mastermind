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
    vector<int> guess(n);
    int input;
    cout << "Enter your guess: ";
    cin >> input;
    if (input < 0) {
        cout << "Please enter a positive guess." << endl;
        return humanGuess();
    }
    for (int i = n; i > 0; i--){
        if ((guess.at(i) = input % 10) > m) {
            cout << "Your guess is out of range. Please enter a number between 0 and " << m << endl;
            return humanGuess();
        } else {
            guess.at(i) = input % 10;
            input /= 10;
        }
    }
    if (guess.size() != n) {
        cout << "Your guess in not the correct length. Please enter a guess that is " << n << " length." << endl;
        return humanGuess();
    }
    Code userGuess(n, m, guess);
    return userGuess;

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