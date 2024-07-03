#ifndef BICYCLE_H
#define BICYCLE_H

#include "vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& id, double maxSpeed, double width, double length, double reactionTime);
    std::string getType() const override;
};

#endif // BICYCLE_H
