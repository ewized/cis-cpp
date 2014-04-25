/*
    Filename: doctor.cpp
    Problem: chapter 15 number 3 page 858
    Description: Make a doctor awesome class 
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 03/20/2014
*/
#include <iostream>
#include "doctor.h"

using namespace std;

int main() {
    Doctor d;
    cout << "Setting the doctors fee to 5.5" << endl;
    d.set_fee(5.5);
    cout << d.get_fee() << endl;
    cout << "Setting the doctors special to General" << endl;
    d.set_special("General");
    cout << d.get_special() << endl;

    cout << "Copying the doctor" << endl;

    Doctor b(d);

    cout << b.get_fee() << endl;
    cout << b.get_special() << endl;


    cout << "Overloading the inseration operator" << endl;
    cout << d;

    return 0;
}
