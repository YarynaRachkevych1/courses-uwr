#ifndef ZADANIE8_WYMIERNA_H
#define ZADANIE8_WYMIERNA_H

namespace obliczenia{
    class Wymierna{
    private:
        int licz, mian;
    public:
        Wymierna(int _licz, int _mian);
        Wymierna(int _licz);
        Wymierna();
        int getLicz();
        int getMian();
        Wymierna operator+(Wymierna &other) const;
        Wymierna operator-(Wymierna &other) const;
        Wymierna operator*(Wymierna &other) const;
        Wymierna operator/(Wymierna &other) const;
        Wymierna operator-() const;
        Wymierna operator!() const;
        operator double() const;
        operator int() const;
    };
}

#endif //ZADANIE8_WYMIERNA_H
