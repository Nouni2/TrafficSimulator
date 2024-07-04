#include <iostream>
#include "point.h"
#include "road.h"
#include "vehicle.h"
#include "traffic_manager.h"

class Car : public Vehicle {
public:
    Car(const std::string& id, double maxSpeed, double width, double length, double reactionTime)
        : Vehicle(id, maxSpeed, width, length, reactionTime) {}

    std::string getType() const override {
        return "Car";
    }
};

int main() {
    // Create roads
    Road road1("R1", Point(0, 0, 0), Point(100, 0, 0), 100, 25, 2);

    // Create vehicles
    Car car1("Car1", 20, 2, 4, 1.5);
    car1.setPosition(Point(0, 0, 0));
    car1.setSpeed(20);
    car1.setRoad(&road1);

    // Create traffic manager
    TrafficManager trafficManager;
    trafficManager.addVehicle(&car1);

    // Update traffic manager
    double deltaTime = 1.0; // 1 second time step
    for (int i = 0; i < 10; ++i) {
        trafficManager.update(deltaTime);
        Point pos = car1.getPosition();
        std::cout << "Car1 position at time " << (i + 1) * deltaTime << "s: ("
                  << pos.getX() << ", " << pos.getY() << ", " << pos.getZ() << ")" << std::endl;
    }

    return 0;
}
