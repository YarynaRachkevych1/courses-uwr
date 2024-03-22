#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "point.h"
#include "line.h"

class LineSegment {
private:
    Point a;
    Point b;
public:
    LineSegment(Point a, Point b);

    Point getA();

    Point getB();

    double length();

    void pMoveVector(Vector v);

    void rotation(Point p, double angle);

    void xAxisSymetry();

    void yAxisSymetry();

    void pSymetry(Point p);

    bool containsPoint(Point p);

    bool isParallel(LineSegment l);

    bool isPerpendicular(LineSegment l);

    bool intersectsLine(Line l);

    bool intersectsLineSegment(LineSegment l);

    Line getLine();
};

#endif