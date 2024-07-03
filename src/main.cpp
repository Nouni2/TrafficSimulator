#include <iostream>
#include "../include/point.h"
#include "../include/road.h"
#include "../include/intersection.h"
#include "../include/car.h"
#include "../include/truck.h"
#include "../include/motorcycle.h"
#include "../include/bicycle.h"

int main() {
    // Création de véhicules
    Car car1("Car1", 120, 2.0, 4.0, 1.5);
    Truck truck1("Truck1", 90, 2.5, 12.0, 2.5);
    Motorcycle motorcycle1("Motorcycle1", 100, 0.8, 2.2, 1.0);
    Bicycle bicycle1("Bicycle1", 25, 0.6, 1.8, 0.5);

    // Affichage des informations des véhicules
    std::vector<Vehicle*> vehicles = {&car1, &truck1, &motorcycle1, &bicycle1};

    for (const auto& vehicle : vehicles) {
        std::cout << "Vehicle ID: " << vehicle->getId() << std::endl;
        std::cout << "Type: " << vehicle->getType() << std::endl;
        std::cout << "Max Speed: " << vehicle->getMaxSpeed() << " km/h" << std::endl;
        std::cout << "Width: " << vehicle->getWidth() << " m" << std::endl;
        std::cout << "Length: " << vehicle->getLength() << " m" << std::endl;
        std::cout << "Reaction Time: " << vehicle->getReactionTime() << " s" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
