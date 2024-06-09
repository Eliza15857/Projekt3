#include "hydraulika.h"

Hydraulika::Hydraulika() {
    l_h++;
#ifdef _DEBUG
    cout << "Konstruktor domyslny Hydraulika" <<endl;
#endif
}
Hydraulika::Hydraulika(string r_r){
    rodzaj_rur = r_r;
#ifdef _DEBUG
    cout << "Konstruktor  Hydraulika" <<endl;
#endif
}
Hydraulika::~Hydraulika(){
    l_h--;
#ifdef _DEBUG
    cout << "Destruktor Hydraulika" <<endl;
#endif
}

void Hydraulika::setRodzajRur(string R_r) {rodzaj_rur = R_r;}

void Hydraulika::dodajPracownika(const Pracownik &p) {
    pracownik.push_back(p);
    l_pracownikow = pracownik.size();
}

void Hydraulika::dodajMHydrauliczny(const Materialy &m){
#ifdef _DEBUG
    cout<< l_mhydrauliczny;
#endif
    materialhydrauliczny.push_back(m);
    l_mhydrauliczny++;
}

void Hydraulika::ObliczFinanse(){
    int wynik;
    wynik = przychod - wydatki;
    if (wynik>0){
        cout<< "Dzial hydrauliki w tym roku zyskal: " << wynik << " tys" <<endl;
    }else cout << "Dzial hydrauliki w tym roku stracil: "<< wynik <<" tys"<<endl;
}

ostream& operator << (ostream& os, Hydraulika& H){
    os << "Hydraulika" <<endl;
    os << H.nazwa<<endl;
    os << H.przychod<<endl;
    os << H.wydatki<<endl;
    os << H.typ_budowy<<endl;
    os << H.rodzaj_rur<<endl;

    os << H.pracownik.size()<<endl;
    int x = H.pracownik.size();
    for(int i =0; i<x; i++){
        os<<H.pracownik[i].wyswietlimie()<<endl;
        os<<H.pracownik[i].wyswietlnazwisko()<<endl;
        os<<H.pracownik[i].wyswietlwiek()<<endl;}

    os << H.l_mhydrauliczny<<endl;
    for(int i = 0; i<H.l_mhydrauliczny;i++){
        os<< H.materialhydrauliczny[i].nazwaMaterialu()<<endl;
        os<< H.materialhydrauliczny[i].cenaMaterialu()<<endl;}


    return os;
}

istream& operator >> (istream& is, Hydraulika& H){
    is>> H.nazwa;
    is >> H.przychod;
    is >> H.wydatki;
    is >> H.typ_budowy;
    is >> H.rodzaj_rur;

    string p_imie, p_nazwisko, p_wiek;
    int l_p;
    is>>l_p;
    for(int i =0; i<l_p; i++){
        is>>p_imie;
        is>>p_nazwisko;
        is>>p_wiek;
        H.pracownik.push_back(Pracownik(p_imie, p_nazwisko, stoi(p_wiek)));
    }

    string p_nazwamhydrauliczny, p_cenamhydrauliczny;
    int l_mh;
    is>>l_mh;
    for(int i =0; i<l_mh; i++){
        is>>p_nazwamhydrauliczny;
        is>>p_cenamhydrauliczny;
        H.materialhydrauliczny.push_back(Materialy(p_nazwamhydrauliczny, stoi(p_cenamhydrauliczny)));
    }

    return is;
}


