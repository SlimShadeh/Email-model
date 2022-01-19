#ifndef ZAD1_ELEKTRONSKAPOSTA_H
#define ZAD1_ELEKTRONSKAPOSTA_H
#include "korisnik.h"
enum st {U_PRIPREMI,POSLATA,PRIMLJENA};
class ElektronskaPosta {
public:
    ElektronskaPosta(Korisnik *pos, Korisnik *prim,string n) : posiljalac(pos) , primalac(prim) {
        naslov=n;
        stanje=U_PRIPREMI;
    }

    Korisnik *getPosiljalac() const {
        return posiljalac;
    }

    Korisnik *getPrimalac() const {
        return primalac;
    }

    st getStanje() const {
        return stanje;
    }

    const string &getNaslov() const {
        return naslov;
    }

    virtual void posalji(){
        stanje=POSLATA;
    }

    friend ostream &operator <<(ostream &os,const ElektronskaPosta &e);
protected:
    Korisnik *posiljalac,*primalac;
    st stanje ;
    string naslov;

    virtual void pisi(ostream &os) const;
};


#endif //ZAD1_ELEKTRONSKAPOSTA_H
