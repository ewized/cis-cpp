/*
    Filename: rational.cpp
    Problem: Inclass
    Description: Ration numbers
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/25/2014
*/
#include<iostream>

using namespace std;

class Rational {
    private:
        int num,dem;
    public:
        Rational();
        Rational(int,int);
        Rational(int);
        friend ostream& operator<<(ostream& , const Rational&);
        friend istream& operator>>(istream& , Rational&);
        friend Rational operator+(const Rational& , const Rational&);
        // added start
        friend bool operator==(const Rational&, const Rational&);
        friend bool operator>(const Rational& , const Rational&);
        friend bool operator<(const Rational& , const Rational&);
        friend bool operator<=(const Rational& , const Rational&);
        friend bool operator>=(const Rational& , const Rational&);
        friend Rational operator-(const Rational& , const Rational&);
        friend Rational operator*(const Rational& , const Rational&);
        friend Rational operator/(const Rational& , const Rational&);
        // added end
};

Rational::Rational() {
    num = 0;
    dem = 1;
}

Rational::Rational(int _num, int _dem) {
    num = _num;
    dem = _dem;
}

Rational::Rational(int whole) {
    num = whole;
    dem = 1;
}

Rational operator+(const Rational& a, const Rational& b) {
    Rational temp;
    temp.num = (a.num * b.dem) + (b.num * a.dem);
    temp.dem = a.dem * b.dem;
    return temp;
}

ostream& operator<<(ostream& out, const Rational& r) {
    if (r.dem == 0)
        out << "undefined" ;
    else
        out << r.num << "/" << r.dem;
    return out;
}

istream& operator>>(istream& in, Rational& r) {
    in >> r.num >> r.dem;   
    return in;
}

// added start
bool operator==(const Rational& a, const Rational& b) {
    return (a.dem * b.num) == (a.num * b.dem);
}

bool operator>(const Rational& a, const Rational& b) {
    return (a.dem * b.num) > (a.num * b.dem);
}

bool operator<(const Rational& a, const Rational& b) {
    return (a.dem * b.num) < (a.num * b.dem);
}

bool operator<=(const Rational& a, const Rational& b) {
    return (a.dem * b.num) <= (a.num * b.dem);
}

bool operator>=(const Rational& a, const Rational& b) {
    return (a.dem * b.num) >= (a.num * b.dem);
}

Rational operator-(const Rational& a, const Rational& b) {
    Rational temp;

    temp.num = (a.num * b.dem) - (b.num * a.dem);
    temp.dem = a.dem * b.dem;

    return temp;
}

Rational operator*(const Rational& a, const Rational& b) {
    Rational temp;

    temp.num = a.num * b.num;
    temp.dem = a.dem * b.dem;

    return temp;
}

Rational operator/(const Rational& a, const Rational& b) {
    Rational temp;

    temp.num = a.num / b.dem;
    temp.dem = a.dem / b.num;

    return temp;
}

//added end


int main()
{
    Rational b(1,2);
    Rational c(2,4);

    cout << "b=" << b << endl;
    cout << "c=" << c << endl;

    cout << "b=c " << (b==c ? "true" : "false") << endl;
    cout << "b<=c " << (b<=c ? "true" : "false") << endl;
    cout << "b>=c " << (b>=c ? "true" : "false") << endl;
    cout << "b<c " << (b<c ? "true" : "false") << endl;
    cout << "b>c " << (b>c ? "true" : "false") << endl;

    cout << "b*c " << b*c << endl;
    cout << "b/c " << b/c << endl;
    cout << "b+c " << b+c << endl;
    cout << "b-c " << b-c << endl;

    return 0;
}
