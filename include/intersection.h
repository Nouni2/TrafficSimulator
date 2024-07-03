#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include "point.h"
#include "road.h"

enum class IntersectionType {
    CROSSROADS,            // Croisement en X
    X_INTERSECTION,        // Intersection en X avec des routes décalées
    Y_INTERSECTION,        // Intersection en Y
    T_INTERSECTION,        // Intersection en T
    ROUNDABOUT,            // Rond-point
    MISALIGNED,            // Intersection décalée
    RAMP_MERGE,            // Fusion de rampe
    DEFORMED_INTERSECTION, // Intersection déformée
    TRAFFIC_LIGHT,         // Feu de signalisation
    PEDESTRIAN_CROSSING,   // Passage piéton
    STOP_SIGN              // Panneau Stop
};

class Intersection {
public:
    Intersection(const Point& location, IntersectionType type);

    void addRoad(const Road& road);
    const std::vector<Road>& getRoads() const;
    IntersectionType getType() const;

private:
    Point location;
    IntersectionType type;
    std::vector<Road> connectedRoads;
};

#endif // INTERSECTION_H
