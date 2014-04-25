/*
	File: massgravity.cpp
	Description: Write a function that takes arguments for the masses of two
	bodies and the distance between them and that returns the grvitational
	force. Since you will use the preceding formula, the gravition force
	will be in dynes.
	Name: Joshua Rodriguez
	Date: 09/19/2013
	Email: ewized@gmail.com
*/
#include <iostream>
#include <cmath>

// Declare the floowing because they are needed.
bool repeatProgram();
float askMassFirst();
float askMassSecond();
float askMassDistance();
float getForce(float, float, float);
void outputData(float, float, float, float);
const float GRAVITY = 6.67300E-11;

int main()
{
	using namespace std;
	float massFirst, massSecond, massDistance, massForce;

	// Loop if needed
	do
	{
		massFirst = askMassFirst();
		massSecond = askMassSecond();
		massDistance = askMassDistance();
		massForce = getForce(massFirst, massSecond, massDistance);
		outputData(massFirst, massSecond, massDistance, massForce);
	} while (repeatProgram());
}

// Return the mass of the first object.
float askMassFirst()
{
	using namespace std;
	float massFirst;
	cout << "Enter the mass in pounds of the first object: ";
	cin >> massFirst;
	return massFirst;
}

// Return the mass of the second object.
float askMassSecond()
{
	using namespace std;
    float massSecond;
    cout << "Enter the mass in pounds of the second object: ";
    cin >> massSecond;
    return massSecond;
}

// Return the distance between the mass object.
float askMassDistance()
{
	using namespace std;
	float massDistance;
	cout << "Enter the distance between the two objects: ";
	cin >> massDistance;
	return massDistance;
}

// Return the results of the caculation.
float getForce(float massFirst, float massSecond, float massDistance)
{
	using namespace std;
	float force;
	float stepOne = massFirst * massSecond;
	float stepTwo = pow(massDistance, 2);
	force = (GRAVITY * stepOne)/stepTwo;
	return force;
}

// Print out the results of the global objects.
void outputData(float massFirst, float massSecond, float massDistance, float massForce)
{
	using namespace std;
	cout << "The first object is: " << massFirst << " pounds" << endl
		 << "The second object is: " << massSecond << " pounds" << endl
		 << "The distance between them are: " << massDistance << endl
		 << "The force is: " << massForce << endl;
}

// Asks the user to repeat the program.
// Return true if y and false if any other.
bool repeatProgram()
{
	using namespace std;
    char answer;
    cout << "Type 'y' to repeate, anything else will end: ";
    cin >> answer;

    if (answer == 'Y' || answer == 'y')
	{
		return true;
	}
	return false;
}
