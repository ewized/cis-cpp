/*
    Filename: rainfall.cpp
    Problem: #1 pg 429
    Description: Write a program that reads in the average monthly rainfall
        for a city for each month of the year and then reads in the actual
        monthly rainfall for each of the previous 12 months. The program
        then prints out a nicely formated table show the rainfall for each
        of the previous 12 months as well as how much above or bellow the
        average the rain fall for each months.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 10/22/2013
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function declaration.
void get_in_file(ifstream&, const char*);
void get_out_file(ofstream&, const char*);
void add_month_data(ifstream&, double []);
void add_month_names(string []);
void print_chart(ofstream&, string [], double [], double []);
void print_graph(ofstream&, string [], double [], double []);
double get_average(double, double);
string print_dots(double);

// Constant declaration
const char FILE_ONE[32] = "rainfall_current.dat";
const char FILE_TWO[32] = "rainfall_previous.dat";
const char FILE_OUT[32] = "rainfall_output.dat";
const int MONTH_SIZE = 12;

// Master all of them!
int main() {
    // Get the files loaded.
    ifstream rainfall_current, rainfall_previous;
    ofstream rainfall_output;
    get_in_file(rainfall_current, FILE_ONE);
    get_in_file(rainfall_previous, FILE_TWO);
    get_out_file(rainfall_output, FILE_OUT);

    // Fill the arrays with data from the files.
    double current[MONTH_SIZE], previous[MONTH_SIZE];
    string months[MONTH_SIZE];
    add_month_names(months);
    add_month_data(rainfall_current, current);
    add_month_data(rainfall_previous, previous);

    // Print out the nice chart
    print_chart(rainfall_output, months, current, previous);
    print_graph(rainfall_output, months, current, previous);

    // Close writing file.
    rainfall_output.close();
    return 0;
}

// Get the average of current and previous results.
// @return average of both numbers
double get_average(double current, double previous) {
    double result = (current+previous)/2;
    double final = result;
    if(result < current) {
        final *= -1;
    }
    return final;
}

// Print dots like no today.
string print_dots(double ammount) {
    string dots = "*";
    for(double i = 0; i < ammount;i+=0.1) {
        dots += "*";
    }
    return dots;
}

// Print out the graph with fancy data.
void print_graph(ofstream& file, string month[], double current[] , double previous[]) {
    file << "--------------------" << endl;
    for(int i = 0; i < MONTH_SIZE;i++) {
        file << month[i] << " - GRAPH" << endl;
        file << "--------------------" << endl;
        file << " Current Year: " << print_dots(current[i]) << endl;
        file << "      Average: " << print_dots(get_average(current[i], previous[i])) << endl;
        file << "--------------------" << endl;
    }
    file << endl;
}

// Print out the chart with the data in the chart.
void print_chart(ofstream& file, string month[], double current[] , double previous[]) {
    file.setf(ios::fixed);
    file.setf(ios::showpoint);
    file.precision(2);
    file << "--------------------" << endl;
    for(int i = 0; i < MONTH_SIZE;i++) {
        file << month[i] << " - CHART"  << endl;
        file << "--------------------" << endl;
        file << " Current Year:  " << current[i] << endl;
        file << "Previous Year:  " << previous[i] << endl;
        file.setf(ios::showpos); // Show the positive or negative number.
        file << "      Average: " << get_average(current[i], previous[i]) << endl;
        file.unsetf(ios::showpos); // Clear the flag.
        file << "--------------------" << endl;
    }
    file << endl;
}
// Fill an array with the month names.
void add_month_names(string months[]) {
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";
}

// Get data from file and fill it in the array.
void add_month_data(ifstream& file, double month[]) {
    double data;
    for(int i = 0;i < MONTH_SIZE;i++) {
        file >> data;
        month[i] = data;
    }
}

// Get the output file
void get_out_file(ofstream& file, const char* file_name) {
    file.open(file_name);
    if (file.fail()) {
        cout << "WARRING: " << file_name << " can't be opened." << endl;
        exit(1);
    }
    cout << "NOTICE: " << file_name << " opened successfully." << endl;
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
