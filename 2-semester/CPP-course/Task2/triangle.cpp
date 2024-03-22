#include "triangle.h"
#include <cmath>
#include <stdexcept>
#include "point.h"
#include "line_segment.h"

//Konstruktor
Triangle::Triangle(Point a, Point b, Point c) {
    if ((a.getX() == b.getX() && a.getY() == b.getY()) ||
        (a.getX() == c.getX() && a.getY() == c.getY()) ||
        (b.getX() == c.getX() && b.getY() == c.getY())) {
        throw std::invalid_argument("Trojkat nie moze miec dwoch takich samych wierzcholkow!");
    }
    this->a = a;
    this->b = b;
    this->c = c;
    this->aSide = LineSegment(a, b);
    this->bSide = LineSegment(b, c);
    this->cSide = LineSegment(a, c);
}

Point Triangle::getA() {
    return a;
}

Point Triangle::getB() {
    return b;
}

Point Triangle::getC() {
    return c;
}

double Triangle::area() {
    return std::abs(
            (this->b.getX() - this->a.getX()) * (this->c.getY() - this->a.getY()) -
            (this->b.getY() - this->a.getY()) * (this->c.getX() - this->a.getX())) / 2;
}

double Triangle::perimeter() {
    return this->aSide.length() + this->bSide.length() + this->cSide.length();
}

void Triangle::pMoveVector(Vector v) {
    this->a.pMoveVector(v);
    this->b.pMoveVector(v);
    this->c.pMoveVector(v);
}

void Triangle::rotation(Point p, double angle) {
    this->a.rotation(p, angle);
    this->b.rotation(p, angle);
    this->c.rotation(p, angle);
}

void Triangle::xAxisSymetry() {
    this->a.xAxisSymetry();
    this->b.xAxisSymetry();
    this->c.xAxisSymetry();
}

void Triangle::yAxisSymetry() {
    this->a.yAxisSymetry();
    this->b.yAxisSymetry();
    this->c.yAxisSymetry();
}

void Triangle::pSymetry(Point p) {
    this->a.pSymetry(p);
    this->b.pSymetry(p);
    this->c.pSymetry(p);
}
