#ifndef ZADANIE6_OPERATOR2ARG_H
#define ZADANIE6_OPERATOR2ARG_H
#include "operator1arg.h"

class Operator2Arg : public Operator1Arg {
private:
    Wyrazenie *arg2;
public:
    virtual std::string zapisz() override;
    Operator2Arg(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    virtual void set2Arg(Wyrazenie *wyrazenie);
    Wyrazenie *get2Arg();
};

class Dodaj : public Operator2Arg {
public:
    Dodaj(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};

class Odejmij : public Operator2Arg {
public:
    Odejmij(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};

class Logarytm : public Operator2Arg {
public:
    Logarytm(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};

class Mnoz : public Operator2Arg {
public:
    Mnoz(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};

class Modulo : public Operator2Arg {
public:
    Modulo(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};

class Potega : public Operator2Arg {
public:
    Potega(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};

class Dziel : public Operator2Arg {
public:
    Dziel(Wyrazenie *wyrazenie1, Wyrazenie *wyrazenie2);
    double oblicz() override;
};
#endif //ZADANIE6_OPERATOR2ARG_H