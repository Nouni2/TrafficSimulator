#ifndef ROAD_H
#define ROAD_H

#include <string>
#include "point.h"

class Road {
public:
    Road(const std::string& id, const Point& start, const Point& end, double length, double maxSpeed, int lanes);
    ~Road();

    std::string getId() const;
    Point getStart() const;
    Point getEnd() const;
    double getLength() const;
    double getMaxSpeed() const;
    int getLanes() const;

private:
    std::string id;
    Point start;
    Point end;
    double length;
    double maxSpeed;
    int lanes;
};

#endif // ROAD_H
