#ifndef DOCTOR_H
#define DOCTOR_H

#include "salariedemployee.h"
#include <string>

using namespace std;

class Doctor : public SalariedEmployee {
    private:
        string special;
        double fee;
    public:
        Doctor();
        Doctor(Doctor&);
        friend ostream& operator<<(ostream&, Doctor&);
        string get_special();
        void set_special(string);
        double get_fee();
        void set_fee(double);
};

#endif
