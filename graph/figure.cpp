#include <iostream>
#include "figure.h"

using namespace std;

void Figure::erase() {
    cout << "ERASE FROM FIGURE" << endl;
}

void Figure::draw() {
    cout << "DRAW FROM FIGURE" << endl;
}

void Figure::center() {
    cout << "CENTER FROM FIGURE" << endl;
    erase();
    draw();
}
