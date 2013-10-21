/*
    Filename: math.cpp
    Problem: #2 Pg 364
    Description: Write a program that takes its input from a file of numbers
        of type double and out put the average of the numbers in the file
        to the screen. The file contains nothing but numbers of the type
        double separated by blanks and/or line breaks.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 10/7/2013
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Function declarations.
double get_average(ifstream&);
void output_average(double);

// Constant declaration.
const char FILE_NAME[15] = "input.dat";

// The simple but yet powerful main function.
int main()
{
    ifstream file;
    file.open(FILE_NAME);

    if (file.fail())
    {
        cout << "WARRING: '" << FILE_NAME << "' can not be opened." << endl;
        exit(1);
    }

    double average = get_average(file);
    output_average(average);

    file.close();
   
    return 0;
}

// Get the average of the list of numbers.
double get_average(ifstream& file)
{
    int next, count = 0;
    double sum = 0;

    cout << "The numbers from the file are bellow." << endl;

    while (file >> next)
    {
        count++;
        cout << next << " ";
        sum = sum + next;
    }

    cout << endl;
    return sum / count;
}

// Output the average in fancy format.
void output_average(double average)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "The average of the numbers in the file is '"
         << average << "'." << endl;
}
