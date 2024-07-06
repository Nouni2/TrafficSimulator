#include "car.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Car::Car() : Vehicle() {}

Car::Car(const Point& position, double speed, double acceleration, double direction, double length)
    : Vehicle(position, speed, acceleration, direction, length) {}

void Car::updatePosition(double deltaTime) {
    // Mise à jour de la vitesse en fonction de l'accélération
    speed += acceleration * deltaTime;

    // Mise à jour de la position en fonction de la vitesse et de la direction
    double radians = direction * M_PI / 180.0;
    double deltaX = speed * deltaTime * std::cos(radians);
    double deltaY = speed * deltaTime * std::sin(radians);
    position.setX(position.getX() + deltaX);
    position.setY(position.getY() + deltaY);
}

void Car::display() const {
    std::cout << "Car at (" << position.getX() << ", " << position.getY() << ", " << position.getZ() << ")"
              << " with speed " << speed << " m/s, acceleration " << acceleration << " m/s², direction " << direction 
              << " degrees, length " << length << " meters" << std::endl;
}
