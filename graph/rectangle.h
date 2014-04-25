#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
    public:
        void erase();
        void draw();
        void center();
};

#endif
