#include "../include/bicycle.h"

Bicycle::Bicycle(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
    : Vehicle(id, maxSpeed, width, length, reactionTime) {}

std::string Bicycle::getType() const {
    return "Bicycle";
}
