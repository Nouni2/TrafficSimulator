#include "../include/motorcycle.h"

Motorcycle::Motorcycle(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
    : Vehicle(id, maxSpeed, width, length, reactionTime) {}

std::string Motorcycle::getType() const {
    return "Motorcycle";
}
