#include <iostream>
#include "lista.h"
#include "korisnik.h"
#include "vremenskaOznaka.h"
#include "elektronskaPorukaSaTekstom.h"
int main() {
    Korisnik k1("Tadija Ivkovic","tadija@gmail.com");
    Korisnik k2("Danica Ivkovic","danica@gmail.com");
    ElektronskaPorukaSaTekstom e(&k1,&k2,"domaci");
    e.dodajTekst("Jel si uradila domaci?");
    e.posalji();
    cout <<e;
    /*
    Lista <int> l;
    l.dodaj(5);
    l.dodaj(7);
    l.dodajPrvi(11);
    l.naPrvi();
    int a=l.dohvTek();
    cout << a;
    */
    return 0;
}
