#include <stdexcept>
#include "kolornazwany.h"

KolorNazwany::KolorNazwany() {
    setRed(0);
    setGreen(0);
    setBlue(0);
    name = "";
}

KolorNazwany::KolorNazwany(int _red, int _green, int _blue) {
    setRed(_red);
    setGreen(_green);
    setBlue(_blue);
    name = "";
}

void KolorNazwany::setName(std::string _name) {
    for (char c : name)
        if (!islower(c) || !isalpha(c))
            throw std::invalid_argument("Podana nazwa nie jest możliwa");
    name = _name;
}

std::string KolorNazwany::getName() {
    return name;
}