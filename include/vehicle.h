#ifndef VEHICLE_H
#define VEHICLE_H

#include "point.h"

class Vehicle {
protected:
    Point position;
    double speed;
    double acceleration;
    double direction; // direction in degrees
    double length; // longueur moyenne du véhicule

public:
    // Constructeurs
    Vehicle();
    Vehicle(const Point& position, double speed, double acceleration, double direction, double length);

    // Accesseurs et mutateurs
    Point getPosition() const;
    void setPosition(const Point& position);

    double getSpeed() const;
    void setSpeed(double speed);

    double getAcceleration() const;
    void setAcceleration(double acceleration);

    double getDirection() const;
    void setDirection(double direction);

    double getLength() const;
    void setLength(double length);

    // Méthodes virtuelles pour être redéfinies dans les classes dérivées
    virtual void updatePosition(double deltaTime) = 0;

    // Méthode pour afficher les informations du véhicule
    virtual void display() const;
};

#endif // VEHICLE_H
