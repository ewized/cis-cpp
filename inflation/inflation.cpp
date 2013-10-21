/*
 File: inflation.cpp
 Description: Write a program to gauge the expected cost of an item in a specified number of years.
 Created: 9/6/2013
 Author: Joshua Rodriguez
 mail: ewized@gmail.com
*/
#include <iostream>

using namespace std;

int main()
{
    // Make the var's exits in ram.
    string itemName, repeatAns;
    double itemInflation, itemInflationYears, itemCost, itemInflationCost;

    // loop the code untill the user dont want to.
    do
    {
        // Ask and set the varibles.
        cout << "What is the name of the item: \n";
        cin >> itemName;
        cout << "How much does " << itemName << " cost: \n$";
        cin >> itemCost;
        cout << "What is the inflation percent rate: \n";
        cin >> itemInflation;
        cout << "How many years are you caculating inflation: \n";
        cin >> itemInflationYears;
        cout << "======================================\n";

        // Convert the inflation percent in to a fraction.
        itemInflation = itemInflation/100;
        // Do the math of the inflation.
        for (int years = 0; years < itemInflationYears ; years++)
        {
            // The stupid pain math fourmal to get the CORRECT answer.
            itemInflationCost = (itemCost * (1 + itemInflation)) * itemInflationYears;
        }

        // Output the results of the inflation.
        cout << "At todays market " << itemName << " is priced at $" << itemCost << ".\n";
        cout << "In " << itemInflationYears << " years " << itemName
            << " will be priced at $" << itemInflationCost << ".\n";
        cout << "======================================\n";

        // Loop the question to make sure the user enters yes or no.
        // Also check if the answer is not blank so it wont loop in
        // a code that will destory the computer. Umm happen to me :)
        do
        {
            // Ask the user to loop the program.
            cout << "Would you like to repeate the program, enter 'yes' or 'no': ";
            cin >> repeatAns;
        } while (repeatAns != "yes" && repeatAns != "no" && repeatAns != "");

    } while (repeatAns == "yes");

    // End with a blank line.
    cout << endl;

    return 0;
}
