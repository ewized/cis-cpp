/*
    Filename: highscore.cpp
    Problem: High Score List
    Description: 
        Write a program that maintains a high score table of five
        entries, where each entry is made up of a player's name
        and score.  The table should store the entries in order,
        from highest score to lowest. Your program should
        initialize the table using your name and 1000 for all five
        entries.  Next, your program should display the entries and
        allow a player to add a new one.  Your program should accept
        a name and a  score for the potential new entry.  If the score
        is greater than or equal to the lowest score in the table,
        your program should insert the new entry at the correct
        position, adjust the rest of the table accordingly, and
        display a message saying that the entry was inserted.  Otherwise,
        your program should display a message telling the player that
        the score was too low for the entry to be added.  Your program
        should continue to display the table and allow the player to add
        new entries as long as he or she wants.  (Hint: Your program
        doesn't have to do a full sort of the entries when a new one is
        added.  You can assume that the entries are already sorted; a new
        entry needs only to be inserted at the correct position with
        the rest of the table adjusted accordingly)
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/06/2014
*/
#include <iostream>
#include <string>

using namespace std;

// Declarations
void displayScores();
void menu();
int mainMenu();
void addScore();
void addScoreBoard();

// The score struct
struct Score {
    bool base;
    string name;
    //string name = "Your Name"; // Stupid C++11
    int score;
    //int score = 1000; // Stupid C++11
};

// The scoreboard
Score *scoreboard;
// The scoreboard size.
const int size = 5;

// The main entry point to the program.
int main() {
    addScoreBoard();
    menu();

    return 0;
}

// Add scorebord with default scores
void addScoreBoard() {
    scoreboard = new Score[size];

    for (int i = 0; i < size; i++) {
        scoreboard[i].base = true;
        scoreboard[i].name = "Your Name";
        scoreboard[i].score = 1000;
    }
}

// Add a score to the list
void addScore() {
    string name;
    int score;
    bool first = true;
    cout << "Enter the name of the score: ";
    cin >> name;
    cout << "Enter score for " << name << ": ";
    cin >> score;

    for (int i = 0; i < size; i++) {
        if (i > size) return;

        // Set score if
        //      replace score if default,
        //      add score if not default.
        if (scoreboard[i].score < score && first) {
            if (!scoreboard[i].base) i++;

            scoreboard[i].base = false;
            scoreboard[i].score = score;
            scoreboard[i].name = name;
            first = false;
        }
    }
}

// Display the scores
void displayScores() {
    for (int i = 0;i<size;i++) {
        cout << 1+i << ". Name: " << scoreboard[i].name;
        cout << " Score: " << scoreboard[i].score << endl;
    }
}

// Get the menu selection
int mainMenu() {
    cout << "1. Add a score." << endl;
    cout << "2. View high scores." << endl;
    cout << endl;
    cout << "Select the number for the menu selection that you want: " << endl;
    int sel;
    cin >> sel;
    return sel;
}

// Let the user select from the menu
void menu() {
    switch (mainMenu()) {
        case 1:
            addScore();
            break;
        case 2:
            displayScores();
            break;
    }
    menu();
}
