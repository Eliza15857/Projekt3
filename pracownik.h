#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include <string>
#include <iostream>
#define DEBUG_
using namespace std;

class Pracownik
{
private:
    string imie;
    string nazwisko;
    int wiek;
public:
    Pracownik(string p_imie = " ", string p_nazwisko = " ", int p_wiek = 0);
    ~Pracownik();

    string wyswietlimie();
    string wyswietlnazwisko();
    int wyswietlwiek();

    Pracownik& operator = (const Pracownik&);
    friend ostream& operator <<(ostream &, const Pracownik &);
    friend istream& operator >>(istream &, Pracownik &);
};

#endif // PRACOWNIK_H
