#ifndef ZAD1_ELEKTRONSKAPORUKASATEKSTOM_H
#define ZAD1_ELEKTRONSKAPORUKASATEKSTOM_H
#include "elektronskaPosta.h"
class GPoslata{
    friend ostream& operator<<(ostream& os,const GPoslata &p){
        return os << "***Tekst se ne moze menjati nakon slanja!***\n";

    }
};

class ElektronskaPorukaSaTekstom : public ElektronskaPosta{
public:
    ElektronskaPorukaSaTekstom(const ElektronskaPosta& p) : ElektronskaPosta(p){}

    ElektronskaPorukaSaTekstom(Korisnik *pos, Korisnik *prim,string n) : ElektronskaPosta(pos,prim,n) {
        stanje=U_PRIPREMI;
    }

    void dodajTekst(string t){
        if(stanje==1 || stanje==2) throw GPoslata();
        tekst=t;
    }
    void posalji() override{
        stanje=POSLATA;
    }

    friend ostream &operator<<(ostream &os,const ElektronskaPorukaSaTekstom &e);

private:
    string tekst;

    void pisi(ostream &os) const override;
};


#endif //ZAD1_ELEKTRONSKAPORUKASATEKSTOM_H
