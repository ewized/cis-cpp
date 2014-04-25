/*
    Filename: vitamin.cpp
    Description: The Bite-a Vite-a vitamin store needs an "expert" 
computer programmer to help keep track of their inventory. The store 
maintains all their vitamin stock information on disk. The data is organized 
as follows:

The first column contains the vitamin name (A, B, C, etc.)

The second column contains the unit price of a single jar of that particular 
vitamin.

The third column has the number of jars of that vitamin in the store.

For example:

A   12.95   23
K   9.99    56
Z   6.99    25

Write a C++ program that will do the following:

1. Read data from the keyboard in the form

vitamin price quantity

2. Call a function that will return the total value of the store's inventory
for that one vitamin product (unit_price * number_of_jars).

You will also calculate:
The average price of a vitamin

The total inventory (total number of jars)

Print the output so that it is organized as follows:
Vitamin Price Inventory Total Inventory

--------------------------------------------------

A   12.95   23  297.85
K   9.99    56  559.44
Z   6.99    25  174.75


The average price for a vitamin is: $9.98

The total store inventory is 104 jars of vitamins
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 12/12/2013
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function declaration
void input(string, double, int, int);
void output(string, double, int, int);
int get_average(double [], int);
int get_total(double, int);

// Get the user's input
// @param name The names of the stock
// @param price The price of the stock
// @param amount The amount of the stock
void input(string name[], double price[], int amount[], int size) {
    // Temp store the current arrays
    /*
    string* names = new string[size];
    double* prices = new double[size];
    int* amounts = new int[size];
    for (int i = 0; i < size; i++) {
        names[i] = name[i];
        prices[i] = prices[i];
        amounts[i] = amount[i];
    }
    */

    // Temp store current and ask the user.
    //string current_name;
    //double current_price;
    //int current_amount;
    cout << "Enter the name: ";
    //cin >> current_name;
    cin >> name[size];
    cout << "Enter the price: ";
    //cin >> current_price;
    cin >> price[size];
    cout << "Enter the amount: ";
    //cin >> current_amount;
    cin >> amount[size];

    // Resize the storage array.
    /*
    delete [] name;
    delete [] price;
    delete [] amount;
    name = new string[size+1];
    price = new double[size+1];
    amount = new int[size+1];

    // Fill the new array size :)
    for (int i = 0; i < size+1; i++) {
        if (i==size) {
            name[i] = current_name;
            price[i] = current_price;
            amount[i] = current_amount;
        }
        else {
            name[i] = names[i];
            price[i] = prices[i];
            amount[i] = amounts[i];
        }
    }
    */
}

// Get the average of the array.
// @param stock The array of each price
// @param amount The size of the array.
int get_average(double stock[], int amount) {
    double results;
    for (int i = 0; i < amount; i++)
        results += stock[i];
    return results / amount;
}

// Get the product of the current stock.
// @param price The price of the current item.
// @param amount The amount of items that are in the stock..
int get_total(double price, int amount) {
    return price * amount;
}

// Output the data nicely.
// @param name The names of the stock
// @param price The price of the stock
// @param amount The amount of the stock
void output(string name[], double price[], int amount[], int size) {
    // Size checker
    if (size <= 0) {
        cout << "Error no data stored" << endl;
        return;
    }

    // TEMP VARS
    int total = 0;
    double average[size];

    // Split the results from the input.
    for (int i = 0; i < 70; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < size; i++) {
        average[i] = amount[i];
        total += amount[i];
        // Print the results
        cout << name[i] << "   ";
        cout << price[i] << "   ";
        cout << amount[i] << "   ";
        cout << get_total(price[i], amount[i]);
        cout << endl;
    }

    // General Info
    cout << "The average price for a vitamin is: $"
         << get_average(average, size) << endl;
    cout << "The total store inventory is " << total << " jars." << endl;
}

// MASTER THEM ALL!!!
int main() {
    // Type define.
    typedef string* Name;
    typedef double* Price;
    typedef int* Amount;

    // Hack fix
    int max;
    cout << "Enter the max amount of vitamin types: ";
    cin >> max;

    // The storage of the products.
    Name names = new string[max];
    Price prices = new double[max];
    Amount amounts = new int[max];

    // Get the products and loop when user wants to end.
    for (int i=0; i<max; i++) {
        input(names, prices, amounts, i);
    }

    // Output the products.
    output(names, prices, amounts, max);
    return 0;
}
