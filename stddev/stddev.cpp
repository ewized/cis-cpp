/*
    Filename: stddev.cpp
    Problem: #4 pg 430
    Description: The standard deviation of a list of numbers is a measure
        of how much the number deviate from the average. If the standard
        deviation is small, the numbers are clustered close to the average.
        If the standard deviation is large, the umbers are scattered far
        from the average. The standard deviation, S, of a list of N numbers
        x is defined. Where x is the average of the N number x1, x2, ...
        Define a function that takes a partially filled array of numbers as
        its arguments and returns the standard deviation of the numbers in
        the partially filled array. Since a partially filled array requires
        two parameter and a formal parameter of type it that gives the
        number of array positions used. The umbers in the array will be type
        double.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 10/24/2013
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

// Function declarations
double get_average(double [], int);
double get_summation(double [], int); 
double get_standard_devation(double [], int);
void get_in_file(ifstream&, const char*);
int fill_array(ifstream&, double [], int);

// The master function.
// @return awesomeness
int main() {
    // Load the file.
    const char FILENAME[32] = "stddev.dat";
    ifstream file;
    get_in_file(file, FILENAME);

    // Fill the array from file.
    const int SIZE = 10;
    double array[SIZE];
    int true_size = fill_array(file, array, SIZE);

    // Print out the results.
    cout << "The standard deviation from the file is: ";
    cout << get_standard_devation(array, true_size) << endl;

    return 0;
}

// Fill an array with data from a file.
// @return size of the file
int fill_array(ifstream& file, double array[], int size) {
    int count = 0;
    double data;
    while(file >> data && count < size) {
        array[count] = data;
        count ++;
    }
    return count;
}

// Gets the average of the array.
// @return average
double get_average(double array[], int size) {
    double average = 0;
    for(int i = 0;i < size; i++) {
        average += array[i];
    }
    return average/size;
}

// Get the summation of an array.
// @return summation
double get_summation(double array[], int size) {
    double average = get_average(array, size);
    double summation = 0;
    for(int i = 0;i < size;i++) {
        summation += pow(array[i] - average, 2);
    }
    return summation;
}

// Get the standard deviation of an array.
// @return standard deviation
double get_standard_devation(double array[], int size) {
    double summation = get_summation(array, size);
    return sqrt(summation/(size - 1));
}

// Get the input file.
void get_in_file(ifstream& file, const char* file_name) {
    file.open(file_name);
    if (file.fail()) {
        cout << "WARRING: " << file_name << " can't be opened." << endl;
        exit(1);
    }
    cout << "NOTICE: " << file_name << " opened successfully." << endl;
}
