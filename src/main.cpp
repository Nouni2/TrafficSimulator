#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <filesystem>
#include "point.h"
#include "road.h"

using namespace std;
namespace fs = std::filesystem;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    // Définir le centre du rond-point
    Point center(0.0, 0.0, 0.0);

    // Définir le rayon du rond-point
    double radius = 5;

    // Définir le nombre de voies
    int lanes = 2;

    // Définir la vitesse limite
    double speedLimit = 50.0;

    // Créer le rond-point
    vector<Road> roundabout = Roundabout(center, radius, lanes, speedLimit);

    // Obtenir le chemin du répertoire de travail actuel
    fs::path currentPath = fs::current_path();
    fs::path projectRootPath = currentPath.parent_path().parent_path();
    fs::path dataPath = projectRootPath / "data" / "points.txt";

    // Écrire les points dans un fichier
    ofstream outFile(dataPath);
    if (outFile.is_open()) {
        for (const auto& road : roundabout) {
            outFile << road.getStartPoint().getX() << " " << road.getStartPoint().getY() << endl;
        }
        outFile.close();
    } else {
        cerr << "Unable to open file at " << dataPath << endl;
        return 1;
    }

    // Paramètres pour le calcul du flow rate optimal
    double v_f = 50.0 / 3.6;  // Convertir la vitesse de libre circulation en m/s
    double L = 4.5;  // Longueur moyenne des véhicules en mètres
    double t_reac = 1.5;  // Temps de réaction en secondes
    double a = 4.0;  // Décélération maximale en m/s²
    double p = 2.0;  // Paramètre p

    // Calculer le flow rate optimal et la densité maximale
    auto [q_max, v_opt] = Road::optimalFlowRate(v_f, L, t_reac, a, p);

    // Afficher les résultats
    cout << "Flow rate optimal par voie: " << q_max * 3600 << " veh/h" << endl;
    cout << "Vitesse optimale: " << v_opt * 3.6 << " km/h" << endl;

    return 0;
}
