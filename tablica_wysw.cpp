#include <iostream>
#include <string>
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;

void tablica_wyswietl () {
  cout << "Zawartosc tablicy:" << endl;

  for (int i = 0; i < rozmiar_tablicy; i++) {
      for (int j = 0; j < 10; j++){
          cout << tablica[i].kolumny[j] << " ";
      }
      cout << endl;
  }

  cout << endl;
}
