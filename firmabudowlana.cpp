#include "firmabudowlana.h"

int FirmaBudowlana::l_fbud =0;

//KONSTRUKTORY i DESTRUKTOR
FirmaBudowlana::FirmaBudowlana(string p_nazwa, float p_przychod, int p_wydatki){
    nazwa = p_nazwa;
    przychod = p_przychod;
    wydatki = p_wydatki;
    l_fbud++;
#ifdef _DEBUG
    cout << "Konstruktor FirmaBudowlana domyslny" << endl;
#endif
}

FirmaBudowlana::FirmaBudowlana(const FirmaBudowlana &FB){
    nazwa = FB.nazwa;
    przychod = FB.przychod;
    wydatki = FB.wydatki;
    typ_budowy =FB.typ_budowy;
    l_pracownikow = FB.l_pracownikow;

    if(FB.pracownik.empty() == false){
        pracownik = FB.pracownik;
    }
    if(FB.materialy.empty() == false){
        materialy = FB.materialy;
    }

    l_fbud++;
#ifdef _DEBUG
    cout << "Konstruktor kopiujacy FirmaBudowlana" << endl;
#endif
}

FirmaBudowlana::~FirmaBudowlana(){
    l_fbud--;
#ifdef _DEBUG
    cout << "Destruktor FirmaBudowlana" <<  "Liczba firm: "<< l_fbud<< endl;
#endif
}

//DODAWANIE DO VECTORA

void FirmaBudowlana::dodajPracownika(const Pracownik &p) {
    pracownik.push_back(p);
    l_pracownikow = pracownik.size();
}

void FirmaBudowlana::dodajMaterial(const Materialy &m){
#ifdef _DEBUG
    cout<< l_materialow;
#endif
    materialy.push_back(m);
    l_materialow++;
}

//USTALANIE DANYCH

void FirmaBudowlana::setDane(string p_nazwa, float p_przychod, float p_wydatki, string p_typ_budowy){
    nazwa=p_nazwa;
    przychod = p_przychod;
    wydatki = p_wydatki;
    typ_budowy = p_typ_budowy;
}
void FirmaBudowlana::setBudowe(string t_b){typ_budowy =t_b;}

string FirmaBudowlana::getNazwa() {return nazwa;}
float FirmaBudowlana::getPrzychod(){return przychod;}
float FirmaBudowlana::getWydatki(){return wydatki;}
string FirmaBudowlana::getTypbudowy(){return typ_budowy;}

void FirmaBudowlana::ObliczFinanse(){
    int wynik;
    wynik = przychod - wydatki;
    if (wynik>0){
        cout<< "Firma budowlana w tym roku zyskala: " << wynik << " tys" <<endl;
    }else cout << "Firma budowlana w tym roku stracila: "<< wynik <<" tys"<<endl;
}

//OPERATORY

double FirmaBudowlana::operator-(){                  // OPERATOR JEDNOARGUMENTOWY
    double wynik;
    wynik = przychod - wydatki;
    if(wynik>0)
        cout << "Zysk firmy " << nazwa << " wynosi: " << wynik << " tys" <<endl;
    else
        cout << "Firma "<< nazwa  <<" poniosla straty o wartosci: " << wynik << " tys" << endl;
    return wynik;
}

FirmaBudowlana& FirmaBudowlana::operator=(const FirmaBudowlana &other){              //OPERATOR PRZYPISANIA
    if(this == &other)
        return *this;

    nazwa = other.nazwa;
    przychod = other.przychod;
    wydatki = other.wydatki;
    l_pracownikow = other.l_pracownikow;
    materialy = other.materialy;
    pracownik = other.pracownik;

    return *this;
}

void FirmaBudowlana::operator[](float nowyprzychod){
    this->przychod = nowyprzychod;}


ostream& operator << (ostream &os, FirmaBudowlana &FB){
    os << "Firma Budowlana" <<endl;
    os << FB.nazwa<<endl;
    os << FB.przychod<<endl;
    os << FB.wydatki<<endl;
    os << FB.typ_budowy<<endl;

    os << FB.l_pracownikow << endl;
    for(int i =0; i<FB.l_pracownikow; i++){
        os<<FB.pracownik[i].wyswietlimie()<<endl;
        os<<FB.pracownik[i].wyswietlnazwisko()<<endl;
        os<<FB.pracownik[i].wyswietlwiek()<<endl;}

    os << FB.l_materialow << endl;
    for(int i = 0; i< FB.l_materialow;i++){
        os<< FB.materialy[i].nazwaMaterialu()<<endl;
        os<< FB.materialy[i].cenaMaterialu()<<endl;}

    return os;
}
istream& operator >> (istream &is, FirmaBudowlana& FB){
    is >> FB.nazwa;
    is >> FB.przychod;
    is >> FB.wydatki;
    is >> FB.typ_budowy;

    string p_imie, p_nazwisko, p_wiek;
    int l_p;
    is>>l_p;
    for(int i =0; i<l_p; i++){
        is>>p_imie;
        is>>p_nazwisko;
        is>>p_wiek;
        FB.pracownik.push_back(Pracownik(p_imie, p_nazwisko, stoi(p_wiek)));
    }

    string p_nazwamaterialu, p_cenamaterialu;
    int l_m;
    is>>l_m;
    for(int i =0; i<l_m; i++){
        is>>p_nazwamaterialu;
        is>>p_cenamaterialu;
        FB.materialy.push_back(Materialy(p_nazwamaterialu, stoi(p_cenamaterialu)));
    }
    return is;
}


