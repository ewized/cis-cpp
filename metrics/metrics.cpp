/*
	File: metrics.cpp
	Problem: #6-8 pg 294
	Description: Write a program that reads in a length in feet and inches 
		and outputs the equivalent length in meters and cenimeters. Use
		at least three functions: loop that lets the user repeate the
		program for new input values untill the user says he or she wants
		to end the program. There are 0.3048 meters in a foot, 100
		centimeters ina meter, and 12 inches in a foot.

		Write a program like that of the previous exercise that converts
		from meters and centimeters into feed and inches. Use function
		for the subtasks.

		Write a program that combines the function in the previous two
		projects. The program asjs the user if he or she wants to convert
		from feet and inches to meters and cenitmeters or visa versa. The
		program reads the user's answer and then excutes an if-else
		statement. Each branch of the if-else statement will be a function
		call. The two functions called in the if else-statement will have 
		functions that are simler to the last two projects. Thus, they will
		be fairly complicated function definitions that call other functions
		in their functions bodies. Include a loop that lets the user repeate
		this computation for new input values untill they say stop it!!!
	Name: Joshua Rodriguez
	Email: ewized@gmail.com
	Date: 9/26/2013
*/
#include <iostream>

using namespace std;

// Declare the functions.
int getProblem();
bool getRepeat();
void getMetersCentimeters(double, double);
void getFeetInches(double, double);
double getMeters();
double getCentimeters();
double getInches();
double getFeet();

// Define the constants
const double METERSFOOT = 0.3048; // there are 0.3048 meters in a foot.
const double CENTIMETERSINCH = 2.54; // There are 2.54 centimeters in a inch.

// The main function that will rule them all!!!
int main()
{
	do
	{
		int problem =  getProblem();
		if (problem == 1) // Converts Feet/Inches to meters/Centimeters
		{
			double feet = getFeet();
			double inches = getInches();
			getMetersCentimeters(feet, inches);
		}
		if (problem == 2) // Converts Meters/Centimeters to Feet/Inches
		{
			double meters = getMeters();
			double centimeters = getCentimeters();
			getFeetInches(meters, centimeters);
		}
	} while (getRepeat());
	return 0;
}

// Print out the conversion
void getMetersCentimeters(double feet, double inches)
{
	feet = feet * METERSFOOT;
	inches = inches * CENTIMETERSINCH;
	cout << "Feet to Meters: " << feet << endl;
	cout << "Inches to Centimeters: " << inches << endl;
}

// Print out the conversion
void getFeetInches(double meters, double centimeters)
{
	meters = meters / METERSFOOT;
	centimeters = centimeters / CENTIMETERSINCH;
	cout << "Meters to Feet: " << meters << endl;
	cout << "Centimeters to Inches: " << centimeters << endl;
}

// Ask the user to input feet to convert.
double getFeet()
{
	double feet;
	cout << "Enter the feet to convert: ";
	cin >> feet;
	return feet;
}

// Asks the user to enter inches.
double getInches()
{
	double inch;
	cout << "Enter the inches to convert: ";
	cin >> inch;
	return inch;
}

// Asks the user to enter meters.
double getMeters()
{
	double meter;
	cout << "Enter the meter to convert: ";
	cin >> meter;
	return meter;
}

// Ask the user to enter centimeters.
double getCentimeters()
{
	double centimeters;
	cout << "Enter the centimeters: ";
	cin >> centimeters;
	return centimeters;
}

// Ask the user to figure out which problem to do.
int getProblem()
{
	int problem;
	do
	{
		cout << "1. Feet/Inches to Meters/Centimeters" << endl
			 << "2. Meters/Centimeters to Feet/Inches" << endl
			 << "Enter the number for the problem you want to do: ";
		cin >> problem;
	} while (problem < 0 || problem > 2);
	return problem;
}

// Ask the user to repeate the program with error correction.
bool getRepeat()
{
	char answer = 'n';
	do
	{
		cout << "Repeat? Type 'y/n': ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			return true;
		}
		else if (answer == 'n' || answer == 'N')
		{
			return false;
		}
	} while (answer != 'Y' && answer != 'y' 
		  && answer != 'N' && answer != 'n');
}
