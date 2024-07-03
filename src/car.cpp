#include "../include/car.h"

Car::Car(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
    : Vehicle(id, maxSpeed, width, length, reactionTime) {}

std::string Car::getType() const {
    return "Car";
}
