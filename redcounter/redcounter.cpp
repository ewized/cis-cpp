/*
    Filename: redcounter.cpp
    Problem: pg 596 number 9
    Description: Make a counter that will count using a class.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/20/2014
*/
#include <iostream>

using namespace std;

class Counter {
    private:
        int max;
        int counter;
    public:
        Counter(int);
        void reset();
        void inc1();
        void inc10();
        void inc100();
        void inc1000();
        bool overflow();
        void output();
};

void menu(Counter&);
void parseMenu(Counter&, char);

// Constructor
Counter::Counter(int size) {
    counter = 0;
    max = size; 
}

// Reset the counter
void Counter::reset() {
    counter = 0;
}

// Add 1
void Counter::inc1() {
    counter++;
}

// Add 10
void Counter::inc10() {
    for (int i = 0; i < 10; i++)
        inc1();
}

// Add 100
void Counter::inc100() {
    for (int i = 0; i < 10; i++)
        inc10();
}

// Add 1000
void Counter::inc1000() {
    for (int i = 0; i < 10; i++)
        inc100();
}

// Check is the counter is red or white.
bool Counter::overflow() {
    return counter > max;
}

// Output the data
void Counter::output() {
    cout << "The Counter is at: " << counter << endl;
}

int main() {
    Counter c(9999);
    menu(c);
    return 0;
}

// The menu
void menu(Counter& c) {
    char index;
    do {
        cout << endl << endl << endl;
        cout << "a - cents" << endl;
        cout << "s - dimes" << endl;
        cout << "d - dollars" << endl;
        cout << "f - tens of dollars" << endl;
        cout << "o - overflow" << endl;
        cout << "r - reset the counter" << endl;
        cout << "e - end program" << endl;
        cout << "Enter the letter for the option you want: ";
        cin >> index;
        parseMenu(c, index);
    }
    while(index != 'e');
}

// Parse the menu
void parseMenu(Counter& c, char index) {
    int amount;

    switch (index) {
        case 'a':
            cout << "Enter the amount you want: ";
            cin >> amount;
            for (int i = 0; i < amount; i++)
                c.inc1();
            break;
        case 's':
            cout << "Enter the amount you want: ";
            cin >> amount;
            for (int i = 0; i < amount; i++)
                c.inc10();
            break;
        case 'd':
            cout << "Enter the amount you want: ";
            cin >> amount;
            for (int i = 0; i < amount; i++)
                c.inc100();
            break;
        case 'f':
            cout << "Enter the amount you want: ";
            cin >> amount;
            for (int i = 0; i < amount; i++)
                c.inc1000();
            break;
        case 'r':
            c.reset();
            break;
        case 'o':
            cout << (!c.overflow() ? "The counter is not full." : "The counter is full") << endl;
            break;
        default:
            return;
            break;
    }

    c.output();
}
