/*
    Filename: ABC.cpp
    Description: Midterm part 2
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 03/27/2014
*/
#include <iostream>

using namespace std;

// A
class A {
    public:
        A() { cout << "A" << endl; };
};

// B
class B {
    public:
        B() { cout << "B" << endl; };
};

// C
class C : public A {
    public:
        void b() { B b; };
};

int main() {
    C c;
    return 1;
}
