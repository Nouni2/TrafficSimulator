#ifndef POINT_H
#define POINT_H

/**
 * @class Point
 * @brief Classe représentant un point dans un espace 3D.
 */
class Point {
private:
    double x, y, z; // Coordonnées du point dans l'espace 3D

public:
    // Constructeurs
    /**
     * @brief Constructeur par défaut qui initialise les coordonnées à 0.
     */
    Point();

    /**
     * @brief Constructeur avec paramètres pour initialiser les coordonnées.
     * @param x Coordonnée x du point.
     * @param y Coordonnée y du point.
     * @param z Coordonnée z du point.
     */
    Point(double x, double y, double z);

    // Accesseurs et mutateurs
    /**
     * @brief Obtient la coordonnée x du point.
     * @return La coordonnée x.
     */
    double getX() const;

    /**
     * @brief Obtient la coordonnée y du point.
     * @return La coordonnée y.
     */
    double getY() const;

    /**
     * @brief Obtient la coordonnée z du point.
     * @return La coordonnée z.
     */
    double getZ() const;

    /**
     * @brief Définit la coordonnée x du point.
     * @param x Nouvelle coordonnée x.
     */
    void setX(double x);

    /**
     * @brief Définit la coordonnée y du point.
     * @param y Nouvelle coordonnée y.
     */
    void setY(double y);

    /**
     * @brief Définit la coordonnée z du point.
     * @param z Nouvelle coordonnée z.
     */
    void setZ(double z);

    // Méthode pour afficher le point
    /**
     * @brief Affiche les coordonnées du point.
     */
    void display() const;
};

#endif // POINT_H
