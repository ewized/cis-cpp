/*
	File: time.cpp
	Problem: #3 pg 293
	Description Write a program that requests the current time and waiting
		time as two intergers for the number og hors and the number of
		minutes to wait. The program then outputs what the time will be
		after the waiting period. Use 24-hour notation for the time. Include
		a loop to let the user repeate the prgram.

		Now make it so that it will use the 12 hour notation.
	Name: Joshua Rodriguez
	Email: ewized@gmail.com
	Date: 9/27/2013
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function declaration.
bool getRepeat();
int getHour(bool);
int getMinute();
char getTime();
int convertTwentyFour(int, int, char);
void outputTime(int, int);

// Rule them all with the main function!
int main()
{
	do
	{
        // Get the starting time
		cout << "Enter the current time: " << endl;
		int startHour = getHour(true);
		int startMinute = getMinute();
		char startTime = getTime();

        // Get the time to run against.
        cout << "Enter the time to wait: " << endl;
        int waitHour = getHour(false);
		int waitMinute = getMinute();

        // Do the math to get the wait time.
        int sTime = convertTwentyFour(startHour, startMinute, startTime);        
        int wTime = waitHour * 100 + waitMinute;

        // Output the time after the wait.
        cout << "The time after the wait will be: ";
        outputTime(sTime, wTime);

	} while (getRepeat());

	return 0;
}

// Ask the user to repeat the program.
bool getRepeat()
{
	char a; // This is answer
	do
	{
		cout << "Repeat? Enter 'y/n': ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			return true;
		}
		else if (a == 'N' || a == 'n')
		{
			return false;
		}
	} while (!(a == 'Y' || a == 'y' || a == 'N' || a == 'n'));
}

// Ask the user for the hour. If limit is true only use 12 hours.
int getHour(bool limit)
{
	int hour;
	do
	{
		cout << "Hour: ";
        cin >> hour;
    } while (!(hour > 0 && hour <= 12 || !limit && hour <= 12));
	return hour;
}

// Ask the user for the minute.
int getMinute()
{
	int minute;
	do
	{
		cout << "Minute: ";
		cin >> minute;
	} while (!(minute >= 0 && minute < 60));
	return minute;
}

// Ask the user for time of day ex AM/PM
char getTime()
{
	char time, temp;
	do
	{
		cout << "AM/PM: ";
        cin >> time >> temp;
	} while(!(time == 'a' || time == 'A' || time == 'p' || time == 'P'));

	if (time == 'a' || time == 'A')
	{
		return 'A';
	}
	else if (time == 'p' || time == 'P')
	{
		return 'P';
	}
}

// Convert the time to 24 hour time.
int convertTwentyFour(int hour, int minute, char time)
{
    // Convert time to 24 hour format.
    if (time == 'P' && hour != 12)
    {
        hour = hour + 2;
        return (hour * 100) + minute;  
    }
    else if (time == 'A' && hour == 12)
    {
        return minute;
    }
    // All else fais this is the answer.
    return (hour * 100) + minute;    
}

// Output time
void outputTime(int startTime, int waitTime)
{
    int endTime = startTime + waitTime;
    int endHour = endTime / 100;
    int endMinute = endTime - (endHour * 100);
    int finalHour;
    string finalTime;

    // Get the right hour.
    if (endTime > 1159)
    {
        finalHour = 12 - endHour;
        finalTime = " PM";
    }
    else
    {
        if (!(endHour <= 2))
        {
            finalHour = 2 - endHour;
        }
        else
        {
            finalHour = 12;
        }
        finalTime = " AM";
    }
    
    // Display the right minute.
    if (endMinute < 10)
    {
        cout << abs(finalHour) << ":0" << endMinute << finalTime  << endl;
    }
    else
    {
        cout <<  abs(finalHour) << ":" << endMinute << finalTime << endl;
    }
}
