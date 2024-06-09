#include "pracownik.h"
#include <fstream>
#include <limits>


Pracownik::Pracownik(string p_imie, string p_nazwisko, int p_wiek) : imie(p_imie), nazwisko(p_nazwisko), wiek(p_wiek) {
#ifdef _DEBUG
    cout << "Konstruktor Pracownik domyslny" << endl;
#endif
}
Pracownik::~Pracownik() {
#ifdef _DEBUG
    cout << "Destruktor Pracownik" << endl;
#endif
}

string Pracownik::wyswietlimie(){
    return imie;
}
string Pracownik::wyswietlnazwisko(){
    return nazwisko;
}
int Pracownik::wyswietlwiek(){
    return wiek;
}

Pracownik& Pracownik::operator = (const Pracownik &p){
    this->imie= p.imie;
    this->nazwisko = p.nazwisko;
    this->wiek = p.wiek;
    return *this;
}

ostream& operator <<(ostream &os, const Pracownik &p){
    os << p.imie << endl;
    os << p.nazwisko << endl;
    os << p.wiek<<endl;
    return os;
}

istream& operator >>(istream &is, Pracownik &p){
    getline(is, p.imie);
    getline(is, p.nazwisko);
    is >> p.wiek;
    is.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorujemy znak nowej linii po wieku
    return is;
}
