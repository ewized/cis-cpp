/*
    Filename: money.cpp
    Problem: pg 675 number 1
    Description: Modify the definition of class Money
    Author: Joshua Rodriguez
    Email: ewized@gmail.com
    Date: 02/25/2014
*/
//DISPLAY 11.8 Overloading << and >>  
//Program to demonstrate the class Money. 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Class for amounts of money in U.S. currency. 
class Money
{
public:
    friend Money add(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns the sum of the values of amount1 and amount2.

    friend bool equal(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns true if the amount1 and amount2 have the same value; 
    //otherwise, returns false.

    friend Money operator +(const Money& amount1, const Money& amount2);//

    friend Money operator -(const Money& amount1, const Money& amount2); //

    friend Money operator -(const Money& amount); //

    friend bool operator ==(const Money& amount1, const Money& amount2);//

    // added start

    Money percent(int );

    friend bool operator <(Money& , Money& );
    friend bool operator <=(Money& , Money& );
    friend bool operator >(Money& , Money& );
    friend bool operator >=(Money& , Money& );

    // added end

    Money(long dollars, int cents);

    Money(long dollars);

    Money( );

    double get_value( );

    friend istream& operator >>(istream& ins, Money& amount);//
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file. 

    friend ostream& operator <<(ostream& outs, const Money& amount);//
    //Overloads the << operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, 
    //then outs has already been connected to a file.

    void input(istream& ins);
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file. An amount of money, including a dollar sign, has been
    //entered in the input stream ins. Notation for negative amounts is -$100.00.
    //Postcondition: The value of the calling object has been set to
    //the amount of money read from the input stream ins.
    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then outs has already been 
    //connected to a file.
    //Postcondition: A dollar sign and the amount of money recorded
    //in the calling object have been sent to the output stream outs.

private:
    long all_cents;
};

// added start


bool operator <(Money& amount1, Money& amount2) {
    return amount1.get_value() < amount2.get_value();
}

bool operator <=(Money& amount1, Money& amount2) {
    return amount1.get_value() <= amount2.get_value();
}

bool operator >(Money& amount1, Money& amount2) {
    return amount1.get_value() > amount2.get_value();
}

bool operator >=(Money& amount1, Money& amount2) {
    return amount1.get_value() >= amount2.get_value();
}

Money Money::percent(int percentage)
{
    /*
    When declaring a new object, use the existing cents value 
    and get the percentage by multiplying the percentage value
    parameter by the existing cents value.  This will give you 
    the percentage, use that as the value when constructing the
    temporary Money object, then return the new temporary Money object
    
    temp_percent = (percentage/100)

    temp_current = get_value() / temp_percent

    temp_current = temp_current * .100

    */

    double d = static_cast<double>(percentage);
    double percent_of_money_object = all_cents * (d / 100);
    Money temp(0, percent_of_money_object);

    return temp;
}

// added stop

int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

int main( )
{
    Money your_amount, my_amount(10, 9), our_amount;
    cout << "Enter an amount of money: ";
    your_amount.input(cin);
    cout << "Your amount is ";
    your_amount.output(cout);
    cout << endl;
    cout << "My amount is ";
    my_amount.output(cout);
    cout << endl;


    // added start
    cout << "%10 of your account" << endl;
    cout << your_amount.percent(10) << endl;

    cout << ((your_amount <= my_amount) ?
            "is less or equal" : "not less or equal") << endl;
    cout << ((your_amount < my_amount) ?
            "is less" : "not less") << endl;
    cout << ((your_amount > my_amount) ?
            "is more" : "not less") << endl;
    cout << ((your_amount >= my_amount) ?
            "is more or equal" : "not more or equal") << endl;
 

    // added stop


    our_amount = add(your_amount, my_amount);
    your_amount.output(cout);
    cout << " + ";
    my_amount.output(cout);
    cout << " equals ";
    our_amount.output(cout);
    cout << endl;
    return 0;
}

Money add(Money amount1, Money amount2)
{
    Money temp;

    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool equal(Money amount1, Money amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

double Money::get_value( )
{
    return (all_cents * 0.01);
}

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;


    return ins;
}       

int digit_to_int(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive


{
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}



//Uses iostream, cctype, cstdlib:
void Money::input(istream& ins)
{
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.
 
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )


    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    all_cents = dollars*100 + cents;
    if (negative)
        all_cents = -all_cents;
}

//Uses cstdlib and iostream:
void Money::output(ostream& outs)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}

//The definitions of the member functions and other overloaded operators go here.
//See Display 11.3, 11.4, 11.5, and 11.6 for the definitions.

