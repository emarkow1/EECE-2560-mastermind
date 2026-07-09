//  mastermind.cpp
//  1-satbermacmar-1b
/* This File contains the implementation of the "Mastermind" 
class member functions. It also defines the constructors that initialize 
the member variables of the class.
*/

#include "mastermind.h"


// Mastermind constructor that initializes the secret code with the given length and range
Mastermind::Mastermind(int n, int m) : secretCode(n, m), n(n), m(m) {}

// Default Mastermind constructor that initializes the secret code with default length of 5 and range of 10
Mastermind::Mastermind() : secretCode(5, 10), n(5), m(10) {}

// Print the secret code to terminal
void Mastermind::printCode() const
{
    cout << "Secret Code: ";
    //utilize the Code function to print the secret code
    secretCode.print();
    cout << endl;
} // end printCode

Code Mastermind::humanGuess()
{
    vector<int> guess(n);
    cout << "Enter your guess: ";
    cin >> input;
   

}

// getResponse takes in a guess and then returns a response object
// Containing the number of correct and incorrect digits in the guess
Response Mastermind::getResponse(const Code &guess) {
    
    // Use checkCorrect and checkIncorrect functions from the Code class 
    // to get the number of correct and incorrect digits in the guess
    int correct = secretCode.checkCorrect(guess);
    int incorrect = secretCode.checkIncorrect(guess);

    //return a Response with the number of correct and incorrect digits
    return Response(correct, incorrect);
}

// isSolved checks to see if a response has been solved
// by comparing it to a response with the number of correct
// digits equal to the length of the code and 0 incorrect digits
bool Mastermind::isSolved(const Response &response) const{

    // Creates a Response object with the number of correct digits equal
    // to the length of the code and 0 incorrect digits
    Response correct(n, 0);

    // Use the overloaded == operator to then compare the input response
    // to the correct response and return true if they are equal and
    // false if they are not equal
    return correct == response;
}


// Playgame is a function that essentially runs the game. It initializes
// a random secret code and prints out the code (for grading purposes) it
// then ieratively gets a guess from a user then checks the guess with the 
// secret code. After 10 guesses if the user has not correctly guessed the secret
// code then the game ends and the user looses.
void Mastermind::playGame() {

    // Generate a random secret code
    secretCode.random();

    // print out the secret code using the mastermind function
    cout << "The secret code is: ";
    printCode();
    cout << endl;

    // This is a loop that goes through 10 iterations of gettings a guess
    for (int x = 0; x < 10; x++) {

        // Creates a Code object then sets the user guess to the Code object.
        Code breakerGuess = humanGuess();

        // Creates a Response object that gets the response from the guess.
        Response guessResponse = getResponse(breakerGuess);

        // Checks to see if the Response is solved and if the user won the game.
        if (isSolved(guessResponse)) {
            cout << "You solved the code! Congratulations!" << endl;

            //end function if the user solved the code.
            return;

        // If the user did not solve the code then print the reponse to the user
        // and loop back to another guess.
        } else {
            cout << guessResponse << endl;
        }
    }
    cout << "Unfortunately you did not break the code. The secret code was: ";
    printCode();
}