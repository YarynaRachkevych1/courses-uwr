#include <iostream>
#include "Wymierna.h"
#include "WyjatekWymierny.h"

using namespace obliczenia;
using namespace std;

int main() {
    obliczenia::Wymierna a(3);
    obliczenia::Wymierna c(INT_MAX);
    obliczenia::Wymierna b(1, 4);
    cout << "Liczba a: " << double(a) << endl;
    cout << "Liczba b: " << double(b) << endl << endl;

    cout << "a + c: " << double(a + b) << endl;
    cout << "a - b: " << double(a - b) << endl;
    cout << "a * b: " << double(a * b) << endl;
    cout << "a / b: " << double(a / b) << endl << endl;

    cout << "-a: " << double(-a) << endl;
    cout << "!a: " << double(!a) << endl;

}