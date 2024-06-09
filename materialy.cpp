#include "materialy.h"

Materialy::Materialy(string nazwa, int cena) : nazwa_materialu(nazwa), cena_materialu(cena) {
#ifdef _DEBUG
    cout << "Konstruktor Materialy" << endl;
#endif
}

Materialy::~Materialy(){
#ifdef _DEBUG
    cout << "Destruktor Materialy" << endl;
#endif
}

string Materialy::nazwaMaterialu() const{
    return nazwa_materialu;
};
int Materialy::cenaMaterialu() const{
    return cena_materialu;
};

void Materialy::setMaterial(string nazwa, int cena){
    nazwa_materialu = nazwa;
    cena_materialu = cena;
}

ostream& operator <<(ostream &os, Materialy &m){
    if(m.cena_materialu != 0){
        os << "Nazwa materialu: " << m.nazwa_materialu <<endl;
        os << "Cena materialu: " << m.cena_materialu << endl;
    }
    return os;
}

istream& operator >>(istream &is, Materialy &m){
    cout << "Podaj nazwe materialu: ";
    is >> m.nazwa_materialu;
    cout << "Podaj cene materialu: ";
    is >> m.cena_materialu;
    return is;
}
