#include <iostream>
#include "Figure.h"
#include "Shape.h"
#include "Bound.h"

Figure::~Figure(){
    for(int i = 0; i < n; i++){
        delete shapes[i];
    }
}

void Figure::addShape(Shape* s){
    Shape** tmp = new Shape*[n+1];

    for(int i = 0; i < n; i++){
        tmp[i] = nullptr;
        tmp[i] = shapes[i];
    }
    tmp[n] = s;

    shapes = nullptr;
    shapes = tmp;

    n++;
}

Bound Figure::getBoundingBox(){
    int xR = 0, xL = 0, yT = 0, yB = 0;

    int iYTS = 0; //Index, Y-Axis, Top, Shape
    int iYTP = 0; //Index, Y-Axis, Top, Points
    int iYBS = 0; //Index, Y-Axis, Bottom, Shape
    int iYBP = 0; //Index, Y-Axis, Bottom, Points
    int iXRS = 0; //Index, Y-Axis, Right, Shape
    int iXRP = 0; //Index, Y-Axis, Right, Points
    int iXLS = 0; //Index, Y-Axis, Left, Shape
    int iXLP = 0; //Index, Y-Axis, Left, Points

    //Find out all indexes for our edge points...

    for(int i = 0; i < n; i++){
        for(int v = 0; v < shapes[i]->getCount(); v++){
            if(shapes[i]->getPoints()[v].getX() > shapes[iXRS]->getPoints()[iXRP].getX()){
                iXRS = i;
                iXRP = v;
            }    
            if(shapes[i]->getPoints()[v].getX() < shapes[iXLS]->getPoints()[iXLP].getX()){
                iXLS = i;
                iXLP = v;
            }
            if(shapes[i]->getPoints()[v].getY() > shapes[iYTS]->getPoints()[iYTP].getY()){
                iYTS = i;
                iYTP = v;
            }
            if(shapes[i]->getPoints()[v].getY() < shapes[iYBS]->getPoints()[iYBP].getY()){
                iYBS = i;
                iYBP = v;
            }
        }
    }

    //Conclude bounds

    xR = shapes[iXRS]->getPoints()[iXRP].getX();
    xL = shapes[iXLS]->getPoints()[iXLP].getX();
    yT = shapes[iYTS]->getPoints()[iYTP].getY();
    yB = shapes[iYBS]->getPoints()[iYBP].getY();
    Bound b = Bound(Point(xL, yT), Point(xR, yB));
    return b;
}