#include "tab_bit.hpp"

const int tab_bit::rozmiarSlowa = 64;

// konstructor tab_bit:
// tablica n-bitowa z samymi zerami:
tab_bit::tab_bit(int rozm) {
    dl = rozm;

    tab = new slowo[1 + dl / 64];
    for(int i = 0; i <1+dl/64; i++) {
        tab[i]=0;
    }
}

tab_bit::tab_bit(slowo tb) {
    tab = new slowo;
    tab[0] = tb;

    dl = rozmiarSlowa;

}

