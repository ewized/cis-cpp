/*
    Filename: vectors.cpp
    Problem: page 676 number 3
    Description: Create a class for that acts like the vector in cstdlib.
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/27/2014
*/
#include <iostream>
#include <cstdlib>

using namespace std;

class VectorDouble {
    private:
        int cap;
        double* doubles;
        void init();
    public:
        VectorDouble();
        VectorDouble(int);
        VectorDouble(VectorDouble&);
        ~VectorDouble() { delete[] doubles; }
        void push_back(double);
        int capacity();
        int size();
        void reserve(int);
        void resize(int);
        double value_at(int);
        void change_value_at(int, double);
};

void print(VectorDouble&);

VectorDouble::VectorDouble(int _size) {
    cap = _size;
    doubles = new double[_size];
    init();
}

VectorDouble::VectorDouble() {
    const int DEFAULT = 50;
    cap = DEFAULT;
    doubles = new double[cap];
    init();
}

VectorDouble::VectorDouble(VectorDouble& copy) {
    cap = copy.capacity();
    doubles = new double[cap];
    init();

    for (int i = 0; i < copy.size(); i++) {
        doubles[i] = copy.value_at(i);
    }
}

// Set them to zero
void VectorDouble::init() {
    for (int i = 0; i < cap; i++) {
        doubles[i] = 0;
    }
}

// Push back: Added the element to the end.
void VectorDouble::push_back(double amount) {
    if (size() + 1 > capacity()) {
        cout << "Capacity matched cant add to array." << endl;
        exit(1);
    }

    // Add the data.
    double last = value_at(0);
    for (int i = 1;i<capacity();i++) {
        double temp = doubles[i];
        doubles[i] = last;
        last = temp;
    }
    doubles[0] = amount;
}

// Capacity: The number of elements that can be held in
//      currently allocated storage.
int VectorDouble::capacity() {
    return cap;
}

// Size: The number of elements.
int VectorDouble::size() {
    int temp = 0;

    for (int i = 0; i < cap; i++) {
        if (doubles[i] > 0 || doubles[i] < 0) temp++;
    }

    return temp;
}

// Reserve: Reserve storage.
void VectorDouble::reserve(int _size) {
    if (capacity() < _size) {
        cout << "Size not bigger then original" << endl;
        exit(1);
    }

    int tempSize = size();
    double* temp = new double[tempSize];

    for (int i=0;i<cap;i++) {
        temp[i] = doubles[i];
    }

    delete [] doubles;
    cap = _size;
    doubles = new double[cap];
    init();

    for (int i=0;i<tempSize;i++) {
        doubles[i] = temp[i];
    }
}

// Resize: Changes the number of elements stored.
void VectorDouble::resize(int _size) {
    if (capacity() > _size) {
        cout << "Size not smaller then original" << endl;
        exit(1);
    }

    int tempSize = size();
    double* temp = new double[tempSize];

    for (int i=0;i<cap;i++) {
        temp[i] = doubles[i];
    }

    delete [] doubles;
    cap = _size;
    doubles = new double[cap];
    init();

    for (int i=0;i<tempSize;i++) {
        doubles[i] = temp[i];
    }
}

// Gets the Value at the index
double VectorDouble::value_at(int pos) {
    if (pos > capacity()) {
        cout << "VALUE TOO BIG" << endl;
        exit(1);
    }

    return doubles[pos];
}

// Change the value at the index
void VectorDouble::change_value_at(int pos, double data) {
    if (pos > capacity()) cout << "VALUE TOO BIG" << endl;
    doubles[pos] = data;
}

// Testing program
int main() {
    VectorDouble a;
    VectorDouble c(5);

    cout << "=====[Adding]=====" << endl;
    cout << "A: 5.5 to 0" << endl;
    a.change_value_at(0,5.5);
    a.push_back(7.5);
    a.push_back(6.5);
    cout << "A: 4.5 to 1" << endl;
    a.change_value_at(1,4.5);
    cout << "C: 5.6 to 3" << endl;
    c.push_back(4.1);
    c.push_back(4.2);
    c.push_back(4.3);
    c.push_back(4.4);

    VectorDouble b(a);

    cout << "=====[SIZE]=====" << endl;
    cout << "a: " << a.size() << endl;
    cout << "b: " << b.size() << endl;
    cout << "c: " << c.size() << endl;

    cout << "=====[CAPACITY]=====" << endl;
    cout << "a: " << a.capacity() << endl;
    cout << "b: " << b.capacity() << endl;
    cout << "c: " << c.capacity() << endl;


    cout << "=====[A]=====" << endl;
    print(a);
    cout << "=====[B]=====" << endl;
    print(b);
    cout << "=====[C]=====" << endl;
    print(c);

    return 0;
}

// Simple printer
void print(VectorDouble& a) {
    if (a.size() == 0) cout << "empty" << endl;

    for (int i = 0;i<a.capacity();i++) {
        if (a.value_at(i) > 0 || a.value_at(i) < 0) {
            cout << i << ": ";
            cout << a.value_at(i);
            cout << endl;
        }
    }
}
