#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
public:
    // Constructeurs
    Car();
    Car(const Point& position, double speed, double acceleration, double direction, double length);

    // Redéfinir les méthodes virtuelles
    void updatePosition(double deltaTime) override;
    void display() const override;

};

#endif // CAR_H
