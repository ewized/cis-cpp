#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	// Declaring the random number.
	srand(time(0));

	// Declaring the var's.
	const int scale = 5;
	const int shift = 1;

	int randomNumber = random() % scale + shift;
	cout << randomNumber << endl;

	return 0;
}
