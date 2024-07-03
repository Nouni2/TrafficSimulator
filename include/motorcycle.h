#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& id, double maxSpeed, double width, double length, double reactionTime);
    std::string getType() const override;
};

#endif // MOTORCYCLE_H
