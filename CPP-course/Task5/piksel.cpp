#include <stdexcept>
#include <cmath>
#include "piksel.h"

Piksel::Piksel(){
    x = 0;
    y = 0;
}

Piksel::Piksel(int _x, int _y) {
    setX(_x);
    setY(_y);
}

void Piksel::setX(int _x) {
    if (_x < 0 || _x > resolutionX)
        throw std::invalid_argument("Wartosc musi byc z przedzialu [0...1024]");
    else
        x = _x;
}

void Piksel::setY(int _y) {
    if (_y < 0 || _y > resolutionX)
        throw std::invalid_argument("Wartosc musi byc z przedzialu [0...768]");
    else
        y = _y;
}

int Piksel::getX() const {
    return x;
}

int Piksel::getY() const {
    return y;
}

int Piksel::distanceLeft() const {
    return x;
}

int Piksel::distanceRight() const {
    return resolutionX - x;
}

int Piksel::distanceBottom() const {
    return y;
}

int Piksel::distanceTop() const {
    return resolutionY - y;
}

int distance(const Piksel &piksel1, const Piksel &piksel2) {
    return int(round(sqrt(pow(piksel1.getX() - piksel2.getX(), 2) + pow(piksel1.getY() - piksel2.getY(), 2))));
}

int distance(const Piksel *piksel1, const Piksel *piksel2) {
    return int(round(sqrt(pow(piksel1->getX() - piksel2->getX(), 2) + pow(piksel1->getY() - piksel2->getY(), 2))));
}