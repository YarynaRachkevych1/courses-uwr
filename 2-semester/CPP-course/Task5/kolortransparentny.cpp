#include <stdexcept>
#include "kolortransparentny.h"

//Konstruktor bezargumentowy
KolorTransparentny::KolorTransparentny(){
    setRed(0);
    setGreen(0);
    setBlue(0);
    alfa = 0;
}

//Konstruktor z podanymi wartosciami
KolorTransparentny::KolorTransparentny(int _red, int _green, int _blue, int _alfa) {
    if ((_alfa < 0 || _alfa > 255)){
        throw std::range_error("Wartosc alfa musi byc z przedzialu [0...255]");
    } else{
        setRed(_red);
        setGreen(_green);
        setBlue(_blue);
        alfa = _alfa;
    }
}

//Setter
void KolorTransparentny::setAlpha(int _alfa) {
    alfa = _alfa;
}

//Getter
int KolorTransparentny::getAlpha() {
    return alfa;
}

void KolorTransparentny::lightening(int value) {
    Kolor::lightening(value);
    if (alfa + value <= 255)
        alfa += value;
    else
        alfa = 255;
}

void KolorTransparentny::darkening(int value) {
    Kolor::darkening(value);
    if (alfa - value >= 0)
        alfa -= value;
    else
        alfa = 0;
}

