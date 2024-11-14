#ifndef ZADANIE5_KOLORNT_H
#define ZADANIE5_KOLORNT_H

#include "kolortransparentny.h"
#include "kolornazwany.h"

//Dziedziczenie wielobazowe
class Kolornt
        : public KolorTransparentny, public KolorNazwany{
public:
    Kolornt();

    Kolornt(int _red, int _green, int _blue, int _alfa, std::string _name);

};
#endif //ZADANIE5_KOLORNT_H
