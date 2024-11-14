#ifndef ZADANIE6_OPERATOR1ARG_H
#define ZADANIE6_OPERATOR1ARG_H
#include "wyrazenie.h"

class Operator1Arg
        : public Wyrazenie{
private:
    std::string operatorSymbol;
    Wyrazenie *arg;
protected:
    virtual void set1Arg(Wyrazenie *wyrazenie);
    void setOperatorSymbol(std::string _operatorSymbol);
    std::string getOperatorSymbol();
    Wyrazenie *get1Arg();
    Operator1Arg(Wyrazenie *wyrazenie);
public:
    std::string zapisz() override;
};


class Sin : public Operator1Arg{
    double oblicz() override;

public:
    Sin(Wyrazenie *wyrazenie);
};

class Cos : public Operator1Arg{
    double oblicz() override;

public:
    Cos(Wyrazenie *wyrazenie);
};

class Exp : public Operator1Arg{
    double oblicz() override;

public:
    Exp(Wyrazenie *wyrazenie);
};

class Ln : public Operator1Arg{
    double oblicz() override;

public:
    Ln(Wyrazenie *wyrazenie);
};

class Bezwzgl : public Operator1Arg{
    double oblicz() override;

public:
    Bezwzgl(Wyrazenie *wyrazenie);
};

class Przeciw : public Operator1Arg{
    double oblicz() override;

public:
    Przeciw(Wyrazenie *wyrazenie);
};

class Odwrot : public Operator1Arg{
    double oblicz() override;

public:
    Odwrot(Wyrazenie *wyrazenie);
};

#endif //ZADANIE6_OPERATOR1ARG_H