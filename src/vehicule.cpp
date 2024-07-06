#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle() : position(0, 0, 0), speed(0), acceleration(0), direction(0), length(4.5) {}

Vehicle::Vehicle(const Point& position, double speed, double acceleration, double direction, double length)
    : position(position), speed(speed), acceleration(acceleration), direction(direction), length(length) {}

Point Vehicle::getPosition() const {
    return position;
}

void Vehicle::setPosition(const Point& position) {
    this->position = position;
}

double Vehicle::getSpeed() const {
    return speed;
}

void Vehicle::setSpeed(double speed) {
    this->speed = speed;
}

double Vehicle::getAcceleration() const {
    return acceleration;
}

void Vehicle::setAcceleration(double acceleration) {
    this->acceleration = acceleration;
}

double Vehicle::getDirection() const {
    return direction;
}

void Vehicle::setDirection(double direction) {
    this->direction = direction;
}

double Vehicle::getLength() const {
    return length;
}

void Vehicle::setLength(double length) {
    this->length = length;
}

void Vehicle::display() const {
    std::cout << "Vehicle at (" << position.getX() << ", " << position.getY() << ", " << position.getZ() << ")"
              << " with speed " << speed << " m/s, acceleration " << acceleration << " m/s², direction " << direction 
              << " degrees, length " << length << " meters" << std::endl;
}
