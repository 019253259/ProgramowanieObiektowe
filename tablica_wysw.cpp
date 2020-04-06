#include <iostream>
using namespace std;

void tablica_wyswietl () {
  cout << "Zawartosc tablicy:" << endl;

  for (int i = 0; i < rozmiar_tablicy; i++) {
      cout << tablica[i].tekst << endl;
  }

  cout << endl;
}

