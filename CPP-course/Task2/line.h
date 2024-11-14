#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {
private:
    double a;
    double b;

public:
    Line(Point x, Point y);

    double getA();

    double getB();

    bool intersects(Line l);

    bool isParallel(Line l);

    bool isPerpendicular(Line l);

    bool containsPoint(Point p);

    Point intersectionPoint(Line l);
};

#endif