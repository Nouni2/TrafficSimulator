#ifndef TRAFFIC_MANAGER_H
#define TRAFFIC_MANAGER_H

#include <vector>
#include "vehicle.h"
#include "road.h"

class TrafficManager {
public:
    void addVehicle(Vehicle* vehicle);
    void update(double deltaTime);

private:
    std::vector<Vehicle*> vehicles;
};

#endif // TRAFFIC_MANAGER_H
