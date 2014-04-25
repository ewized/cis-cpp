/*
    Filename: driver.cpp
    Problem: chapter 15 number 7 page 860
    Description:  Make a stud thiungy to play around with
        the inheritance.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 03/20/2014
*/
#include <iostream>
#include "triangle.h"
#include "rectangle.h"

using namespace std;

int main() {
    Triangle t;
    t.draw();
    cout << "Derived class Triangle calling center" << endl;
    t.center();
    Rectangle r;
    r.draw();
    cout << "Derived class Rectange calling center" << endl;
    r.center();
    return 0;
}
