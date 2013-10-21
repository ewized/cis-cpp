#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    srand(time(0));

    while (true)
    {
        int number = random() % 10;
        cout << number;
        if (number < 5) {
            cout << " ";
        }
        if (number > 5) {
            cout << "      ";
        }
    }
    return 0;
}

