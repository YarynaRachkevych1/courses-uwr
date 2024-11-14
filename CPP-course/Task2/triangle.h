#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"
#include "line_segment.h"

class Triangle {
private:
    Point a = Point(0, 0);
    Point b = Point(0, 0);
    Point c = Point(0, 0);
    LineSegment aSide = LineSegment(Point(0, 0), Point(0, 1));
    LineSegment bSide = LineSegment(Point(0, 0), Point(0, 1));
    LineSegment cSide = LineSegment(Point(0, 0), Point(0, 1));

public:
    Triangle(Point a, Point b, Point c);

    Point getA();

    Point getB();

    Point getC();

    double area();

    double perimeter();

    void pMoveVector(Vector v);

    void rotation(Point p, double angle);

    void xAxisSymetry();

    void yAxisSymetry();

    void pSymetry(Point p);
};

#endif