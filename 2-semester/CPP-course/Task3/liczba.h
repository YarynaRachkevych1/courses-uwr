#ifndef LISTA3_LICZBA_H
#define LISTA3_LICZBA_H

#endif //LISTA3_LICZBA_H

class Liczba{
private:

    static const int dl_histr = 3;
    int n;
    int index_histr;
    double* histr;

public:

    Liczba(double _n);
    Liczba();
    Liczba(const Liczba &other);
    Liczba(const Liczba &&other);

    ~Liczba();

    void zaspisywanie();
    void cofnij();
    double dajN() const;
    double *dajHistr() const;
    Liczba operator=(double _n);
};