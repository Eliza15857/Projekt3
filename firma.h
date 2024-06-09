#ifndef FIRMA_H
#define FIRMA_H
#include <iostream>
#include <vector>
#include "pracownik.h"
#define DEBUG_
using namespace std;

class Firma
{
public:
    string nazwa;
    float przychod = 0;
    float wydatki = 0;
    static int l_firm;
    int l_pracownikow = 0;
    vector <Pracownik> pracownik;

    Firma();
    Firma(const Firma&);
    virtual ~Firma();

    virtual void dodajPracownika(const Pracownik&) = 0;

    virtual void setDane(string, float, float);
    virtual void setNazwa(string);
    virtual void setFinanse(float, float);
    virtual string getNazwa() = 0;
    virtual float getPrzychod() = 0;
    virtual float getWydatki() = 0;

    virtual void ObliczFinanse();

    bool operator<(const Firma&) const;
    bool operator>(const Firma&) const;
    bool operator<=(const Firma&) const;
    bool operator>=(const Firma&) const;
    bool operator==(const Firma&) const;
    bool operator!=(const Firma&) const;

    friend ostream& operator << (ostream&, Firma&);
    friend istream& operator >> (istream&, Firma&);
};
#endif // FIRMA_H
