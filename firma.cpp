#include "firma.h"

int Firma::l_firm = 0;

Firma::Firma() {
    l_firm++;
#ifdef _DEBUG
    cout << "Konstruktor domyslny Firma" << endl;
#endif
}
Firma::Firma(const Firma &F) {
#ifdef _DEBUG
    cout << "Konstruktor Firma" << endl;
#endif
    nazwa = F.nazwa;
    przychod = F.przychod;
    wydatki = F.wydatki;
    l_pracownikow = F.l_pracownikow;
    pracownik = F.pracownik;
}
Firma::~Firma(){
    l_firm--;
#ifdef _DEBUG
    cout << "Destruktor Firma " << endl;
#endif
}

void Firma::dodajPracownika(const Pracownik &p){
    pracownik.push_back(p);
    l_pracownikow = pracownik.size();
}

void Firma::setDane(string p_nazwa, float p_przychod, float p_wydatki){
    nazwa = p_nazwa;
    przychod = p_przychod;
    wydatki = p_wydatki;
}
void Firma::setNazwa(string p_nazwa){nazwa=p_nazwa;}

void Firma::setFinanse(float p_przychod, float p_wydatki){
    przychod = p_przychod;
    wydatki = p_wydatki;
}

string Firma::getNazwa() {return nazwa;}
float Firma::getPrzychod() {return przychod;}
float Firma::getWydatki() {return wydatki;}

void Firma::ObliczFinanse(){
    int wynik;
    wynik = przychod - wydatki;
    if (wynik>0){
        cout<< "Firma w tym roku zyskala: " << wynik << " tys" <<endl;
    }else cout << "Firma w tym roku stracila: "<< wynik <<" tys"<<endl;
}

bool Firma::operator<(const Firma &other) const {
    return (this->przychod - this->wydatki) < (other.przychod - other.wydatki);
}

bool Firma::operator>(const Firma &other) const {
    return (this->przychod - this->wydatki) > (other.przychod - other.wydatki);
}

bool Firma::operator<=(const Firma &other) const {
    return (this->przychod - this->wydatki) <= (other.przychod - other.wydatki);
}

bool Firma::operator>=(const Firma &other) const {
    return (this->przychod - this->wydatki) >= (other.przychod - other.wydatki);
}

bool Firma::operator==(const Firma &other) const {
    return (this->przychod - this->wydatki) == (other.przychod - other.wydatki);
}

bool Firma::operator!=(const Firma &other) const {
    return !(*this == other);
}

ostream& operator<<(ostream &os, Firma &F){
    os << "Firma" <<endl;
    os << F.nazwa << endl;
    os << F.przychod <<endl;
    os<< F.wydatki <<endl;

    os << F.l_pracownikow<< endl;
    for(int i = 0; i < F.l_pracownikow; i++){
        os << F.pracownik[i]<<endl;
    }
    return os;
}

istream& operator >> (istream &is, Firma &F){
    is >> F.nazwa;
    is >> F.przychod;
    is >> F.wydatki;

    string p_imie, p_nazwisko, p_wiek;
    int l_p;
    is>>l_p;
    for(int i =0; i<l_p; i++){
        is>>p_imie;
        is>>p_nazwisko;
        is>>p_wiek;
        F.pracownik.push_back(Pracownik(p_imie, p_nazwisko, stoi(p_wiek)));
    }
    return is;
}
