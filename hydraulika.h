#ifndef HYDRAULIKA_H
#define HYDRAULIKA_H
#include "firmabudowlana.h"
#define DEBUG_

class Hydraulika : public FirmaBudowlana
{
private:
    string rodzaj_rur;
    int l_h;
protected:
    int l_mhydrauliczny;
    vector <Materialy> materialhydrauliczny;
public:
    Hydraulika();
    Hydraulika(string);
    ~Hydraulika();

    virtual void dodajPracownika(const Pracownik&);
    void dodajMHydrauliczny(const Materialy&);
    void setRodzajRur(string);

    virtual void ObliczFinanse();

    friend ostream& operator << (ostream&, Hydraulika&);
    friend istream& operator >> (istream&, Hydraulika&);
};

#endif // HYDRAULIKA_H
