#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    Vehicle(const std::string& id, double maxSpeed, double width, double length, double reactionTime);
    virtual ~Vehicle() = default;

    std::string getId() const;
    double getMaxSpeed() const;
    double getWidth() const;
    double getLength() const;
    double getReactionTime() const;

    virtual std::string getType() const = 0; // Méthode virtuelle pure

private:
    std::string id;
    double maxSpeed;
    double width;
    double length;
    double reactionTime;
};

#endif // VEHICLE_H
