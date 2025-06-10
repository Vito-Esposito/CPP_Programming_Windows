#include "punto3D.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Punto3D::Punto3D(){
    Punto();  //richiamo il costruttore della classe base così ho x e y = 0
    z= 0;
}

Punto3D::Punto3D(double c1, double c2, double c3){
    Punto(c1, c2);
    z= c3;
}

double Punto3D::getZ() const{
    return z;
}

Punto3D& Punto3D::setZ(double nz){
    z= nz;
    return *this;
}

double Punto3D::distanza_origine() const{
    return sqrt(pow(getX(),2)+pow(getY(),2)+pow(z,2));
}

void Punto3D::show() const{
    cout << "("<<getX()<<","<<getY()<<","<< z <<")";
}

// override per restituire Punto3D
Punto3D& Punto3D::setX(double x) {
    Punto::setX(x);
    return *this;
}

Punto3D& Punto3D::setY(double y) {
    Punto::setY(y);
    return *this;
}
