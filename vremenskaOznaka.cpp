#include "vremenskaOznaka.h"

ostream &operator<<(ostream &os, const VremenskaOznaka &v) {
    return os << v.dan << '.' << v.mesec << '.' << v.godina << '-' << v.sat <<':' << v.minut;
}

VremenskaOznaka::VremenskaOznaka(int g, int m, int d, int s, int min) {
    godina =(g> 1950 && g< 2022 ? g : 1950);
    mesec= (m>0 && m<13 ? m : 1);
    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dan=(d>0 && d<32 ? d : 1);
        case 4: case 6: case 9: case 11:
            dan=(d>0 && d<31 ? d : 1);
        case 2:
            if(g%400==0) dan=(d>0 && d<30 ? d : 1);
            else if(g%4==0 && g%100!=0) dan=(d>0 && d<30 ? d : 1);
            else dan=(d>0 && d<29 ? d : 1);
    }
    sat=(s>0 && s<61 ? s : 1);
    minut=(min>0 && min<61 ? min : 1);
}
