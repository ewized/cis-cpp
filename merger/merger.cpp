/*
    Filename: merger.cpp
    Problem: #7 pg 365
    Description: Write a program that merges the numbers in two files and
        writes all the numbers into a third file. Each input file contain
        a list of numbers type int in sorted order from the smallest to
        largest. After the program is run, the output file will contain
        all the numbers in the two input files in one longer list in sorted
        order from smallest to largest. Your program should define a
        function that is called when the two input-files streams and the
        output-file stream as three arguments.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 10/7/2013
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function declaration.
void get_in_file(ifstream&, const char*);
void get_out_file(ofstream&, const char*);
void caculate_write(ifstream&, ifstream&, ofstream&);

// Constant declaration
const char FILE_ONE[15] = "input1.dat";
const char FILE_TWO[15] = "input2.dat";
const char FILE_OUT[15] = "output.dat";

int main()
{
    // Make the objects exist.
    ifstream file_one, file_two;
    ofstream file_out;

    // Open the files to be used.
    get_in_file(file_one, FILE_ONE);
    get_in_file(file_two, FILE_TWO);
    get_out_file(file_out, FILE_OUT);
 
    // Merge the numbers in the file and write.
    caculate_write(file_one, file_two, file_out);

    // Close the open files for safety.
    file_one.close();
    file_two.close();
    file_out.close();

    return 0;
}

// The back bone to do the math and write to the file.
void caculate_write(ifstream& file_one, ifstream& file_two, ofstream& file_out)
{
    cout << "Calculation starting..." << endl; // Notify the console.

    int number_one, number_two, temp;
    file_two >> number_two;

    // This would be so much easer with an array. But I guess the point of
    // this assignment is to use a loop in a loop, loop inception.
    while (true) 
    {
        file_one >> number_one;
        // When the first file is over finish the second if needed.
        if (file_one.eof())
        {
            while (file_two >> number_two)
            {
                file_out << number_two << endl;
            }
            break; // Kill the loop.
        }
        else
        {
            // Decide on which number to print to file.
            if (number_one < number_two)
            {
                file_out << number_one << endl;
            }
            else if (number_one > number_two)
            {
                file_out << number_two << endl;
            } 
            else
            {
                file_out << number_one << endl;
                file_out << number_two << endl;
                file_two >> number_two; // Get the next number from file two.
            } 
        }
    }
    cout << "Calculation finished..." << endl; // Notify the console.
}

// Get the output file
void get_out_file(ofstream& file, const char* file_name)
{
    file.open(file_name);
    if (file.fail())
    {
        cout << "WARRING: " << file_name << " can't be opened." << endl;
        exit(1);
    }
    cout << "NOTICE: " << file_name << " opened successfully." << endl;
}

// Get the input file.
void get_in_file(ifstream& file, const char* file_name)
{
    file.open(file_name);
    if (file.fail())
    {
        cout << "WARRING: " << file_name << " can't be opened." << endl;
        exit(1);
    }
    cout << "NOTICE: " << file_name << " opened successfully." << endl;
}
