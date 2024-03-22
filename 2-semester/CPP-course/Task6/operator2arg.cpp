#include <cmath>
#include "operator2arg.h"

void Operator2Arg::set2Arg(Wyrazenie *wyrazenie) {
    arg2 = wyrazenie;
}

Wyrazenie *Operator2Arg::get2Arg() {
    return arg2;
}

Operator2Arg::Operator2Arg(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
    : Operator1Arg(wyrazenie1), arg2(wyrazenie2){

}

std::string Operator2Arg::zapisz() {
    std::string expression1 = get1Arg()->zapisz();
    std::string expression2 = get2Arg()->zapisz();
    if (get1Arg()->getPriorytet() < getPriorytet() || (get1Arg()->getPriorytet() == getPriorytet() && (getLacznosc() == 2 || getLacznosc() == 0))) {
        expression1 = "(" + expression1 + ")";
    }
    if (get2Arg()->getPriorytet() < getPriorytet() || (get2Arg()->getPriorytet() == getPriorytet() && (getLacznosc() == 1 || getLacznosc() == 0))) {
        expression2 = "(" + expression2 + ")";
    }
    return expression1 + getOperatorSymbol() + expression2;
}

double Dodaj::oblicz() {
    return get1Arg()->oblicz() + get2Arg()->oblicz();
}

Dodaj::Dodaj(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
    : Operator2Arg(wyrazenie1, wyrazenie2){
    setOperatorSymbol("+");
    setPriorytet(2);
    setLacznosc(3);
}

double Odejmij::oblicz() {
    return get1Arg()->oblicz() - get2Arg()->oblicz();
}

Odejmij::Odejmij(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
        : Operator2Arg(wyrazenie1, wyrazenie2){
    setOperatorSymbol("-");
    setPriorytet(2);
    setLacznosc(1);
}

double Mnoz::oblicz() {
    return get1Arg()->oblicz() * get2Arg()->oblicz();
}

Mnoz::Mnoz(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
        : Operator2Arg(wyrazenie1, wyrazenie2){
    setOperatorSymbol("*");
    setPriorytet(3);
    setLacznosc(3);
}

double Dziel::oblicz() {
    return get1Arg()->oblicz() / get2Arg()->oblicz();
}

Dziel::Dziel(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
        : Operator2Arg(wyrazenie1, wyrazenie2){
    setOperatorSymbol("/");
    setPriorytet(3);
    setLacznosc(2);
}

double Logarytm::oblicz() {
    return std::log(get1Arg()->oblicz()) / log(get2Arg()->oblicz());
}

Logarytm::Logarytm(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
        : Operator2Arg(wyrazenie1, wyrazenie2){
    set1Arg(wyrazenie1);
    set2Arg(wyrazenie2);
    setPriorytet(5);
}

double Modulo::oblicz() {
    return (int)get1Arg()->oblicz() % (int)get2Arg()->oblicz();
}

Modulo::Modulo(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
        : Operator2Arg(wyrazenie1, wyrazenie2){
    set1Arg(wyrazenie1);
    set2Arg(wyrazenie2);
    setPriorytet(1);
}

double Potega::oblicz() {
    return std::pow(get1Arg()->oblicz(), get2Arg()->oblicz());
}

Potega::Potega(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2)
    : Operator2Arg(wyrazenie1, wyrazenie2) {
    setOperatorSymbol("^");
    setPriorytet(4);
    setLacznosc(1);
}