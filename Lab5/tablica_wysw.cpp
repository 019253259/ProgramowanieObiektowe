#include <iostream>
#include <string>
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;

void Tablica::wyswietl () {
  cout << "Zawartosc tablicy:" << endl;

  for (int i = 0; i < pocziloscWierszy; i++) {
      for (int j = 0; j < pocziloscKolumn; j++){
          cout << tab[i][j].wartosc << " ";
      }
      cout << endl;
  }

  cout << endl;
}
