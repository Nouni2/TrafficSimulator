#include "../include/intersection.h"

Intersection::Intersection(const Point& location, IntersectionType type)
    : location(location), type(type) {}

void Intersection::addRoad(const Road& road) {
    connectedRoads.push_back(road);
}

const std::vector<Road>& Intersection::getRoads() const {
    return connectedRoads;
}

IntersectionType Intersection::getType() const {
    return type;
}
