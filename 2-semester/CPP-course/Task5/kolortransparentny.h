#ifndef ZADANIE5_KOLORTRANSPARENTNY_H
#define ZADANIE5_KOLORTRANSPARENTNY_H
#include "kolor.h"

//Publiczne dziedziczenie
class KolorTransparentny
        : public virtual Kolor{
private:
    int alfa;

public:
    KolorTransparentny();
    KolorTransparentny(int _red, int _green, int _blue, int _alfa);

    void setAlpha(int _alfa);
    int getAlpha();

    void lightening(int value);
    void darkening(int value);
};
#endif //ZADANIE5_KOLORTRANSPARENTNY_H