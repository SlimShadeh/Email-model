#ifndef ZAD1_VREMENSKAOZNAKA_H
#define ZAD1_VREMENSKAOZNAKA_H
#include <iostream>
using namespace std;

class VremenskaOznaka {
public:
    VremenskaOznaka(int g,int m,int d,int s,int min);

    friend ostream& operator<<(ostream &os, const VremenskaOznaka &v);
private:
    int godina,mesec,dan,sat,minut;
};

#endif //ZAD1_VREMENSKAOZNAKA_H
