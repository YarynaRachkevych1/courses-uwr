#ifndef POINT_H
#define POINT_H

#include "vector.h"

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0);

    double getX();

    double getY();

    double distanceTo(Point p2);

    void pMoveVector(Vector v);

    void rotation(Point p, double angle);

    void xAxisSymetry();

    void yAxisSymetry();

    void pSymetry(Point p);
};

#endif
