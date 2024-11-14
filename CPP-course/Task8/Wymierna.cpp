#include "Wymierna.h"
#include "WyjatekWymierny.h"

int nwd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return nwd(b, a % b);
}

obliczenia::Wymierna::Wymierna() {
    licz = 0;
    mian = 1;
}

obliczenia::Wymierna::Wymierna(int _licz) {
    licz = _licz;
    mian = 1;
}

obliczenia::Wymierna::Wymierna(int _licz, int _mian) {
    if (_mian <= 0){
        throw DzieleniePrzez0 ("Mianownik nie moze byc < 0!");
    }
    int _nwd = nwd(_licz, _mian);

    licz = _licz / _nwd;
    mian = _mian / _nwd;
}

int obliczenia::Wymierna::getLicz() {
    return licz;
}

int obliczenia::Wymierna::getMian() {
    return mian;
}

obliczenia::Wymierna obliczenia::Wymierna::operator+(Wymierna &other) const{
    int64_t _licz = static_cast<int64_t>(licz) * other.mian + static_cast<int64_t>(other.licz) * mian;
    int64_t _mian = static_cast<int64_t>(mian) * other.mian;
    if (_licz < INT8_MIN || _licz > INT8_MAX || _mian < INT8_MIN || _mian > INT8_MAX) {
        throw PrzekroczenieZakresu ("Watrosc wykracza poza typ int!");
    }
    return Wymierna(static_cast<int>(_licz), static_cast<int>(_mian));
}


obliczenia::Wymierna obliczenia::Wymierna::operator-(Wymierna &other) const{
    int64_t _licz = static_cast<int64_t>(licz) * other.mian - static_cast<int64_t>(other.licz) * mian;
    int64_t _mian = static_cast<int64_t>(mian) * other.mian;
    if (_licz < INT8_MIN || _licz > INT8_MAX || _mian < INT8_MIN || _mian > INT8_MAX) {
        throw PrzekroczenieZakresu ("Watrosc wykracza poza typ int!");
    }
    return Wymierna(static_cast<int>(_licz), static_cast<int>(_mian));
}

obliczenia::Wymierna obliczenia::Wymierna::operator*(Wymierna &other) const{
    int64_t _licz = static_cast<int64_t>(licz) * static_cast<int64_t>(other.licz);
    int64_t _mian = static_cast<int64_t>(mian) * static_cast<int64_t>(other.mian);
    if (_licz < INT8_MIN || _licz > INT8_MAX || _mian < INT8_MIN || _mian > INT8_MAX) {
        throw PrzekroczenieZakresu ("Watrosc wykracza poza typ int!");
    }
    return Wymierna(static_cast<int>(_licz), static_cast<int>(_mian));
}

obliczenia::Wymierna obliczenia::Wymierna::operator/(Wymierna &other) const{
    int64_t _licz = static_cast<int64_t>(licz) * static_cast<int64_t>(other.mian);
    int64_t _mian = static_cast<int64_t>(mian) * static_cast<int64_t>(other.licz);
    if (_licz < INT8_MIN || _licz > INT8_MAX || _mian < INT8_MIN || _mian > INT8_MAX) {
        throw PrzekroczenieZakresu ("Wartość wykracza poza typ int!");
    }
    return Wymierna(static_cast<int>(_licz), static_cast<int>(_mian));
}

obliczenia::Wymierna obliczenia::Wymierna::operator-() const{
    return Wymierna(-licz, mian);
}

obliczenia::Wymierna obliczenia::Wymierna::operator!() const{
    if (mian == 0)
        throw DzieleniePrzez0("Mianownik nie może byc 0!");
    if (mian > 0)
        return obliczenia::Wymierna(mian, licz);
    return obliczenia::Wymierna(-mian, -licz);
}

obliczenia::Wymierna::operator double() const {
    return static_cast<double>(static_cast<double>(licz) / static_cast<double>(mian));
}

obliczenia::Wymierna::operator int() const {
    return static_cast<int>(licz / mian);
}