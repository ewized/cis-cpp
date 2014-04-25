/*
    Filename: computerlab.cpp
    Problem: #5 pg 520
    Description: You run four computer labs. Each lab contains computer
        stations that are numbered shown.
        Each user has a unique five-digit ID number. When ever a user logs on,
        the user's ID, lab number, and the computer station number are
        transmitted to you system. For example, if the user 49193 2 3 as input
        data. Similarly, when a user logs off a station, then your system gets
        the lab number and computer station.
        Write a computer program that could be used to track, by lab, which
        user is logged onto which computer. For example, if user 49193 logged
        into station 2 in lab 3 and user 99577 is logged into station 1 of lab
        4 then your system might display the following.
        Create a menu that allows the administrator to makeup the transmission
        of information by manually typing in the user login logout data.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 11/14/2013
*/
#include <iostream>

using namespace std;

// Function declaration
int get_menu();
void store_data(int, int, int);
void search_user(int);
bool process_menu(int);
void set_data();
void print_data();

// Constant vars
const int LABS = 4;

// The Labs
int *labs[LABS];
int lab_size[LABS];
typedef int* Stations;

int main() {
    set_data();
    while(process_menu(get_menu()));
    return 0;
}

// Set up the data
void set_data() {
    for (int i=0;i<LABS;i++) {
        int answer;
        cout << "Enter the number of computers in lab " << i+1 << ": ";
        cin >> answer;
        lab_size[i] = answer;
        labs[i] = new int[answer];
    }
}

// Show and get the user's menu selection.
int get_menu() {
    int results;   
    const int MENU = 3;
    do {
        cout << "0: Exit Program" << endl;
        cout << "1: Enter user data" << endl;
        cout << "2: Search user data" << endl;
        cout << "3: Print chart" << endl;
        cout << "Select the number you want then press enter: ";
        cin >> results;
    } while (results < 0 && results > MENU); 

    return results;
}

// Process what to do with the user's input.
bool process_menu(int input) {
    switch (input) {
        case 0:
            return false;
        case 1:
            int id, station, lab;
            cout << "If user ID is 0 that means they loged off." << endl;
            cout << "Enter the users ID: ";
            cin >> id;
            cout << "Enter the station #: ";
            cin >> station;
            cout << "Enter the lab #: ";
            cin >> lab;
            store_data(id, station, lab);
            break;
        case 2:
            int user;
            cout << "Enter the user ID to search for: ";
            cin >> user;
            search_user(user);
            break;
        case 3:
            print_data();
            break;
    }
    return true;
}

// Store the data in the array.
void store_data(int id, int station, int lab) {
    Stations temp = labs[lab-1];
    temp[station-1] = id;
}

// Search for the user and print the chart.
void search_user(int id) {
    int lab, station;
    for (int i=0; i < LABS; i++) {
        Stations temp = labs[i];
        for (int j=0; j < lab_size[i]; j++) {
            if (temp[j] == id) {
                lab = i+1;
                station = j+1;
                break;
            }
        }
    }
    if (lab != 0 && station != 0) {
        cout << "User " << id                 // User ID
             << " is on lab " << lab          // Lab #
             << " and station " << station    // Station #
             << "." << endl;
    }
    else {
        cout << "User not login." << endl;
    }
}

//  Prints the chart
void print_data() {
    for (int i=0; i < LABS; i++) {
        cout << "Lab " << i+1 << ": ";
        Stations temp = labs[i];
        for (int j=0; j < lab_size[i]; j++) {
            cout << "Station " << j+1 << ": ";
            if (temp[j] == 0) {
                cout << "Empty ";
            }
            else {
                cout << temp[j] << " ";
            }
        }
        cout << endl;
    }
}
