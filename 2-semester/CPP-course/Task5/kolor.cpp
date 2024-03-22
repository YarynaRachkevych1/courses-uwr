#include <stdexcept>
#include "kolor.h"

//Konstruktor bezargumentowy
Kolor::Kolor(){
    red = 0;
    green = 0;
    blue = 0;
}

//Konstruktor z podanymi wartosciami
Kolor::Kolor(int _red, int _green, int _blue){
    if ((_red < 0 || _red > 255) ||
        (_green < 0 || _green > 255) ||
        (_blue < 0 || _blue > 255)){
        throw std::range_error("któraś z podanych wartości wykrocza poza zakres [0...255]");
    } else{
        setRed(_red);
        setGreen(_green);
        setBlue(_blue);
    }
}


//Gettery dla każdej farby
int Kolor::getRed() const {
    return red;
}

int Kolor::getGreen() const {
    return green;
}

int Kolor::getBlue() const {
    return blue;
}


//Settery dla każdej farby
void Kolor::setRed(int newRed) {
    if (newRed > 255 || newRed < 0)
        throw std::invalid_argument("Wartosc musi byc z przedzialu [0...255]");
    else
        red = newRed;
}

void Kolor::setGreen(int newGreen) {
    if (newGreen > 255 || newGreen < 0)
        throw std::invalid_argument("Wartosc musi byc z przedzialu [0...255]");
    else
        green = newGreen;
}

void Kolor::setBlue(int newBlue) {
    if (newBlue > 255 || newBlue < 0)
        throw std::invalid_argument("Wartosc musi byc z przedzialu [0...255]");
    else
        blue = newBlue;
}

//Rozjaśnianie
void Kolor::lightening(int value) {
    if (red + value <= 255)
        red += value;
    else
        red = 255;
    if (green + value <= 255)
        green += value;
    else
        green = 255;
    if (blue + value <= 255)
        blue += value;
    else
        blue = 255;
}

//Przyciemnianie
void Kolor::darkening(int value) {
    if (red - value >= 0)
        red -= value;
    else
        red = 0;
    if (green - value >= 0)
        green -= value;
    else
        green = 0;
    if (blue - value >= 0)
        blue -= value;
    else
        blue = 0;
}