#include <iostream>
#include <string>
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;

void tablica_wyswietl () {
  cout << "Zawartosc tablicy:" << endl;

  for (int i = 0; i < pocziloscWierszy; i++) {
      for (int j = 0; j < pocziloscKolumn; j++){
          cout << Tablica[i][j] << " ";
      }
      cout << endl;
  }

  cout << endl;
}
