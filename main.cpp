#include <iostream>
#include "Kontener.h"
#include "firmabudowlana.h"
#include "firmatransportowa.h"
#include "hydraulika.h"

using namespace std;
template<typename T>
void menu(Kontener<T>& kontener) {
    char choice;
    T value;

    do {
        cout << "\n=== MENU ===\n"
                     "1. Dodaj element\n"
                     "2. Usun element\n"
                     "3. Wyswietl kontener\n"
                     "4. Zapisz do pliku\n"
                     "5. Wczytaj z pliku\n"
                     "6. Wyjscie\n"
                     "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Podaj wartosc do dodania: ";
            cin >> value;
            kontener.dodaj(value);
            break;
        case '2':
            cout << "Podaj wartosc do usuniecia: ";
            cin >> value;
            kontener.usun(value);
            break;
        case '3':
            cout << "Zawartosc kontenera:\n";
            kontener.wizualizuj();
            break;
        case '4':
            try {
                kontener.zapiszDoPliku("kontener.txt");
                cout << "Zapisano do pliku.\n";
            } catch (const exception& ex) {
                cerr << "Blad zapisu do pliku: " << ex.what() << std::endl;
            }
            break;
        case '5':
            try {
                kontener.wczytajZPliku("kontener.txt");
                cout << "Wczytano z pliku.\n";
            } catch (const exception& ex) {
                cerr << "Blad wczytywania z pliku: " << ex.what() << std::endl;
            }
            break;
        case '6':
            cout << "Zakonczono program.\n";
            break;
        default:
            cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        }
    } while (choice != '6');
}

int main() {
    // Testowanie dla typu int
    Kontener<int> kontenerInt;
    cout << "Testowanie dla typu int:\n";
    menu(kontenerInt);

    // Testowanie dla klasy Klasa
    Kontener<FirmaBudowlana> kontenerFirma;
    cout << "\nTestowanie dla klasy firma:\n";
    menu(kontenerFirma);

    return 0;
}
