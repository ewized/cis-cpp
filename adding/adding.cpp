/*
    Filename: reverse.cpp
    Problem: In Class Work
    Description: Upload the program that was outlined in class.
        1.  Prompt user for size of the arrays.
        2.  Interactively ask the user for elements for the 1st and then the 2nd array.
        3.  Add the elements together and place them in a third array.
        4.  Print out the 3rd array.
        5.  Use functions to accomplish this program assignment.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/06/2014
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Declaring
void addMe(string,string);
void output(string);

// Constants
char *total;

// I really need this review or that I'm very tired.
// AKA This is the main function that has to run first!!!
int main() {
    string strOne;
    string strTwo;

    // Ask the user.
    cout << "Enter a string: ";
    cin >> strOne;

    // Ask the user.
    cout << "Enter a new string: ";
    cin >> strTwo;

    // Forgot to add me again....
    addMe(strOne, strTwo);

    // Out put the char
    output(total);

    return 0;
}

// Add two strings together and place then in the pointer
void addMe(string strOne, string strTwo) {
    int lenOne = strOne.length();
    int lenTwo = strTwo.length();
    int place = 0;

    total = new char[lenOne + lenTwo];

    for (int i = 0; i < lenOne+lenTwo; i++) {
        if (i < lenOne) {
            total[i] = strOne[i];
        }
        else {
            total[i] = strTwo[place];
            place++;
        }
    }
}

// Make me out put each char.
void output(string word) {
    for (int i = 0; i < word.length(); i++) {
        cout << word[i];
    }
    cout << endl;
}
