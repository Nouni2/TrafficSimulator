#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
public:
    Car(const std::string& id, double maxSpeed, double width, double length, double reactionTime);
    std::string getType() const override;
};

#endif // CAR_H
