// src/road.cpp
#include <iostream>
#include <cmath>
#include <vector>
#include "road.h"

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const int NUM_POINTS = 50; // Nombre de points pour la discrétisation du rond-point

// Constructeurs
Road::Road() : speedLimit(0), lanes({0, 0}) {}

Road::Road(const Point& start, const Point& end, double speedLimit, std::pair<int, int> lanes)
    : startPoint(start), endPoint(end), speedLimit(speedLimit), lanes(lanes) {}

// Accesseurs
Point Road::getStartPoint() const {
    return startPoint;
}

Point Road::getEndPoint() const {
    return endPoint;
}

double Road::getSpeedLimit() const {
    return speedLimit;
}

std::pair<int, int> Road::getLanes() const {
    return lanes;
}

std::vector<std::string> Road::getRestrictedVehicles() const {
    return restrictedVehicles;
}

// Mutateurs
void Road::setStartPoint(const Point& start) {
    startPoint = start;
}

void Road::setEndPoint(const Point& end) {
    endPoint = end;
}

void Road::setSpeedLimit(double limit) {
    speedLimit = limit;
}

void Road::setLanes(std::pair<int, int> lanes) {
    this->lanes = lanes;
}

void Road::addRestrictedVehicle(const std::string& vehicle) {
    restrictedVehicles.push_back(vehicle);
}

// Méthode pour afficher les informations de la route
void Road::display() const {
    cout << "Road from ";
    startPoint.display();
    cout << " to ";
    endPoint.display();
    cout << "Speed limit: " << speedLimit << " km/h" << endl;
    cout << "Lanes: (" << lanes.first << ", " << lanes.second << ")" << endl;
    cout << "Restricted vehicles: ";
    for (const auto& vehicle : restrictedVehicles) {
        cout << vehicle << " ";
    }
    cout << endl;
    cout << "Length: " << getLength() << " units" << endl;
}

// Méthode pour calculer la longueur de la route
double Road::calculateLength() const {
    double dx = endPoint.getX() - startPoint.getX();
    double dy = endPoint.getY() - startPoint.getY();
    double dz = endPoint.getZ() - startPoint.getZ();
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Méthode pour obtenir la longueur de la route
double Road::getLength() const {
    return calculateLength();
}

// Fonction pour créer un rond-point
std::vector<Road> Roundabout(const Point& center, double radius, int lanes, double speedLimit) {
    vector<Road> roads;
    vector<Point> points;

    // Créer les points sur la circonférence
    for (int i = 0; i <= NUM_POINTS; ++i) {
        double angle = 2 * M_PI * i / NUM_POINTS;
        double x = center.getX() + radius * cos(angle);
        double y = center.getY() + radius * sin(angle);
        points.push_back(Point(x, y, center.getZ()));
    }

    // Ajouter le premier point à la fin pour fermer le rond-point
    points.push_back(points[0]);

    // Créer les routes entre les points
    for (int i = 0; i <= NUM_POINTS; ++i) {
        roads.push_back(Road(points[i], points[i + 1], speedLimit, {lanes, 0}));
    }

    return roads;
}

std::pair<double, double> Road::optimalFlowRate(double v_f, double L, double t_reac, double a, double p) {
    // Déterminer la vitesse optimale
    double v_opt = (p / (1 + p)) * v_f;
    
    // Calculer l'espacement s(v_opt)
    double s_v_opt = v_opt * t_reac + (v_opt * v_opt) / (2 * a);
    
    // Calculer k_j
    double k_j = 1 / (L + s_v_opt);
    
    // Calculer le flow rate maximum
    double q_max = (v_opt * k_j) * pow(1 - (v_opt / v_f), 1 / p);
    
    return std::make_pair(q_max, v_opt);
}
