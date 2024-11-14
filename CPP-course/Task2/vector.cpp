#include "vector.h"

//Konstruktor
Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

//Pobranie wartosci x i y
double Vector::getX() {
    return x;
}

double Vector::getY() {
    return y;
}

