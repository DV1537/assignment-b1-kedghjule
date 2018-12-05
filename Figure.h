#include <string>
#include <iostream>
#include "Shape.h"
#ifndef FIGURE_H
#define FIGURE_H


class Figure{
    public:
        Figure(){}
        void addShape(Shape const &s);
        
    private:
        int n;
        Shape* shapes;
        Shape* addToArray(Shape* array, int bufferSize, Shape const &value); //Dynamic array manager
};

#endif