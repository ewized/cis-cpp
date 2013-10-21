#include <iostream>

using namespace std;

string function(string str);

int main() {
    string output = function("Math sucks.");
    cout << output << endl;
    return 0;
}

string function(string str) {
    return str;
}
