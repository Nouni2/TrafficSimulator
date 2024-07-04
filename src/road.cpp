#include "road.h"

Road::Road(const std::string& id, const Point& start, const Point& end, double length, double maxSpeed, int lanes)
    : id(id), start(start), end(end), length(length), maxSpeed(maxSpeed), lanes(lanes) {}

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

Point Road::getPositionAlongRoad(const Point& currentPosition, double distance) const {
    // Calculate the new position along the road based on the distance traveled
    // This is a simplified version; a real implementation would handle the curves and segments of the road.
    double t = distance / length;
    double newX = start.getX() + t * (end.getX() - start.getX());
    double newY = start.getY() + t * (end.getY() - start.getY());
    double newZ = start.getZ() + t * (end.getZ() - start.getZ());
    return Point(newX, newY, newZ);
}
