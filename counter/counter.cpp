/*
    Filename: counter.cpp
    Problem: Problem number 5 in chapter 10
    Description: Define a class for a type called CounterType, An object of
        this type is used to count things, so it records a count that is a
        nonnegative whole number. Include a default constructor that sets the
        counter to zero and a constructor with one argument that sets the
        counter to the value specified bu its argument. Include member
        functions to increase the count by 1 and to decrease the counter by 1.
        Be sure that no member function allow the value of the counter to
        become negative. Also, include a member function that returns the
        current count value and the one that outputs the count to a stream.
        The member function for doing output will have one formal parameter of
        type ostream for the output stream that receives the output.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 11/26/2013
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Function Declaration
void output(ostream&, string);

class CounterType {
public:
    // Set up the class.
    CounterType(int);
    CounterType();

    // API Function.
    void output(ostream&);
    int get_counter();
    void add();
    void remove();
private:
    int counter;
    bool check_amount(int);
};

// Set up the template of CounterType with the given amount.
// When a negative number kill program.
CounterType::CounterType(int amount) {
    if (amount < 0) {
        cout << "NOTICE: Incorrect amount input defaulting to 0." << endl;
        counter = 0;
        return;
    }
    counter = amount;
}

// Set up the template of CounterType with default of 0.
CounterType::CounterType() {
    counter = 0;
}

// Output the current amount to the given out stream.
void CounterType::output(ostream& stream) {
    stream << "Counter is at: ";
    stream << get_counter() << endl;
}

// @return the current amount of counter.
int CounterType::get_counter() {
    return counter;
}

// Add one to the counter.
void CounterType::add() {
    int count = get_counter();
    // Should never happen but add it anyways.
    if (check_amount(count + 1)) {
        counter = count + 1;
    }
}

// Remove one from the counter.
void CounterType::remove() {
    int count = get_counter();
    if (check_amount(count - 1)) {
        counter = count - 1;
    }
}

// Check if the amount will make the counter zero.
bool CounterType::check_amount(int amount) {
    if (amount < 0) {
        cout << "WARNING: New amount will be negative. "
             << "Will not change counter." << endl;
        return false;
    }
    return true;
}

// Main Function
int main() {
    // Count Setup
    cout << "Counter One: Setup" << endl;
    CounterType counter_one;
    cout << "Counter Two: Setup" << endl;
    CounterType counter_two(10);
    cout << "Counter Three: Setup" << endl;
    CounterType counter_three(-10);
    cout << endl;

    // Counter Amount.
    cout << "Counter One: Amount" << endl;
    counter_one.output(cout);
    cout << "Counter Two: Amount" << endl;
    counter_two.output(cout);
    cout << "Counter Three: Amount" << endl;
    counter_three.output(cout);
    cout << endl;

    // Counter Remove One.
    cout << "Counter One: Remove One" << endl;
    counter_one.remove();
    cout << "Counter Two: Remove One" << endl;
    counter_two.remove();
    cout << "Counter Three: Remove One" << endl;
    counter_three.remove();
    cout << endl;

    // Counter Amount.
    cout << "Counter One: Amount" << endl;
    counter_one.output(cout);
    cout << "Counter Two: Amount" << endl;
    counter_two.output(cout);
    cout << "Counter Three: Amount" << endl;
    counter_three.output(cout);
    cout << endl;

    // Counter Add One.
    cout << "Counter One: Add One" << endl;
    counter_one.add();
    cout << "Counter Two: Add One" << endl;
    counter_two.add();
    cout << "Counter Three: Add One" << endl;
    counter_three.add();
    cout << endl;

    // Counter Amount.
    cout << "Counter One: Amount" << endl;
    counter_one.output(cout);
    cout << "Counter Two: Amount" << endl;
    counter_two.output(cout);
    cout << "Counter Three: Amount" << endl;
    counter_three.output(cout);
    cout << endl;

    return 0;
}
