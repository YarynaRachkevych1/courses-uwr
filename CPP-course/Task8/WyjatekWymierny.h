#include <stdexcept>

#ifndef ZADANIE8_MYEXCEPTION_H
#define ZADANIE8_MYEXCEPTION_H

class WyjatekWymierny : public std::logic_error{
protected:
    explicit WyjatekWymierny(const std::string& message) : std::logic_error(message) {}
};

class PrzekroczenieZakresu : public WyjatekWymierny {
public:
    explicit PrzekroczenieZakresu(const std::string& message) : WyjatekWymierny(message) {}
};

class DzieleniePrzez0 : public WyjatekWymierny {
public:
    explicit DzieleniePrzez0(const std::string& message) : WyjatekWymierny(message) {}
};

#endif //ZADANIE8_MYEXCEPTION_H
