#ifndef FIRMATRANSPORTOWA_H
#define FIRMATRANSPORTOWA_H
#include "firma.h"
#define DEBUG_

class FirmaTransportowa : public Firma
{
protected:
    int liczba_pojazdow = 0;
    static int l_ftransp;
public:
    //KONSTRUKTORY i DESTRUKTOR
    FirmaTransportowa();
    FirmaTransportowa(const FirmaTransportowa&);
    virtual ~FirmaTransportowa();
    //DODAWANIE
    virtual void dodajPracownika(const Pracownik&);
    //USTAW DANE
    virtual void setDane(string, float, float, int);
    void setLPojazdow(int);
    //ZWROC DANE
    virtual string getNazwa();
    virtual float getPrzychod();
    virtual float getWydatki();
    int getLiczbaPojazdow();
    virtual void ObliczFinanse();
    //OPERATOR STRUMIENIOWY
    friend ostream& operator << (ostream&, FirmaTransportowa&);
    friend istream& operator >> (istream&, FirmaTransportowa&);
};

#endif // FIRMATRANSPORTOWA_H
