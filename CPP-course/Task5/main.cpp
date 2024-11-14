#include <iostream>
#include "kolornazwany.h"
#include "kolornt.h"
#include "pikselkolorowy.h"

using namespace std;

string print_kolor(int red, int green, int blue) {
    return "Wartosc: ("+to_string(red)+", "+to_string(green)+", "+to_string(blue)+")";
}

int main() {
    //Kolory
    Kolornt k1(48, 213, 200, 4, "turkusowy");
    Kolornt k2(0, 0, 80, 45, "granatowy");

    cout << "Nazwa k1: " << k1.getName() << ", " << print_kolor(k1.getRed(), k1.getGreen(), k1.getBlue()) << endl;
    cout << "Nazwa k2: " << k2.getName() << ", " << print_kolor(k2.getRed(), k2.getGreen(), k2.getBlue()) << endl;
    k1.lightening(40);
    k1.setName("zielony");
    cout << "\nRozjasniony z inna nazwa k1:" << endl;
    cout << "Nazwa k1: " << k1.getName() << ", Wartosc: (" << k1.getRed() << ", " << k1.getGreen() << ", " << k1.getBlue() << ")" << endl;

    Kolor k3;
    k3 = Kolor::kombineKolor(k1, k2);
    cout << "Kombinacja kolorow k1 i k2: ("<< k3.getRed() << ", " << k3.getGreen() << ", " << k3.getBlue() << ")" << endl;


    //Piksele
    PikselKolorowy pk1(12, 28, k1);
    PikselKolorowy pk2(1000, 0, k2);

    cout << "\npk1: Koordynaty (" << pk1.getX() << ", " << pk1.getY() << "), " << print_kolor(k1.getRed(), k1.getGreen(), k1.getBlue()) << endl;
    cout << "pk2: Koordynaty (" << pk2.getX() << ", " << pk2.getY() << "), " << print_kolor(k2.getRed(), k2.getGreen(), k2.getBlue()) << endl;

    cout << "\nPrzesuwanie pk1 o wektor (28, -28): " << endl;
    pk1.moveVector(28, -28);
    cout << "Nowe koordynaty pk1: (" << pk1.getX() << ", " << pk1.getY() << ")" << endl;

    cout << "\nOdleglosc pk2 do brzegow ekranu :" << endl;
    cout << "Odleglosc do lewego bregu: " << pk2.distanceLeft() << endl;
    cout << "Odleglosc do prawego bregu: " << pk2.distanceRight() << endl;
    cout << "Odleglosc do gornego bregu: " << pk2.distanceTop() << endl;
    cout << "Odleglosc do dolnego bregu: " << pk2.distanceBottom() << endl;

    cout << "\nOdleglosc miedzy pk1 i pk2: " << distance(pk1, pk2) << endl;
    return 0;
}
