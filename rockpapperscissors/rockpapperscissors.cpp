/*
 File: rockpaperscissors.cpp
 Description: Play a game of rock paper scissors
 Created: 9/12/2013
 Author: Joshua Rodriguez
 mail: ewized@gmail.com
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // Create the random seed.
    srand(time(0));

    // Define the varibles.
    int userInput, computerInput;
    string repeatProgram;
    const int RANDMAX = 3;
    const int RANDMIN = 1;
    const string picks[RANDMAX] = {"Rock", "Paper", "Scissors"};

    // Ask the user to repeat the program.
    do
    {
        // Ask the user for your choice.
        cout << "1: Rock" << endl
            << "2: Paper" << endl
            << "3: Scissors" << endl
            << "Pick one of the preseeding numbers then press enter: ";
        cin >> userInput;
        cout << endl;

    // Generate computer choice.
    //  load number for the computer with randomNumber()
    computerInput = random() % RANDMAX + RANDMIN;

    // Use a giant if else statement for all choices.
    // Print if the user wins or loses..
    if (userInput == computerInput)
    {
        cout << "Tied: ";
    }
    else if (userInput > computerInput)
    {
        if ((userInput == RANDMIN && computerInput == RANDMAX) || !(userInput == RANDMAX && computerInput == RANDMIN))
        {
            cout << "Winner: ";
        }
        else
        {
            cout << "Loser: ";
        }
    }
    else
    {
            cout << "Loser: ";
    }
    cout << "User picked '" << picks[userInput-1] << "' and "
                << "computer picked '" << picks[computerInput-1] << "'." << endl << endl;

    cout << "Type 'yes' to repeat the game anything else will end the game: ";
    cin >> repeatProgram;

    } while(repeatProgram == "yes" && repeatProgram != "");

    return 0;
}
