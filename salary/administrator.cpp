#include <iostream>
#include <string>
#include "administrator.h"

using namespace std;

void Administrator::print_check() {
    set_net_pay(get_salary());

    cout << endl
        << "============================================" << endl
        << "Pay to the order of: " << get_name() << endl
        << "Pay amount: " << get_net_pay() << endl
        << "--------------------------------------------" << endl
        << "SSN: " << get_ssn() << endl
        << "TITLE: " << get_title() << endl
        << "AREA: " << get_area() << endl
        << "SUPERVISOR: " << get_supervisor() << endl
        << "============================================" << endl;
}

void Administrator::print() const {
    cout << "{" << endl
        << "    \"title\" : \"" << get_title() << "\"," << endl
        << "    \"area\" : \"" << get_area() << "\"," << endl
        << "    \"supervisor\" : \"" << get_supervisor() << "\"" << endl
        << "}" << endl;
}

string Administrator::get_title() const {
    return title;
}

string Administrator::get_area() const {
    return area;
}

string Administrator::get_supervisor() const {
    return supervisor;
}

void Administrator::set_title(string _title) {
    title = _title;
}

void Administrator::set_area(string _area) {
    area = _area;
}

void Administrator::set_supervisor(string _supervisor) {
    supervisor = _supervisor;
}
