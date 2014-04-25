#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "salariedemployee.h"

using namespace std;

class Administrator : public SalariedEmployee {
    private:
        // Title
        string title;
        // Area
        string area;
        // Supervisor
        string supervisor;
    public:
        // Print the check out to the screen.
        void print_check();
        // Print the data of this class to the screen.
        void print() const;
        // return the title of this administrator.
        string get_title() const;
        // return the area that this administrator belongs to.
        string get_area() const;
        // return the supervisor that this administrator reports to.
        string get_supervisor() const;
        // Set the title of this administrator
        void set_title(string);
        // Set the area of this administrator.
        void set_area(string);
        // Set the supervisor of this administrator.
        void set_supervisor(string);
};

#endif // ADMINISTRATOR_H
