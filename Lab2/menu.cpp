#include <iostream>
#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;

void menu_opcje() {
    cout << "Co chcesz zrobic?" << endl;
    cout << "1\t dodaj element" << endl;
    cout << "2\t wyswietl tablice" << endl;
    cout << "3\t ustaw liczbe wierszy i kolumn" << endl;
    cout << "4\t wczytaj plik" << endl;
    cout << "5\t zapisz plik" << endl;
    cout << "0\t zakoncz program" << endl;
}

void menu_wyswietl() {
    int wybrana_opcja;

    do {
        menu_opcje();
        cin >> wybrana_opcja;
        cin.ignore();
        cout << endl;

        switch (wybrana_opcja) {
            case 1: 
                tablica_dodaj_element();
                break;
            case 2: 
                tablica_wyswietl();
                break;           
            case 3:
                {
                    int iloscWie = 0;
                    int iloscKol = 0;
                    cout << "Podaj liczbe wierszy" << endl;
                    cin >> iloscWie;
                    cout << "Podaj liczbe kolumn" << endl;
                    cin >> iloscKol;
                    tablica_zmien_rozmiar(Tablica, pocziloscWierszy, pocziloscKolumn, iloscWie, iloscKol);                    
                }
                break;
            case 4:
                wczytaj_plik(Tablica, pocziloscWierszy, pocziloscKolumn);
                break;
            case 5:
                zapisz_plik(Tablica, pocziloscWierszy, pocziloscKolumn);
                break;                     
        }

    } while (wybrana_opcja != 0);
}
