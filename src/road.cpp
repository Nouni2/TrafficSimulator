#include "../include/road.h"

Road::Road(const std::string& id, const Point& start, const Point& end, double length, double maxSpeed, int lanes)
    : id(id), start(start), end(end), length(length), maxSpeed(maxSpeed), lanes(lanes) {}

Road::~Road() {}

std::string Road::getId() const {
    return id;
}

Point Road::getStart() const {
    return start;
}

Point Road::getEnd() const {
    return end;
}

double Road::getLength() const {
    return length;
}

double Road::getMaxSpeed() const {
    return maxSpeed;
}

int Road::getLanes() const {
    return lanes;
}
