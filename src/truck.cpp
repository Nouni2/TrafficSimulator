#include "../include/truck.h"

Truck::Truck(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
    : Vehicle(id, maxSpeed, width, length, reactionTime) {}

std::string Truck::getType() const {
    return "Truck";
}
