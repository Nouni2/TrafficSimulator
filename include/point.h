#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

private:
    double x;
    double y;
};

#endif // POINT_H
