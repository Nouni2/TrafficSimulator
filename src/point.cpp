// src/point.cpp
#include <iostream>
#include "point.h"

using namespace std;

// Constructeurs
Point::Point() : x(0), y(0), z(0) {}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

// Accesseurs
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

// Mutateurs
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setZ(double z) {
    this->z = z;
}

// Méthode pour afficher le point
void Point::display() const {
    cout << "Point(" << x << ", " << y << ", " << z << ")" << endl;
}
