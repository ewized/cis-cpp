#include <iostream>
#include "doctor.h"

using namespace std;

Doctor::Doctor() {
}

Doctor::Doctor(Doctor& doctor) {
    set_special(doctor.get_special());
    set_fee(doctor.get_fee());
}

ostream& operator<<(ostream& out, Doctor& doctor) {
    out << "Special: " << doctor.get_special() << endl
        << "Fee: " << doctor.get_fee() << endl;
}

string Doctor::get_special() {
    return special;
}

void Doctor::set_special(string _special) {
    special = _special;
}

double Doctor::get_fee() {
    return fee;
}

void Doctor::set_fee(double _fee) {
    fee = _fee;
}
