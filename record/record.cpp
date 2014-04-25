/*
    Filename: record.cpp
    Problem: Extra
    Description: Write a definition for a structure type for
        records consisting of a person’s wage rate, accrued
        vacation (in whole days), and status (hourly or salaried).
        Represent the status as one of the two character values
        ‘H’ and ‘S’. Call the type EmployeeRecord.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/24/2014
*/
#include <iostream>

using namespace std;

struct EmployeeRecords {
    int work_hours;
    int vacation_hours;
    char type; /* H|S */

    EmployeeRecords() {
        work_hours = 0;
        vacation_hours = 0;
        type = 'H';
    }
};

int main() {
    // Example
    EmployeeRecords r;
    cout << "Work hours: " << r.work_hours << endl;
    cout << "Vacation hours: " << r.vacation_hours << endl;
    cout << "Work Type: " << r.type << endl;

    return 0;
}
