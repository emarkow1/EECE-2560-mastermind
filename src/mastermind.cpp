//  mastermind.cpp
//  1-satbermacmar-1b

// This file contains the implementation of the "Mastermind" class member functions.
// 
// the member variables of the class.


#include "mastermind.h"
#include <string>
#include <sstream>

// initializer list with inputted n and m (represneting length and range). 
// Stores the integer values of n and m to the code object's. Then creates
// secretCode object using n and m, and stores it to the code object's.
Mastermind::Mastermind(int n, int m) : secretCode(n, m), n(n), m(m) {}

// initializer list without inputted n and m (representing length and range).
// Uses default values of n = 5 and m = 7 and stores them to the code object's.
// Then creates secretCode object using n and m, and stores it to code object's
Mastermind::Mastermind() : secretCode(5, 7), n(5), m(7) {}

// Defines printCode function to print the secret code for grading
// Uses Code object's print function to print secret code
void Mastermind::printCode() const
{
    cout << "Secret Code: ";
    secretCode.print();
    cout << endl;
}

Code Mastermind::humanGuess()
{
    vector<int> guess;
    int guessDigit; 
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter digit " << (i + 1) << " of your guess: ";
        cin >> guessDigit;
        if (!cin) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            --i; 
            continue;
        }
        if (guessDigit < 0 || guessDigit >= m) {
            cout << "Invalid digit. Please enter a digit between 0 and " << (m - 1) << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            --i; 
            continue;
        }
        guess.push_back(guessDigit);
    }
    return Code(n, m, guess);
}
// Defines humanGuess function to obtain n-length guess from user and returns
// it in the form of a Code object using a for loop to iterate over a vector.
/*
Code Mastermind::humanGuess()
{
    vector<int> guess;
    int guessDigit; 
    bool cont = false;
    string userInput;

    while (!cont)
    {
        cout << "Enter your guess: ";

        getline(cin >> ws, userInput);

        istringstream input(userInput);

        guess.clear();

        while (input >> guessDigit)
        {
            guess.push_back(guessDigit);
        }

        if (guess.size() == n)
        {
            cont = true;
        }
        else
        {
            cout << "Please enter a guess of "<< n << " numbers." << "\n";
        }
    }
    // while(!cont) 
    // {
    //     cin >> guessDigit;
    //     guess.push_back(guessDigit);
    //     if (guess.size() == n)
    //     {
    //         cont = true;
    //     }
    //         else
    //         {
    //             cout << "Please enter guess of " << n << "numbers long. " ;
    //             guess.clear();
    //         }
        return Code(n,m,guess);
}
*/
// Defines getResponse function to compare user's guess to the secret code
// using Code class' checkCorrect and checkIncorrect functions.
// Returns a Response object containing number correct & incorrect.
Response Mastermind::getResponse(const Code &guess) {
    int correct = secretCode.checkCorrect(guess);
    int incorrect = secretCode.checkIncorrect(guess);
    return Response(correct, incorrect);
}

// Defines isSolved function to determine if the secret code has been found by
// creating a new Response object containing n correct and 0 incorrect then
// comparing it to the response object generated from the user's guess.
bool Mastermind::isSolved(const Response &response) const{
    Response correct(n, 0);
    return correct == response;
}

// Defines playGame function to generate and print a secret code, and then
// iteratively get a guess from the player and print the response until
// either the codemaker or the codebreaker has won.
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