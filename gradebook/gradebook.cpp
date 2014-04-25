/*
    Filename: gradebook.cpp
    Problem: pg 594 number 1
    Description: Make a gradebook program.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/18/2014
*/
#include <iostream>
#include <string>

using namespace std;

// Grades
struct Grades {
    string name;
    double final;
    double quiz_one;
    double quiz_two;
    double midterm;
};

// Function delcarations
Grades book;
void addStudent();
void outputStudent();
char gradeLetter(double);
double gradeAverage();

// Rule them all.
int main() {
    addStudent();
    outputStudent();
    return 0;
}

// Add a student to the gradebook.
void addStudent() {
    cout << "Enter the student name: ";
    cin >> book.name;
    cout << "Enter the score of the final: ";
    cin >> book.final;
    cout << "Enter the score of the midterm: ";
    cin >> book.midterm;
    cout << "Enter the score of quiz one: ";
    cin >> book.quiz_one;
    cout << "Enter the score of quiz two: ";
    cin >> book.quiz_two;
}

// What is the grade average.
double gradeAverage() {
    double total;
    total += book.final * .50;
    cout << total << endl;
    total += book.midterm * .25;
    cout << total << endl;
    total += (book.quiz_one + book.quiz_two) * .25;
    cout << total << endl;
    return total;
}

// Out put the grade book.
void outputStudent() {
    cout << "Student Name: " << book.name << endl;
    cout << "Final: " << book.final << " " << gradeLetter(book.final) << endl;
    cout << "Midterm: " << book.midterm << " " << gradeLetter(book.midterm) << endl;
    cout << "Quiz One: " << book.quiz_one << " " << gradeLetter(book.quiz_two) << endl;
    cout << "Quiz Two: " << book.quiz_two << " " << gradeLetter(book.quiz_two) << endl;
    cout << "Average: " << gradeAverage() << " " << gradeLetter(gradeAverage()) << endl;
}

// Translate the grade to a color.
char gradeLetter(double score) {
    if (score >= .9)
        return 'A';
    if (score >= .8)
        return 'B';
    if (score >= .7)
        return 'C';
    if (score >= .6)
        return 'D';

    return 'F';
}
