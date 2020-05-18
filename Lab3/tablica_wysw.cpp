#include <iostream>
#include <string>
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;
Tabela Tabelka;
void tablica_wyswietl () {
  cout << "Zawartosc tablicy:" << endl;

  for (int i = 0; i < Tabelka.pocziloscWierszy; i++) {
      for (int j = 0; j < Tabelka.pocziloscKolumn; j++){
          cout << Tablica[i][j] << " ";
      }
      cout << endl;
  }

  cout << endl;
}
