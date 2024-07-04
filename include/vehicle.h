#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "point.h"
#include "road.h"

class Vehicle {
public:
    Vehicle(const std::string& id, double maxSpeed, double width, double length, double reactionTime);
    virtual ~Vehicle() = default;

    std::string getId() const;
    double getMaxSpeed() const;
    double getWidth() const;
    double getLength() const;
    double getReactionTime() const;

    virtual std::string getType() const = 0;

    Point getPosition() const;
    void setPosition(const Point& position);
    void updatePosition(double deltaTime);
    
    double getSpeed() const;
    void setSpeed(double speed);

    void setRoad(Road* road);
    Road* getRoad() const;

private:
    std::string id;
    double maxSpeed;
    double width;
    double length;
    double reactionTime;
    Point position;
    double speed;
    Road* currentRoad;  // Pointer to the current road
};

#endif // VEHICLE_H
