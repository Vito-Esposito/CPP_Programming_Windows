#ifndef PUNTO_3D_HPP
#define PUNTO_3D_HPP

#include "punto.hpp"

class Punto3D: public Punto{
    public:
    double z;

    Punto3D();
    Punto3D(double, double, double);
    
    double getZ() const;
    Punto3D &setZ(double);
    double distanza_origine() const;
    void show() const;

    Punto3D& setX(double);
    Punto3D& setY(double);
};

#endif