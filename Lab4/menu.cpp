#include <iostream>
#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;

Tablica tablica;

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
                tablica.dodajElement();
                break;
            case 2: 
                tablica.wyswietl();
                break;           
            case 3:
                {
                    int iloscWie = 0;
                    int iloscKol = 0;
                    cout << "Podaj liczbe wierszy" << endl;
                    cin >> iloscWie;
                    cout << "Podaj liczbe kolumn" << endl;
                    cin >> iloscKol;
                    tablica.zmienRozmiar(iloscWie, iloscKol);                    
                }
                break;
            case 4:
                tablica.wczytajPlik();
                break;
            case 5:
                tablica.zapiszPlik();
                break; 
            case 6:
		{
                int max = tablica.max();
                cout << "Max: " << max << endl;
                break; 
		}  
	    case 7:
		{
		int min = tablica.min();
		cout << "Min: " << min << endl;
		break;
		}    
	    case 8:
		{
		float srednia = tablica.srednia();
		cout << "Srednia: " << srednia << endl;
		break;
		}                                
        }
    } while (wybrana_opcja != 0);
}
