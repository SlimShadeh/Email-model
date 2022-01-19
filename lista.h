#ifndef UNTITLED11_LISTA_H
#define UNTITLED11_LISTA_H
#include <iostream>
using namespace std;
class GNemaTek{
    friend ostream& operator<<(ostream& os,const GNemaTek &t){
        return os << "***Nema tekuceg!***\n";

    }
};

template<typename T>
class Lista {
    struct Elem {
        T pod;
        Elem *sled;
        Elem(const T& p, Elem *s=nullptr){
            pod=p;
            sled=s;
        }
    };
    Elem *prvi,*posl;
    mutable Elem *tek;
    mutable Elem *pret;

    void isprazni();
    void kopiraj(const Lista &l);
    void premesti(Lista &l) {
        prvi=l.prvi;
        posl=l.posl;
        l.prvi=l.posl=nullptr;
    };
public:
    ~Lista(){
        isprazni();
    }
    Lista(){
        prvi=posl=tek=pret=nullptr;
    }
    Lista(const Lista &l){
        kopiraj(l);
    }
    Lista(Lista &&l){
        premesti(l);
    }
    Lista &operator =(const Lista &l){
        if(this !=&l){
            isprazni();
            kopiraj(l);
        }
        return *this;
    }
    Lista &operator =(Lista &&l){
        if(this !=&l){
            isprazni();
            premesti(l);
        }
        return *this;
    }

    Lista& dodaj(const T& t){
        posl=(!prvi ? prvi :posl->sled)=new Elem (t);

        return *this;
    }

    Lista& dodajPrvi(const T& t){
        Elem *novi=new Elem(t);
        if(!prvi) {
            prvi=posl=novi;
        }
        else{
            novi->sled=prvi;
            prvi=novi;
        }
    }

    void naPrvi() {
        tek=prvi;
        pret=nullptr;
    }

    void naSled()const{
        pret=tek;
        if(tek)tek=tek->sled;
    }

    bool imaTek() const {
        return tek !=nullptr;
    }
    int dohvBrojEl() const{
        int br=0;
        for(Elem *pok=prvi;pok;pok=pok->sled){
            br++;
        }
        return br;
    }

    T& dohvTek() {
        if(!tek) throw GNemaTek();
        return tek->pod;
    }
};

template <typename T>
void Lista<T>::kopiraj(const Lista<T> &l) {
    prvi=posl=tek=pret=nullptr;
    for(Elem *pok=l.prvi;pok;pok=pok->sled){
        Elem *novi =new Elem(pok->pod);
        posl=(!prvi ? prvi : posl->sled)=novi;

        if(pok==l.tek)tek=novi;
        if(pok==l.pret)pret=novi;
    }
}

template <typename T>
void Lista<T>::isprazni() {
    while(prvi){
        Elem *stari=prvi;
        prvi=prvi->sled;
        delete stari;
    }
    posl=tek=pret=nullptr;
}

#endif //UNTITLED11_LISTA_H
