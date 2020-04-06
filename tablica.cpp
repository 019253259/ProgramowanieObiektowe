#include <iostream>
using namespace std;

struct Rekord {
  string tekst;
};

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

    tablica_zmien_rozmiar(rozmiar_tablicy + 1);

    cout << "Wpisz tekst do dodania:" << endl;
    Rekord nowy_rekord;
    getline(cin, nowy_rekord.tekst);
    cout << endl;

    tablica[rozmiar_tablicy - 1] = nowy_rekord;
}
