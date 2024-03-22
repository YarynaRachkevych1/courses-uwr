#include <cmath>
#include <stdexcept>
#include "operator1arg.h"

void Operator1Arg::set1Arg(Wyrazenie *wyrazenie) {
    arg = wyrazenie;
}

Wyrazenie *Operator1Arg::get1Arg() {
    return arg;
}

void Operator1Arg::setOperatorSymbol(std::string _operatorSymbol) {
    operatorSymbol = _operatorSymbol;
}

std::string Operator1Arg::getOperatorSymbol() {
    return operatorSymbol;
}

Operator1Arg::Operator1Arg(Wyrazenie *wyrazenie)
    : arg((Wyrazenie* ) wyrazenie), operatorSymbol("") {

}

std::string Operator1Arg::zapisz() {
    return getOperatorSymbol() + "(" + arg->zapisz() + ")";
}


double Sin::oblicz() {
    return std::sin(get1Arg()->oblicz());
}

Sin::Sin(Wyrazenie *wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("sin");
}

double Cos::oblicz() {
    return std::cos(get1Arg()->oblicz());
}

Cos::Cos(Wyrazenie *wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("cos");
}

double Exp::oblicz() {
    return std::exp(get1Arg()->oblicz());
}

Exp::Exp(Wyrazenie *wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("exp");
}

double Ln::oblicz() {
    return std::log(get1Arg()->oblicz());
}

Ln::Ln(Wyrazenie *wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("ln");
    if (wyrazenie->oblicz() <= 0) {
        throw std::invalid_argument("Liczba logarytmowana musi byc dodatnia");
    }
    Operator1Arg::set1Arg(wyrazenie);
}

double Bezwzgl::oblicz() {
    return std::abs(get1Arg()->oblicz());
}

Bezwzgl::Bezwzgl(Wyrazenie *wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("bezwzgl");
}

double Przeciw::oblicz() {
    return -1 * get1Arg()->oblicz();
}

Przeciw::Przeciw(Wyrazenie *wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("przeciw");
}

double Odwrot::oblicz() {
    return 1 / get1Arg()->oblicz();
}

Odwrot::Odwrot(Wyrazenie* wyrazenie) : Operator1Arg(wyrazenie) {
    setOperatorSymbol("odwrot");
    if (wyrazenie->oblicz() == 0) {
        throw std::invalid_argument("Zero nie ma liczby odwrotnej");
    }
    Operator1Arg::set1Arg(wyrazenie);
}