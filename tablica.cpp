#include <iostream>
#include <string>
#include "tablica.h"

using namespace std;

int rozmiar_tablicy = 0;
Rekord* tablica = new Rekord[rozmiar_tablicy];

void tablica_zmien_rozmiar (int nowy_rozmiar_tablicy) {

    Rekord* nowa_tablica = new Rekord[nowy_rozmiar_tablicy];

    // kopiowanie zawartosci poprzedniej tablicy do nowej
    for (int i = 0; i < rozmiar_tablicy; i++) {
        nowa_tablica[i] = tablica[i];
    }

    // usuniecie starej tablicy
    delete [] tablica;
    rozmiar_tablicy = nowy_rozmiar_tablicy;
    tablica = nowa_tablica;
}

void tablica_dodaj_element () {

    int numer_wiersza = 0;
    cout << "Podaj nr wiersza: " <<endl;
    cin >> numer_wiersza;

    int numer_kolumny = 0;
    cout << "Podaj nr kolumny: " <<endl;
    cin >> numer_kolumny;

    int wartosc= 0;
    cout << "Podaj wartosc do wpisania: " <<endl;
    cin >> wartosc;
	
    tablica[numer_wiersza - 1].kolumny[numer_kolumny - 1] = wartosc;

   /* tablica_zmien_rozmiar(rozmiar_tablicy + 1);

    cout << "Wpisz tekst do dodania:" << endl;
    Rekord nowy_rekord; 
    getline(cin, nowy_rekord.tekst);
    cout << endl;

    tablica[rozmiar_tablicy - 1] = nowy_rekord;*/
    

}
