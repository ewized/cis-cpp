#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
    public:
        void erase();
        void draw();
        void center();
};

#endif
