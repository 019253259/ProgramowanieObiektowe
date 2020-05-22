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
    cout << "6\t wyswietlenie najwiekszej wartosci tablicy" << endl;
    cout << "7\t wyswietlenie najmniejszej wartosci tablicy" << endl;
    cout << "8\t wyswietlenie sredniej z wartosci tablicy" << endl;
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
                tablica_dodaj_element(X);
                break;
            case 2: 
                tablica_wyswietl(X);
                break;           
            case 3:
                {
                    int iloscWie = 0;
                    int iloscKol = 0;
                    cout << "Podaj liczbe wierszy" << endl;
                    cin >> iloscWie;
                    cout << "Podaj liczbe kolumn" << endl;
                    cin >> iloscKol;
                    tablica_zmien_rozmiar(X, iloscWie, iloscKol);                    
                }
                break;
            case 4:
                wczytaj_plik(X);
                break;
            case 5:
                zapisz_plik(X);
                break; 
            case 6:
                max(X);
                break; 
	    case 7:
		min(X);
		break;  
	    case 8:
		srednia(X);
		break;                                    
        }

    } while (wybrana_opcja != 0);
}
