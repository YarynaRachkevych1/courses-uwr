#include <stdexcept>
#include "pikselkolorowy.h"

PikselKolorowy::PikselKolorowy() {
    setX(0);
    setY(0);
    color = KolorTransparentny();
}

PikselKolorowy::PikselKolorowy(int _x, int _y, KolorTransparentny _color) {
    setX(_x);
    setY(_y);
    setColor(_color);
}

void PikselKolorowy::setColor(KolorTransparentny _color) {
    color = _color;
}

void PikselKolorowy::moveVector(int vectorX, int vectorY) {
    if (getX() + vectorX < 0 || getX() + vectorX > resolutionX || getY() + vectorY < 0 || getY() + vectorY > resolutionY)
        throw std::invalid_argument("Piksel wychodzi za ekran, podaj inny wektor");
    else{
        setX(getX() + vectorX);
        setY(getY() + vectorY);
    }
}