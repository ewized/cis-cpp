/*
    Filename: Hierarchy.cpp
    Description: Midterm part 2
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 03/27/2014
*/
#include <iostream>

using namespace std;

// One
class One {
    public:
        One() { cout << "START ONE" << endl; };
        ~One() { cout << "END ONE" << endl; };
};

// Two Deep
class Two : public One {
    public:
        Two() { cout << " START TWO" << endl; };
        ~Two() { cout << " END TWO" << endl; };
};

// Three Deep
class Three : public Two {
    public:
        Three() { cout << "  START THREE" << endl; };
        ~Three() { cout << "  END THREE" << endl; };
};

int main() {
    Three three;
    return 1;
}
