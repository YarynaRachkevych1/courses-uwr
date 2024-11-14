#include "wyrazenie.h"

void Wyrazenie::setPriorytet(int wartosc) {
    priorytet = wartosc;
}

int Wyrazenie::getPriorytet() const {
    return priorytet;
}

void Wyrazenie::setLacznosc(int wartosc) {
    lacznosc = wartosc;
}

int Wyrazenie::getLacznosc() const {
    return lacznosc;
}
