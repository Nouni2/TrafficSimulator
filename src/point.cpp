#include "Point.h"

// Définition du constructeur
Point::Point(double x, double y) : x(x), y(y) {}

// Définition des méthodes publiques
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}
