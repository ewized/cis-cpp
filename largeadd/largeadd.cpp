/*
    Filename: largeadd.cpp
    Problem: #7 pg 439
    Description: An array can be used to store large integer one digit at a
        time. For example, the integer 1234 could store in the array a by
        setting a[0] to 1, a[1] to 2, a[2] to 3, a[3] to 4. However, for
        this exercise you might find it more useful to store the digits
        backward.

        In this exercise you will write a program that reads in two
        positive integers that are 20 or fewer digits in length and then
        outputs the sum of the two numbers. Your program will read the digits
        as chars. After they are put in the array they will be changed to
        an integer. 
        
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 10/29/2013
*/
#include <iostream>
#include <string>

using namespace std;

// Function declaration
void get_array(char [], string);
void fill_array(char [], int);
void get_number(char [], int [], int);
void add_number(int [], int [], int);
void print_array(int [], int);
int convert_ascii(char);
bool get_repeat();

// Constant var
const int SIZE = 20;

// The main function jack.
int main() {
    // Ask the user if they want to repeat.
    do {
        // Declare arrays.
        char number_one[SIZE], number_two[SIZE];
        int num_one[SIZE], num_two[SIZE];

        // Fill arrays.
        fill_array(number_one, SIZE);
        fill_array(number_two, SIZE);

        // Ask user for the two numbers.
        get_array(number_one, "Enter the first number: ");
        get_array(number_two, "Enter the next number: ");

        // Get the number from array
        get_number(number_one, num_one, SIZE);
        get_number(number_two, num_two, SIZE);

        // Do the math and print results.
        add_number(num_one, num_two, SIZE);
    } while (get_repeat());

    return 0;
}

// Fills the array with zeros.
void fill_array(char array[], int size) {
    for (int i = 0; i < size;i++) {
        array[i] = 'a';
    }
}

// Ask the user for the char array.
void get_array(char array[], string message) {
    cout << message;
    cin >> array;
}

// Changes the char array to an int array.
void get_number(char array[], int results[], int size) {
    int count = size, index;
    bool prefix = true;

    // Flip the array.
    for (int i = 0; i < size; i++) {
        count--;
        results[count] = convert_ascii(array[i]);
    }

    // Find the last zero.
    for (int i = 0; i < size;i++) {
        if (results[i] == 0) {
            if (prefix) {
                index = i;
                index++;
            }
        }
        else {
            prefix = false;
        }
    }

    // Set the right order at the right index.
    for (int i = 0; index < size; i++) {
        results[index] = convert_ascii(array[i]);
        index++;
    }
}

// Convert the basic 0-9 char into numbers.
// This is a hack fix to my problem.
int convert_ascii(char number) {
    switch (number) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

// Print the array out.
void print_array(int array[], int size) {
    bool prefix = true;
    for (int i = 0; i < size;i++) {
        if (!(array[i] == 0 && prefix)) {
            prefix = false;
            cout << array[i];
        } 
    }
}

// Adds two numbers then prints the problem.
void add_number(int a[], int b[], int size) {
    // Print out the results.
    cout << "ANSWER: ";
    print_array(a, size);
    cout << " + ";
    print_array(b, size);
    cout << " = ";

    // Do the awesome addition.
    bool carryover = false;
    int number, final[size], index = 0;
    for (int i = size-1;i >= 0;i--) {
        index++;
        if (carryover) {
            number = a[i] + b[i] + 1;
            carryover = false;
        }
        else {
            number = a[i] + b[i];
        }
        if (number > 9) {
            number -= 10;
            carryover = true;
        }
        final[i] = number;
    }

    // Check if the array if too big.
    if (carryover && index == size) {
        cout << "Too Big";
    }
    else {
        print_array(final, size);
    }
    cout << endl;
}

// Repeat the program if the user wants to.
// @return true if yes and false if no.
bool get_repeat() {
    char a; // This is answer
    do {
        cout << "Repeat? Enter 'y/n': ";
        cin >> a;
        if (a == 'Y' || a == 'y') {
            return true;
        }
        else if (a == 'N' || a == 'n') {
            return false;
        }
    } while(!(a == 'Y' || a == 'y' || a == 'N' || a == 'n'));
}
