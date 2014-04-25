/*
 File: labrats.cpp
 Description: Input the amount of artificial sweetener to kill a mounse and weight,
 the weight of the dieter when he will stop.
 Created: 8/31/2013
 Author: Joshua Rodriguez
 mail: ewized@gmail.com
*/
#include <iostream>

using namespace std;

int main()
{
    // Set the var's into memory.
    double artificialSweetener, mouseWeight, dieterWeight, tempWeight, tempArtificialSweetener;
    int totalCans;
    const double sweetenerPerCan = 0.001;

    // Ask and set the vars.
    cout << "How many grams did the artificial sweetener did the mouse intake: ";
    cin >> artificialSweetener;
    cout << "How many pounds was the mouse: ";
    cin >> mouseWeight;
    cout << "How many pounds will you stop your diet: ";
    cin >> dieterWeight;

    // Run the loop untill it gets the right math.
    tempWeight = mouseWeight; // Sets the tempWeight to the mouse weight to get a good reading.
    while (tempWeight < dieterWeight)
    {
        tempWeight++;
        totalCans++;
        tempArtificialSweetener = tempArtificialSweetener + sweetenerPerCan;
    }

    // Output the results.
    cout << "You can intake " << tempArtificialSweetener << " grams and be fine.\n";
    cout << "This would mean you can drink " << (totalCans / sweetenerPerCan) << " soda pop.\n";

    return 0;
}
