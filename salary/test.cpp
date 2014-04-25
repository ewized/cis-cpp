/*
    Filename: test.cpp
    Problem: chapter 15 number 1
    Description: Extend SalariedEmplyee and add the require member functions;
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 03/06/2014
*/
#include <iostream>
#include "administrator.h"

using namespace std;

int main() {
    Administrator a;

    a.set_title("CEO");
    a.set_area("eveything");
    a.set_supervisor("no one");

    a.print();
    a.print_check();

    return 0;
}
