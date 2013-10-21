#include<iostream>
#include<string>

using namespace std;

void swap(int&,int&);
void swaptwo(int,int);
void prompt(string, int&);

int main()
{

	int x = 5;
    int a, b;

    // Prompt the thingys
    prompt("Enther the value for a:", a);
    prompt("Enther the value for b:", b);

    // Pass by refrence.
    cout << "Before swap a=" << a << " b=" << b << endl;
    swap(a,b);
    cout << "Aftere swap a=" << a << " b=" << b << endl;

    // Pass by varible.
    cout << "Before swap a=" << a << " b=" << b << endl;
    swaptwo(a,b);
    cout << "Aftere swap a=" << a << " b=" << b << endl;

    return 0;
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swaptwo(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void prompt(string message, int& a)
{
    cout << message;
    cin >> a;
}
