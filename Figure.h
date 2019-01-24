#include <string>
#include <iostream>
#include "Shape.h"
#include "Bound.h"
#ifndef FIGURE_H
#define FIGURE_H


class Figure{
    public:
        Figure(){}
        ~Figure();
        void addShape(Shape* s);
        Bound getBoundingBox();
    private:
        int n;
        Shape** shapes;
};

#endif