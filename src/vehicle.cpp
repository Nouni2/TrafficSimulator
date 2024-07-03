#include "../include/vehicle.h"

Vehicle::Vehicle(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
    : id(id), maxSpeed(maxSpeed), width(width), length(length), reactionTime(reactionTime) {}

std::string Vehicle::getId() const {
    return id;
}

double Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

double Vehicle::getWidth() const {
    return width;
}

double Vehicle::getLength() const {
    return length;
}

double Vehicle::getReactionTime() const {
    return reactionTime;
}
