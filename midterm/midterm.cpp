/*
    Filename: midterm.cpp
    Description: Write a program that has a Fibonacci number calculating
        function. The function will take an integer as a parameter which
        is the Fibonacci number to calculate, and return the Fibonacci
        number. Then use this function to calculate the sum of every
        Fibonacci number that is divisible by 3 or 5, (hint - use modulus
        division). Do this for all Fibonacci numbers less than 4,000,000.
        Make sure that you document your program.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 10/15/2013
*/

#include <iostream>

using namespace std;

// Function declarations.
int get_fibonacci(int, int&);
int get_number();
void get_output(int, int);

// Constant vars.
const int NUMBER_ONE = 5;
const int NUMBER_TWO = 3;

int main() {
    // Set up the vars.
    int fib_sum = 0;

    // Define the user fib and set the fib sum.
    int user_fib = get_fibonacci(get_number(), fib_sum);

    // Output the results.
    get_output(user_fib, fib_sum);
    return 0;
}

// Return the Fibonacci number at the index number.
int get_fibonacci(int number, int& sum) {
    int new_fib_number, fib_one = 1, fib_two = 1;

    for (int i = 1; i < number; i++) {
        new_fib_number = fib_one + fib_two;
        fib_two = fib_one;
        fib_one = new_fib_number;

        // If the number is divisible then add them.
        if (fib_two % NUMBER_ONE == 0 || fib_two % NUMBER_TWO == 0) {
            sum = sum + fib_two;
        }
    }
    return fib_two;
}

// Ask the user for a positive number.
// return the number the user entered.
int get_number() {
    int number = 0;
    do {
        cout << "Enter a positive number: ";
        cin >> number;
    } while (number < 0);
    return number;
}

// Print out the output duh.
void get_output(int user_fib, int fib_sum) {
    cout << "The Fibonacci number is: " << user_fib << endl;
    cout << "The sum of the Fibonacci numbers is: " << fib_sum << endl;
}
