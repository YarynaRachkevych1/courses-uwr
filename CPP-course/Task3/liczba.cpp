#include "liczba.h"

//Konstruktor z zadaną watością
Liczba::Liczba(double _n){
    n = _n;
    histr = new double[dl_histr]();
    index_histr = 0;
    zaspisywanie();
}

//Konstruktor bezparametrowy
Liczba::Liczba() : Liczba(0) {
}

//Konstruktor kopiujący
Liczba::Liczba(const Liczba &other) : n(0), index_histr(0){
    histr = new double [dl_histr];
    histr[1]=other.n;
}


//Konstruktor delegatowy
Liczba::Liczba(const Liczba &&other) {
    n = other.n;
    histr = other.histr;
    index_histr = other.index_histr;
}

//Dekonstruktor
Liczba::~Liczba(){
    delete[] histr;
}

double Liczba::dajN() const{
    return n;
}

void Liczba::zaspisywanie(){
    histr[index_histr%dl_histr] = n;
    index_histr++;
}

void Liczba::cofnij() {
    n = histr[(index_histr + 1)%dl_histr];
    index_histr--;
}

Liczba Liczba::operator=(double _n){
    n = _n;
    zaspisywanie();
    return *this; //Zwraca ten sam objekt
}
