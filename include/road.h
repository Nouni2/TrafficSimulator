#ifndef ROAD_H
#define ROAD_H

#include <string>
#include <vector>
#include "point.h"

/**
 * @class Road
 * @brief Classe représentant une route entre deux points avec des attributs supplémentaires.
 */
class Road {
private:
    Point startPoint; // Point de départ de la route
    Point endPoint; // Point d'arrivée de la route
    double speedLimit; // Vitesse limite sur la route
    std::pair<int, int> lanes; // Nombre de voies (right, left)
    std::vector<std::string> restrictedVehicles; // Types de véhicules restreints sur la route

    /**
     * @brief Méthode pour calculer la longueur de la route.
     * @return La longueur de la route.
     */
    double calculateLength() const;

public:
    // Constructeurs
    /**
     * @brief Constructeur par défaut.
     */
    Road();

    /**
     * @brief Constructeur avec paramètres pour initialiser les attributs de la route.
     * @param start Point de départ de la route.
     * @param end Point d'arrivée de la route.
     * @param speedLimit Vitesse limite sur la route.
     * @param lanes Nombre de voies dans chaque sens.
     */
    Road(const Point& start, const Point& end, double speedLimit, std::pair<int, int> lanes);

    // Accesseurs et mutateurs
    /**
     * @brief Obtient le point de départ de la route.
     * @return Le point de départ.
     */
    Point getStartPoint() const;

    /**
     * @brief Obtient le point d'arrivée de la route.
     * @return Le point d'arrivée.
     */
    Point getEndPoint() const;

    /**
     * @brief Obtient la vitesse limite sur la route.
     * @return La vitesse limite.
     */
    double getSpeedLimit() const;

    /**
     * @brief Obtient le nombre de voies dans chaque sens.
     * @return Le nombre de voies (right, left).
     */
    std::pair<int, int> getLanes() const;

    /**
     * @brief Obtient la liste des véhicules restreints sur la route.
     * @return La liste des véhicules restreints.
     */
    std::vector<std::string> getRestrictedVehicles() const;

    /**
     * @brief Définit le point de départ de la route.
     * @param start Le nouveau point de départ.
     */
    void setStartPoint(const Point& start);

    /**
     * @brief Définit le point d'arrivée de la route.
     * @param end Le nouveau point d'arrivée.
     */
    void setEndPoint(const Point& end);

    /**
     * @brief Définit la vitesse limite sur la route.
     * @param limit La nouvelle vitesse limite.
     */
    void setSpeedLimit(double limit);

    /**
     * @brief Définit le nombre de voies dans chaque sens.
     * @param lanes Le nouveau nombre de voies (right, left).
     */
    void setLanes(std::pair<int, int> lanes);

    /**
     * @brief Ajoute un type de véhicule restreint sur la route.
     * @param vehicle Le type de véhicule à restreindre.
     */
    void addRestrictedVehicle(const std::string& vehicle);

    // Méthode pour afficher les informations de la route
    /**
     * @brief Affiche les informations de la route.
     */
    void display() const;

    // Méthode pour obtenir la longueur de la route
    /**
     * @brief Obtient la longueur de la route.
     * @return La longueur de la route.
     */
    double getLength() const;

   // Méthode pour calculer le flow rate maximum et la vitesse optimale
/**
 * @brief Calcule le flow rate maximum et la vitesse optimale pour maximiser le flow rate.
 * @param v_f Vitesse de libre circulation (m/s).
 * @param L Longueur moyenne des véhicules (m).
 * @param t_reac Temps de réaction (s).
 * @param a Décélération maximale (m/s²).
 * @param p Paramètre déterminant la forme de la relation vitesse-densité.
 * @return Une paire contenant le flow rate maximum et la vitesse optimale.
 */
static std::pair<double, double> optimalFlowRate(double v_f, double L, double t_reac, double a, double p);
 
};

/**
 * @brief Fonction pour créer un rond-point avec des points discrets.
 * @param center Centre du rond-point.
 * @param radius Rayon du rond-point.
 * @param lanes Nombre de voies du rond-point.
 * @param speedLimit Vitesse limite sur le rond-point.
 * @return Un vecteur de routes formant le rond-point.
 */
std::vector<Road> Roundabout(const Point& center, double radius, int lanes, double speedLimit);

#endif // ROAD_H
