#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const std::string& id, double maxSpeed, double width, double length, double reactionTime);
    std::string getType() const override;
};

#endif // TRUCK_H
