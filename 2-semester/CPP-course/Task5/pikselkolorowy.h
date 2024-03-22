#ifndef ZADANIE5_PIKSELKOLOROWY_H
#define ZADANIE5_PIKSELKOLOROWY_H

#endif //ZADANIE5_PIKSELKOLOROWY_H
#include "piksel.h"
#include "kolortransparentny.h"

class PikselKolorowy
        : public Piksel{
private:
    KolorTransparentny color;

public:
    PikselKolorowy();
    PikselKolorowy(int _x, int _y, KolorTransparentny _color);

    void setColor(KolorTransparentny _color);

    void moveVector(int x, int y);
};
