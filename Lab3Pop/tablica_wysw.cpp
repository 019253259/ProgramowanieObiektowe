#include <iostream>
#include <string>
#include "tablica.h"
#include "tablica_wysw.h"

using namespace std;
void tablica_wyswietl(Tabela tabelka) {
  cout << "Zawartosc tablicy:" << endl;

  for (int i = 0; i < tabelka.pocziloscWierszy; i++) {
      for (int j = 0; j < tabelka.pocziloscKolumn; j++){
          cout << tabelka.tablica[i][j] << " ";
      }
      cout << endl;
  }

  cout << endl;
}
