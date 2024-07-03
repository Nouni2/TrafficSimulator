#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

private:
    double x;
    double y;
    double z;
};

#endif // POINT_H
