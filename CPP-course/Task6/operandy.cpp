#include <algorithm>
#include <stdexcept>
#include "operandy.h"

//Liczby
Liczba::Liczba(double _watosc) {
    wartosc = _watosc;
}

double Liczba::oblicz() {
    return wartosc;
}

std::string Liczba::zapisz() {
    return std::to_string(wartosc);
}

//Stale
Stala::Stala(std::string _nazwa) {
    for (auto const& p : zm) {
        if (p.first == _nazwa) {
            nazwa = p.first;
            wartosc = p.second;
            break; }
        }
}

double Stala::oblicz() {
    return wartosc;
}

std::string Stala::zapisz() {
    return nazwa;
}

//Zmienne
Zmienna::Zmienna(std::string _nazwa) {
    nazwa = _nazwa;
}

double Zmienna::oblicz() {
    for (const std::pair<std::string, double> wartosci: wartosci) {
        if (wartosci.first == nazwa) {
            return wartosci.second;
        }
    }
    throw std::invalid_argument("Zmienna nie ma wartosci");
}

std::string Zmienna::zapisz() {
    return nazwa;
}

void Zmienna::dodajZmienna(std::string _nazwa, double _warotsc) {
    Zmienna::wartosci.push_back(std::pair<std::string, double>(_nazwa,_warotsc));
}

void Zmienna::usunZmienna(std::string nazwa) {
    int i = 0;
    for (std::pair<std::string, double> wartosc: Zmienna::wartosci) {
        if (wartosc.first == nazwa) {
            wartosci.erase(wartosci.begin() + i);
            break;
        }
        i++;
    }
}

void Zmienna::zmienZmienna(std::string nazwa, double warotsc) {
    usunZmienna(nazwa);
    dodajZmienna(nazwa, warotsc);
}

std::vector<std::pair<std::string, double>> Zmienna::wartosci;