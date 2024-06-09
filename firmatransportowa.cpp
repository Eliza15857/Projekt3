#include "firmatransportowa.h"

int FirmaTransportowa::l_ftransp = 0;

FirmaTransportowa::FirmaTransportowa() {
    l_ftransp++;
}
FirmaTransportowa::FirmaTransportowa(const FirmaTransportowa &FT){
#ifdef _DEBUG
    cout << "Konstruktor Firma Transportowa" << endl;
#endif
    nazwa = FT.nazwa;
    przychod = FT.przychod;
    wydatki = FT.wydatki;
    liczba_pojazdow = FT.liczba_pojazdow;
    pracownik = FT.pracownik;
    if(FT.pracownik.empty() == false){
        for(int i=0; i< FT.l_pracownikow; i++)
            pracownik.push_back(pracownik[i]);
    }
}
FirmaTransportowa::~FirmaTransportowa(){
    l_ftransp--;
#ifdef _DEBUG
    cout << "Destruktor Firma Transportowa " << " Liczba firm transportowych: " << l_ftransp << endl;
#endif
}

void FirmaTransportowa::dodajPracownika(const Pracownik &p){
    pracownik.push_back(p);
    l_pracownikow = pracownik.size();
}

void FirmaTransportowa::setDane(string n, float p, float w, int lp){
    nazwa = n;
    przychod = p;
    wydatki = w;
    liczba_pojazdow = lp;
}
void FirmaTransportowa::setLPojazdow(int lp){liczba_pojazdow = lp;}
string FirmaTransportowa::getNazwa(){
    return nazwa;
}
float FirmaTransportowa::getPrzychod(){
    return przychod;
}
float FirmaTransportowa::getWydatki(){
    return wydatki;
}
int FirmaTransportowa::getLiczbaPojazdow(){
    return liczba_pojazdow;
}

void FirmaTransportowa::ObliczFinanse(){
    int wynik;
    wynik = przychod - wydatki;
    if (wynik>0){
        cout<< "Firma Transportowa w tym roku zyskala: " << wynik << " tys" <<endl;
    }else cout << "Firma Transportowa w tym roku stracila: "<< wynik <<" tys"<<endl;
}

ostream& operator << (ostream &os, FirmaTransportowa &FT){
    os << "Firma Transportowa" <<endl;
    os << FT.nazwa<<endl;
    os << FT.przychod<<endl;
    os << FT.wydatki<<endl;
    os << FT.liczba_pojazdow<<endl;

    os << FT.l_pracownikow<<endl;
    for(int i =0; i<FT.l_pracownikow; i++){
        os<<FT.pracownik[i].wyswietlimie()<<endl;
        os<<FT.pracownik[i].wyswietlnazwisko()<<endl;
        os<<FT.pracownik[i].wyswietlwiek()<<endl;}

    return os;
}

istream& operator >> (istream &is, FirmaTransportowa& FT){
    is>> FT.nazwa;
    is >> FT.przychod;
    is >> FT.wydatki;
    is >> FT.liczba_pojazdow;

    string p_imie, p_nazwisko, p_wiek;
    int l_p;
    is>>l_p;
    for(int i =0; i<l_p; i++){
        is>>p_imie;
        is>>p_nazwisko;
        is>>p_wiek;
        FT.pracownik.push_back(Pracownik(p_imie, p_nazwisko, stoi(p_wiek)));
    }

    return is;
}

