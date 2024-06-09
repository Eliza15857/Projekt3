#ifndef FIRMABUDOWLANA_H
#define FIRMABUDOWLANA_H
#include "firma.h"
#include "materialy.h"
#define DEBUG_

class FirmaBudowlana : public Firma
{
protected:
    string typ_budowy;
    static int l_fbud;
    int l_materialow;
    vector <Materialy> materialy;
public:
    //KONSTRUKTORY i DESTRUKTOR
    FirmaBudowlana(string p_nazwa_firmy = " ", float p_dochod = 0, int p_wydatki = 0);
    FirmaBudowlana(const FirmaBudowlana&);
    virtual ~FirmaBudowlana();

    //METODY
    virtual void dodajPracownika(const Pracownik&);
    void dodajMaterial(const Materialy&);

    virtual void setDane(string, float, float, string);
    void setBudowe(string);

    virtual string getNazwa();
    virtual float getPrzychod();
    virtual float getWydatki();
    string getTypbudowy();

    virtual void ObliczFinanse();

    //OPERATORY
    double operator-();
    Pracownik& operator+(const Pracownik&);
    FirmaBudowlana& operator=(const FirmaBudowlana&);
    void operator[](float);

    //OPERATORY STRUMIENIOWE
    friend ostream& operator << (ostream&, FirmaBudowlana&);
    friend istream& operator >> (istream&, FirmaBudowlana&);
};

#endif // FIRMABUDOWLANA_H
