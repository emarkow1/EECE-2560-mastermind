// 
// mastermind.cpp
// 1-satbermacmar-1b
//
// This file contains the implementation of the "Mastermind" class member 
// functions and constructors.


#include "mastermind.h"
#include <string>
#include <sstream>

// initializer list with inputted n and m (represneting length and range). 
// Stores the integer values of n and m to the code object's. Then creates
// secretCode object using n and m, and stores it to the code object's.
Mastermind::Mastermind(int n, int m)
    : secretCode(n, m), n(n), m(m)
{
}

// initializer list without inputted n and m (representing length and range).
// Uses default values of n = 5 and m = 7 and stores them to the code object's.
// Then creates secretCode object using n and m, and stores it to code object's
Mastermind::Mastermind()
    : secretCode(5, 7), n(5), m(7) 
{
}

// Defines printCode function to print the secret code for grading
// Uses Code object's print function to print secret code
void Mastermind::printCode() const
{
    cout << "Secret Code: ";
    secretCode.print();
    cout << endl;
}

// Defines humanGuess function to obtain n-length guess from user and returns
// it in the form of a Code object using a for loop to iterate over a vector.
Code Mastermind::humanGuess()
{
    vector<int> guess;
    int guessDigit; 
    
    // For loop to iterate in a digits for a guess and add them to the guess
    // vector.
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter digit " << (i + 1) << " of your guess: ";

        // cin the user input
        cin >> guessDigit;

        // check if the input is an integer and if it isn't send an error
        // message and clear the input buffer and decrement i to repeate the
        // input ask for the same digit.
        if (!cin)
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            --i; 
            continue;
        }

        // check if the input is within the valid range of 0 to m -1
        // Again clear the input buffer and decrement i to repeat the input
        if (guessDigit < 0 || guessDigit >= m)
        {
            cout << "Invalid digit. Please enter a digit between 0 and "
                 << (m - 1) << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            --i; 
            continue;
        }

        // if the input is valid add the digit to the guess vector
        guess.push_back(guessDigit);
    } // end for

    return Code(n, m, guess);
} // end humanGuess


// Defines getResponse function to compare user's guess to the secret code
// using Code class' checkCorrect and checkIncorrect functions.
// Returns a Response object containing number correct & incorrect.
Response Mastermind::getResponse(const Code &guess)
{
    int correct = secretCode.checkCorrect(guess);
    int incorrect = secretCode.checkIncorrect(guess);
    return Response(correct, incorrect);
}

// Defines isSolved function to determine if the secret code has been found by
// creating a new Response object containing n correct and 0 incorrect then
// comparing it to the response object generated from the user's guess.
bool Mastermind::isSolved(const Response &response) const
{
    Response correct(n, 0);
    return correct == response;
}

// Defines playGame function to generate and print a secret code, and then
// iteratively get a guess from the player and print the response until
// either the codemaker or the codebreaker has won.
void Mastermind::playGame()
{

    // Generated a random secret code.
    secretCode.random();
    cout << "The secret code is: ";

    // Print the secret code for grading purposes.
    printCode();
    cout << endl;

    //For loop to iterate over 10 guesses from the user 
    for (int x = 0; x < 10; x++)
    {

        // Get the user's guess
        Code breakerGuess = humanGuess();

        // Get the response for the user's guess
        Response guessResponse = getResponse(breakerGuess);


        // Check if the user's guess is correct
        if (isSolved(guessResponse))
        {
            cout << "You solved the code! Congratulations!" << endl;
            return;
        }
        else
        {
            cout << guessResponse << endl;
        }
    } // end for

    // If the user did not solve the code in 10 guesses, print out a message
    // and the secret code.
    cout << "Unfortunately you did not break the code. The secret code was: ";
    printCode();
} // end playGame