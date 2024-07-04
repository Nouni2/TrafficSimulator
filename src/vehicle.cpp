#include "vehicle.h"

Vehicle::Vehicle(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
    : id(id), maxSpeed(maxSpeed), width(width), length(length), reactionTime(reactionTime), speed(0.0), currentRoad(nullptr) {}

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

void Vehicle::setRoad(Road* road) {
    currentRoad = road;
}

Road* Vehicle::getRoad() const {
    return currentRoad;
}

void Vehicle::updatePosition(double deltaTime) {
    if (currentRoad) {
        double distanceTraveled = speed * deltaTime;
        // Update the position along the road based on the distance traveled
        // This is a simplified version; a real implementation would handle the curves and segments of the road.
        position = currentRoad->getPositionAlongRoad(position, distanceTraveled);
    }
}
