//
// Created by tadij on 1/9/2022.
//

#include "elektronskaPorukaSaTekstom.h"

void ElektronskaPorukaSaTekstom::pisi(ostream &os) const {
    ElektronskaPosta::pisi(os);
    os << tekst;
}

ostream &operator<<(ostream &os, const ElektronskaPorukaSaTekstom &e) {
    e.pisi(os);
    return os;
}
