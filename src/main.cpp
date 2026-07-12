//
//  main.cpp
//  1-satbermacmar-1b
//
//  Created by Jake Berman on 7/1/26.
//
// This file creates the "Code" class objects while calling the member
// functions to execture the mastermind game

#include <iostream>
#include "code.hpp"
#include "mastermind.h"
#include "response.h"
#include <limits>
using namespace std;

// main function that creates the objects of the "Code" class and executes the
// mastermind game.
int main()
{  
    //NEED TYPE CHECKING HERE
    int n, m;
    cout << "Welcome to Mastermind! Please enter the code length desired: ";
    while (!(cin >> n) || n <= 0){
        cout << "Please enter a valid integer above 0 for your desired code length: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << " and the the range of digits you'd like: ";
    while (!(cin >> m) || m <= 0){
        cout << "Please enter a valid integer above 0 for your desired range of digits: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    Mastermind game1(n, m);
    game1.playGame();

    /*
    // sets the secretCode's length to 5 and range to 7
    Code secretCode(5, 7);

    // print text
    cout << "Secret Code: ";

    // generates secret code using random function
    secretCode.random();
    secretCode.print();
    // all the sample code guesses required for Part A of the Project
    Code guess1(5, 7, { 5, 0, 3, 2, 6 });
    Code guess2(5, 7, { 2, 1, 2, 2, 2 });
    Code guess3(5, 7, { 1, 3, 3, 4, 5 });

    // prints out each of the three guesses' respective correct integer values
    // with correct placement AND correct values with the wrong placement
    cout << endl << "Guess 1: " << secretCode.checkCorrect(guess1) << " "
        << secretCode.checkIncorrect(guess1) << endl;
    cout << "Guess 2: " << secretCode.checkCorrect(guess2) << " "
        << secretCode.checkIncorrect(guess2) << endl;
    cout << "Guess 3: " << secretCode.checkCorrect(guess3) << " "
        << secretCode.checkIncorrect(guess3) << endl;

    // - BELOW COMMENTS ARE FOR TESTING PURPOSES. Kept in comments to preserve
    // project building steps.
    // vector<int> t = {2, 1, 0, 2, 1};
    // vector<int> x = {2, 2, 0, 1, 2};
    // Code test(5, 3, t);
    // Code guess(5, 3, x);
    // test.random();
    // cout << test.checkCorrect(guess) << endl;
    */
    return EXIT_SUCCESS;
} // end main