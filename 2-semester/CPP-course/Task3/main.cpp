#include <iostream>
#include "liczba.h"

using namespace std;

int main() {
    Liczba a(32);
    Liczba b = 42;
    Liczba c = (Liczba (Liczba(52)));

    cout << "Liczba a: " << a.dajN() << endl;
    cout << "Liczba b: " << b.dajN() << endl;
    cout << "Liczba c: " << c.dajN() << endl << endl;

    a = 33;
    cout << "Liczba a, zmiana 1: " << a.dajN() << endl;

    a = 34;
    cout << "Liczba a, zmiana 2: " << a.dajN() << endl;

    a = 35;
    cout << "Liczba a, zmiana 3: " << a.dajN() << endl;

    a = 36;
    cout << "Liczba a, zmiana 4: " << a.dajN() << endl;

    a.cofnij();
    cout << "Cofnij jedna zmiane: " << a.dajN() << endl;

    a.cofnij();
    cout << "Cofnij dwie zmiany: " << a.dajN() << endl;

    return 0;
}
