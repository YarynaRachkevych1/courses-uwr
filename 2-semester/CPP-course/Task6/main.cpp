#include <iostream>
#include "wyrazenie.h"
#include "operandy.h"
#include "operator1arg.h"
#include "operator2arg.h"

using namespace std;

int main() {
    //Zmienne
    Zmienna::dodajZmienna("x", -4);
    Zmienna::dodajZmienna("y", -3);

    //Liczba
    Liczba *lcz = new Liczba(2);

    //Stale
    Stala *pi = new Stala("pi");
    Stala *e = new Stala("e");
    Stala *fi = new Stala("fi");

    //Operatory 1 argumentowe
    Wyrazenie *cos = new Cos(pi);
    cout << "Cos od pi: " << cos->oblicz() << endl;

    Wyrazenie *sin = new Sin(e);
    cout << "Sin od e: " << sin->oblicz() << endl;

    Wyrazenie *exp = new Exp(fi);
    cout << "Exp od fi: " << exp->oblicz() << endl;

    Wyrazenie *ln = new Ln(e);
    cout << "Logarytm naturalny od e: " << ln->oblicz() << endl;

    Wyrazenie *bezwzgl = new Bezwzgl(lcz);
    cout << "Wartosc bezwzgledna od lcz: " << bezwzgl->oblicz() << endl;

    Wyrazenie *przeciw = new Przeciw(lcz);
    cout << "Przeciwna dla lcz: " << przeciw->oblicz() << endl;

    Wyrazenie *odwrot = new Odwrot(lcz);
    cout << "Odwrotnosc dla lcz: " << odwrot->oblicz() << endl;

    cout << "\nWyrazenienia: " << endl;
    Wyrazenie *a = new Dziel(new Mnoz(new Odejmij(new Zmienna("x"), new Liczba(1)), new Zmienna("x")), new Liczba(2));
    cout << a->zapisz() << " = " << a->oblicz() << endl;

    //(3+5)/(2+x*7)
    Wyrazenie *b = new Dziel(new Dodaj(new Liczba(3), new Liczba(5)),
                            new Dodaj(new Liczba(2), new Mnoz(new Zmienna("x"), new Liczba(7))));
    cout << b->zapisz() << " = " << b->oblicz() << endl;

    //2+x*7-(y*3+5)
    Wyrazenie* c = new Odejmij(new Dodaj(new Liczba(2), new Mnoz(new Zmienna("x"), new Liczba(7))),
                             new Dodaj(new Mnoz(new Zmienna("y"), new Liczba(3)), new Liczba(5)));
    cout << c->zapisz() << " = " << c->oblicz() << endl;

    //cos((x+1)*pi)/e^x^2
    Wyrazenie* d = new Dziel(new Cos(new Mnoz(new Dodaj(new Zmienna("x"), new Liczba(1)), new Stala("pi"))), new Potega(new Potega(new Stala("e"), new Zmienna("x")), new Liczba(2)));
    cout << d->zapisz() << " = " << d->oblicz() << endl;
    return 0;
}
