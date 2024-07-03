#include <iostream>
#include "../include/point.h"
#include "../include/road.h"

int main() {
    Point start(0, 0, 0); // Point en 3D
    Point end(100, 0, 10); // Point en 3D avec une hauteur différente

    Road road("Road1", start, end, 100, 25, 2);

    std::cout << "Road ID: " << road.getId() << std::endl;
    std::cout << "Start Point: (" << road.getStart().getX() << ", " << road.getStart().getY() << ", " << road.getStart().getZ() << ")" << std::endl;
    std::cout << "End Point: (" << road.getEnd().getX() << ", " << road.getEnd().getY() << ", " << road.getEnd().getZ() << ")" << std::endl;
    std::cout << "Length: " << road.getLength() << " meters" << std::endl;
    std::cout << "Max Speed: " << road.getMaxSpeed() << " m/s" << std::endl;
    std::cout << "Lanes: " << road.getLanes() << std::endl;

    return 0;
}
