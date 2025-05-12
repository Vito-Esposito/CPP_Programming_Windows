#include "punto.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Punto::Punto(){
    x=0;
    y=0;
}

Punto::Punto(double c1, double c2){
    x= c1;
    y= c2;
}

double Punto::getX() const{
    return x;
}

double Punto::getY() const{
    return y;
}
    
Punto& Punto::setX(double nx){
    x= nx;
    return *this;
}

Punto& Punto::setY(double ny){
    y= ny;
    return *this;
}

double Punto::distanza_origine() const{
    return sqrt((x*x)+(y*y));
}

void Punto::show(){
    cout<<"["<<x<<"]"<<";"<<"["<<y<<"]";
}