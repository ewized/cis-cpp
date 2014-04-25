#include <iostream>
#include "rectangle.h"

using namespace std;

void Rectangle::erase() {
    cout << "ERASE FROM RECTANGLE" << endl;
}

void Rectangle::draw() {
    cout << "DRAW FROM RECTANGLE" << endl;
}

void Rectangle::center() {
    cout << "CENTER FROM RECTANGLE" << endl;
    erase();
    draw();
}
