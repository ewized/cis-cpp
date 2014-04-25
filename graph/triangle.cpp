#include <iostream>
#include "triangle.h"

using namespace std;

void Triangle::erase() {
    cout << "ERASE FROM TRIANGLE" << endl;
}

void Triangle::draw() {
    cout << "DRAW FROM TRIANGLE" << endl;
}

void Triangle::center() {
    cout << "CENTER FROM TRIANGLE" << endl;
    erase();
    draw();
}
