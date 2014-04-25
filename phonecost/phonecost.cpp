/*
 File: phonecost.cpp
 Description: Write the program that computes the cost of a
    long-distance call. the cost of the call is determined
    according to the following rate schedule.
 Created: 9/17/2013
 Author: Joshua Rodriguez
 mail: ewized@gmail.com
*/
#include <iostream>

using namespace std;
// Global Vars
const double WEEKEND_PRICE = 0.15;
const double WEEKDAY_DAY_PRICE = 0.40;
const double WEEKDAY_NIGHT_PRICE = 0.25;

int main()
{
    // Store the vars.
    double caculateCost(double callLength, double callTime);
    int hour, minute;
    char dayOne, dayTwo, colon;
    double callTime, callLength, callPrice;
    string repeatProgram;

    // Loop the code only if the user types yes.
    do
    {
        // Take the input of the day of the week.
        // Take the input of the time the call was started. (use 24 hour time.)
        // Take in the length of the phone call.
        cout << "| Mo | Tu | We | Th | Fr | Sa | Su |" << endl;
        cout << "Enter the first two letter for the week: ";
        cin >> dayOne >> dayTwo;
        cout << "Enter the time the call started on use (24 hour clock ex 13:00) : ";
        cin >> hour >> colon >> minute;
        callTime = (hour*100) + minute; // Remove the colon
        cout << "Enter the lenght of the call: ";
        cin >> callLength;

        // Caculate the cost of the phone call.
        // 1800 is 6:00pm 800 is 8:00 am
        if (dayOne == 'M' || dayOne == 'm') // It has to be monday.
        {
            callPrice = caculateCost(callLength, callTime);
        }
        else if (dayOne == 'T' || dayOne == 't') // Is it Tuesday or Thursday.
        {
            if (dayTwo == 'U' || dayTwo == 'u') // Tuesday.
            {
                callPrice = caculateCost(callLength, callTime);
            }
            else // Its Thursday.
            {
                callPrice = caculateCost(callLength, callTime);
            }
        }
        else if (dayOne == 'W' || dayOne == 'w') // Has to be wedsday.
        {
            callPrice = caculateCost(callLength, callTime);
        }
        else if (dayOne == 'F' || dayOne == 'f') // Has to be friday.
        {
            callPrice = caculateCost(callLength, callTime);
        }
        else // It must be a weekend.
        {
            callPrice = callLength * WEEKEND_PRICE;
        }

        // Output the price of the phone call plus deails.
        cout << "The phone call was started on " << dayOne << dayTwo << " at " << hour << ":" << minute << endl;
        cout << "The call lasted " << callLength << " mins the cost of that call is $" << callPrice << endl;

        // Ask the user to loop the code.
        cout << "Type 'yes' to repeat the game anything else will end the game: ";
        cin >> repeatProgram;

    } while(repeatProgram == "yes" && repeatProgram != "");

    return 0;
}

double caculateCost(double callLength, double callTime)
{
    double callPrice;

    if (callTime >= 800 && callTime <= 1800) // Is it during work hours 800 through 1800
    {
        callPrice = callLength * WEEKDAY_DAY_PRICE;
    }
    else // Must be mornings or nights.
    {
        callPrice = callLength * WEEKDAY_NIGHT_PRICE;
    }

    return callPrice;
}
