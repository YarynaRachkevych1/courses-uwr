#ifndef ZADANIE5_KOLORNAZWANY_H
#define ZADANIE5_KOLORNAZWANY_H

#include <string>
#include "kolor.h"

//Publiczne dziedziczenie
class KolorNazwany
        : public virtual Kolor{
private:
    std::string name;

public:
    KolorNazwany();
    KolorNazwany(int _red, int _green, int _blue);

    void setName(std::string _name);
    std::string getName();
};
#endif //ZADANIE5_KOLORNAZWANY_H