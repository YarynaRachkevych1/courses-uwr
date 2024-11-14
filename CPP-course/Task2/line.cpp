#include <stdexcept>
#include "line.h"
#include "point.h"

//Konstruktor
Line::Line(Point a, Point b) {

    if (a.getX() == b.getX() && a.getY() == b.getY()) {
        throw std::invalid_argument("Punkty nie moga byc takie same - to nie bedzie prosta");
    }
    this->a = (a.getY() - b.getY()) / (a.getX() - b.getX());
    this->b = (a.getY() - this->a * a.getX());
}

double Line::getA() {
    return a;
}

bool Line::isParallel(Line l) {
    return this->a == l.getA();
}

bool Line::isPerpendicular(Line l) {
    return this->a * l.getA() == -1;
}

bool Line::containsPoint(Point p) {
    return this->a * p.getX() + this->b == p.getY();
}
