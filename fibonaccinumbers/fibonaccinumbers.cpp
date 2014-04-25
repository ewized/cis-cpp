/*
 File: fibonaccinumbers.cpp
 Description: Assume that the green curd population growth at this rate and has a time
              period of 5 days. Hence, if a green crud is still 10 pounds starts out as
              10 pounds of crud, then in 5 days there is still 10 pounds of curd; in 10 days
              there is 20 pounds of crud, in 15 days 30 pounds, in 20 days 50 pounds, and
              so forth.

              Write a program that takes both the initial size of green crud population (in pounds)
              and a number of days as input, and that outputs the number of pounds of green crud after that
              many days. Assume that the population size is the same for 4 days and then increases every fith
              day. Your program should allow the user to repeate this calculation as offten as desired.
 Created: 9/17/2013
 Author: Joshua Rodriguez
 mail: ewized@gmail.com
*/
#include <iostream>

using namespace std;
int askForPounds();
int askForDays();
bool askForRepeat();
void getResults(int pounds, int days);


int main()
{
    // Loop program is user wants to.
    do
    {
        int pounds = askForPounds();
        int days = askForDays();
        getResults(pounds, days);

    } while (askForRepeat());

    return 0;
}

// Ask for the weight of green crud in pounds.
int askForPounds()
{
    int pounds;
    do
    {
        cout << "Enter the pounds of green crud: ";
        cin >> pounds;
    } while (pounds < 0);
    return pounds;
}

// Ask for the number days.
int askForDays()
{
    int days;
    do
    {
        cout << "Enter the amount of days: ";
        cin.ignore() >> days;
    } while (days < 0);
    return days;
}

// Caculate and output results
void getResults(int pounds, int days)
{
    int futurePounds = pounds;
    int newFibNum, fibOne = 1, fibTwo = 1;
    const int DOUBLEDAY = 5;

    for (int i = 1; i < days; i++)
    {
        newFibNum = fibOne + fibTwo;
        fibTwo = fibOne;
        fibOne = newFibNum;

        if (i % DOUBLEDAY == DOUBLEDAY - 1)
        {
            futurePounds = futurePounds + newFibNum;
        }
    }

    cout << "Start: Your curd is " << pounds << " pounds." << endl;
    cout << "End: You curd in " << days << " days is " << futurePounds << " pounds." << endl;
}

// Ask to loop program
bool askForRepeat()
{
    char answer;
    cout << "Do you want to repeat the program, enter Y/N: ";
    cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        return true;
    }
    else if (answer == 'N' || answer == 'n')
    {
        return false;
    }
    askForRepeat();
}
