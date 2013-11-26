/*
    Filename: month.cpp
    Problem: Problem 6 from Chapter 10.
    Description: Define a class Month that is an abstract data type for month.
        Your class will have one member variable of type int to represent the
        a month. Include all the following member functions. Create a
        constructor that will set the month with by the first 3 letters or a
        number. Create getter for month that will let you get the
        number or the first three letters of the month. Create setters that
        will set the month using the first three letters or a number.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 11/26/2013
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Month {
    private:
        int month;
    public:
        Month(int);
        Month(string);
        Month();
        void set_month(int);
        void set_month(string);
        int get_month_index();
        string get_month_name();
};

// Set the month with an int.
Month::Month(int index) {
    set_month(index);
}

// Set the month with a string.
Month::Month(string name) {
    set_month(name);
}

// Set the default month.
Month::Month() {
    month = 1;
}

// Set the month according to an int.
void Month::set_month(int index) {
    if (index < 1 || index > 12) {
        cout << "WARNING: Month is not right. Setting to 1" << endl;
        month = 1;
        return;
    }
    month = index;
}

// Set the month according to a string.
void Month::set_month(string name) {
    if (name == "jan")
        set_month(1);
    else if (name == "feb")
        set_month(2);
    else if (name == "mar")
        set_month(3);
    else if (name == "apr")
        set_month(4);
    else if (name == "may")
        set_month(5);
    else if (name == "june")
        set_month(6);
    else if (name == "july")
        set_month(7);
    else if (name == "aug")
        set_month(8);
    else if (name == "sept")
        set_month(9);
    else if (name == "oct")
        set_month(10);
    else if (name == "nov")
        set_month(11);
    else if (name == "dec")
        set_month(12);
    else {
        cout << "WARNING: Month is not right. Setting to 1" << endl;
        set_month(1);
    }
}

// Get the month name.
string Month::get_month_name() {
    switch (month) {
        case 1: 
            return "Jan";
        case 2: 
            return "Feb";
        case 3: 
            return "Mar";
        case 4: 
            return "Apr";
        case 5: 
            return "May";
        case 6: 
            return "June";
        case 7: 
            return "July";
        case 8: 
            return "Aug";
        case 9:
            return "Sept";
        case 10: 
            return "Oct";
        case 11: 
            return "Nov";
        case 12: 
            return "Dec";
    }
    return "Jan";
}

// Get the month index.
int Month::get_month_index() {
    return month;
}

int main() {
    // Declare
    Month m;
    cout << "Month Index: " << m.get_month_index() << endl;
    cout << "Month Name: " << m.get_month_name() << endl;
    cout << endl;

    // Set
    m.set_month(2);
    cout << "Month Index: " << m.get_month_index() << endl;
    m.set_month("mar");
    cout << "Month Name: " << m.get_month_name() << endl;
    cout << endl;

    return 0;
}
