#include "point.h"
#include <cmath>

//Konstruktor
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

//Pobranie wartosci x i y
double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

//Znalezienie odległości między punktamidouble Point::distanceTo(Point other) {
double Point::distanceTo(Point p2) {
    double dx = x - p2.getX();
    double dy = y - p2.getY();
    return std::sqrt(dx * dx + dy * dy);
}

//Przesunięcie punktu o wektor
void Point::pMoveVector(Vector v) {
    this->x += v.getX();
    this->y += v.getY();
}

//Obrót punktu wzgłęgem innego
void Point::rotation(Point p, double angle) {
    double rad = angle * M_PI / 180;
    double xp = p.getX() + (x - p.getX()) * cos(rad) - (y - p.getY()) * sin(rad);
    double yp = p.getY() + (x - p.getX()) * sin(rad) + (y - p.getY()) * cos(rad);
    this->x = xp;
    this->y = yp;
}

//Odbicie wzglęgem osi x i y
void Point::xAxisSymetry() {
    this->y *= -1;
}

void Point::yAxisSymetry() {
    this->x *= -1;
}

//Odbicie wzglęgem punktu
void Point::pSymetry(Point p) {
    this->x = 2 * p.getX() - this->x;
    this->y = 2 * p.getY() - this->y;
}
