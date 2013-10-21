/*
 File: leapyear.cpp
 Description: Is the current year a leap year.
 Created: 9/12/2013
 Author: Joshua Rodriguez
 mail: ewized@gmail.com
*/
#include <iostream>

using namespace std;

int main()
{
    // Define the varible.
    int leapYear;

    // Repeat the program untill user says no
    do
    {
        // Ask and set the varible.
        cout << "Enter a year (type 0 to end): ";
        cin >> leapYear;

        // Break the loop if a number less then 1
        if (leapYear <= 0)
        {
            cout << "Good Bye";
            break;
        }

        // Print out the results and do the check at the same time.
        if ((leapYear % 4 == 0) && (leapYear % 100 != 0) || (leapYear % 400 == 0))
        {
            // Is a leap year.
            cout << leapYear << " is a leap year." << endl;
        }
        else
        {
            // Not a leap year.
            cout << leapYear << " is not a leap year." << endl;
        }

    } while (leapYear > 0);


    return 0;
}
