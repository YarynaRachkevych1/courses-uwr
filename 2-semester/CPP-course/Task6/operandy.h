#ifndef ZADANIE6_LICZBA_H
#define ZADANIE6_LICZBA_H
#include "wyrazenie.h"
#include <vector>

class Liczba final
        : public Wyrazenie{
private:
    double wartosc;
public:
    Liczba(double _watosc);
    double oblicz() override;
    std::string zapisz() override;
};


class Stala final
        : public Wyrazenie{
private:
    std::string nazwa;
    double wartosc;
    const std::vector<std::pair<std::string, double>> zm = {
            {"e", 2.71828}, {"fi", 1.61803}, {"pi", 3.14159}
    };
public:
    Stala(std::string _nazwa);
    double oblicz() override;
    std::string zapisz() override;
};


class Zmienna final
        : public Wyrazenie{
private:
    std::string nazwa;
    static std::vector<std::pair<std::string, double>> wartosci;
public:
    Zmienna(std::string _nazwa);

    double oblicz() override;
    std::string zapisz() override;

    static void dodajZmienna(std::string nazwa, double wartosc);
    static void usunZmienna(std::string nazwa);
    static void zmienZmienna(std::string nazwa, double wartosc);
};

#endif //ZADANIE6_LICZBA_H
