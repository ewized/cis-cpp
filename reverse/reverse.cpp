/*
    Filename: reverse.cpp
    Problem: Ch 9 # 4
    Description: Write a function that takes in a string and then sets
        two pointers, first with will set each char as an index, and last
        which will set each char back wards.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/06/2014
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Declaring
void reverse(string);
void output(string);

// Constants
char *rear;

// Rule them all :)
int main() {
    string str;

    // Ask the user.
    cout << "Enter a string: ";
    cin >> str;

    // Maybe I should run the reverse function?
    reverse(str);

    // Out put the char
    output(str);
    output(rear);

    return 0;
}

// Make me reverse the function.
void reverse(string str) {
    int len = str.length();
    int rev = len;

    rear = new char[len];

    for (int i = 0; i < len; i++) {
        rear[--rev] = str[i];
    }
}

// Make me out put each char.
void output(string word) {
    for (int i = 0; i < word.length(); i++) {
        cout << word[i];
    }
    cout << endl;
}
