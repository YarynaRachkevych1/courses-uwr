#ifndef ZADANIE6_WYRAZENIE_H
#define ZADANIE6_WYRAZENIE_H
#include <string>

class Wyrazenie{
private:
    int priorytet = 7;
    int lacznosc = 0;
public:
    Wyrazenie(const Wyrazenie& other) = delete;
    Wyrazenie& operator=(const Wyrazenie& other) = delete;
    Wyrazenie() = default;
    virtual double oblicz() = 0;
    virtual std::string zapisz() = 0;
    void setPriorytet(int value);
    int getPriorytet() const;
    void setLacznosc(int value);
    int getLacznosc() const;
    Wyrazenie* operator=(Wyrazenie* other) = delete;
};

#endif //ZADANIE6_WYRAZENIE_H
