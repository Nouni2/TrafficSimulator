#include "traffic_manager.h"

void TrafficManager::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

void TrafficManager::update(double deltaTime) {
    for (Vehicle* vehicle : vehicles) {
        vehicle->updatePosition(deltaTime);
    }
}
