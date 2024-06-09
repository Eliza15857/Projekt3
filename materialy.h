#ifndef MATERIALY_H
#define MATERIALY_H
#include <string>
#include <iostream>
#define DEBUG_
using namespace std;

class Materialy
{
private:
    string nazwa_materialu;     //nazwa materialu sprzedawanego przez firme
    int cena_materialu;     //cena za m^2 materialu
public:
    Materialy(string nazwa= " ", int cena= 0);      //konstruktor sparametryzowany
    ~Materialy();

    void setMaterial(string, int);

    string nazwaMaterialu()const;        //zwraca nazwe materialu
    int cenaMaterialu()const;        //zwraca cene materialu

    friend ostream& operator <<(ostream &os, Materialy &m);
    friend istream& operator >>(istream &is, Materialy &m);


};

#endif // MATERIALY_H
