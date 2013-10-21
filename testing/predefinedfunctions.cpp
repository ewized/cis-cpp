#include<iostream>
#include<cmath>

using namespace std;

int main()
{

	for(int deg = 0;deg < 360;deg++){
        double radian = static_cast<int>(M_PI*deg / 180);
		cout << "degree = " << deg;
		cout << " radian=" << radian;
		cout << " sin(radian) = " << sin(radian) <<endl;
	}

	return 0;
}
