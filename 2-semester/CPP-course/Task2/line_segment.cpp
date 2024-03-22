#include "line_segment.h"
#include <cmath>
#include <stdexcept>
#include "point.h"

//Konstruktor
LineSegment::LineSegment(Point a, Point b) {
    if (a.getX() == b.getX() && a.getY() == b.getY()) {
        throw std::invalid_argument("Odcinek nie moze miec 0 dlugosci!");
    }
    this->a = a;
    this->b = b;
}

Point LineSegment::getA() {
    return a;
}

Point LineSegment::getB() {
    return b;
}

double LineSegment::length() {
    double dx = this->a.getX() - this->b.getX();
    double dy = this->a.getY() - this->b.getY();
    return std::sqrt(dx * dx + dy * dy);
}

void LineSegment::pMoveVector(Vector v) {
    this->a.pMoveVector(v);
    this->b.pMoveVector(v);
}

void LineSegment::rotation(Point p, double angle) {
    this->a.rotation(p, angle);
    this->b.rotation(p, angle);
}

void LineSegment::xAxisSymetry() {
    this->a.xAxisSymetry();
    this->b.xAxisSymetry();
}

void LineSegment::yAxisSymetry() {
    this->a.yAxisSymetry();
    this->b.yAxisSymetry();
}

void LineSegment::pSymetry(Point p) {
    this->a.pSymetry(p);
    this->b.pSymetry(p);
}

Line LineSegment::getLine() {
    Line l(this->getA(), this->getB());
    return l;
}

bool LineSegment::containsPoint(Point p) {
    return this->getLine().containsPoint(p) &&
           p.getX() <= std::fmax(this->a.getX(), this->b.getX()) &&
           p.getX() >= std::fmin(this->a.getX(), this->b.getX());
}

bool LineSegment::isParallel(LineSegment l) {
    return this->getLine().isParallel(l.getLine());
}

bool LineSegment::isPerpendicular(LineSegment l) {
    return this->getLine().isPerpendicular(l.getLine());
}