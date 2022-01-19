#include "elektronskaPosta.h"

ostream &operator<<(ostream &os,const ElektronskaPosta &e) {
    e.pisi(os);
    return os;
}

void ElektronskaPosta::pisi(ostream &os)const {
    os << naslov << "\n" << *posiljalac << "\n" << *primalac <<"\n";
}
