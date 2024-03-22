#include "kolornt.h"

Kolornt::Kolornt() {
    setRed(0);
    setGreen(0);
    setBlue(0);
    setName("");
}

Kolornt::Kolornt(int _red, int _green, int _blue, int _alfa, std::string _name){
    setRed(_red);
    setGreen(_green);
    setBlue(_blue);
    setName(_name);
}