#ifndef ZAD1_KORISNIK_H
#define ZAD1_KORISNIK_H
#include <iostream>
#include <string>
using namespace std;

class Korisnik {
public:
    Korisnik(string i,string el) {
        ime=i;
        elPosta=el;
    }
    Korisnik(const Korisnik&) =delete;
    Korisnik operator=(const Korisnik&) =delete;

    friend ostream &operator<<(ostream &os, const Korisnik &k);
private:
    string ime;
    string elPosta;
};


#endif //ZAD1_KORISNIK_H
