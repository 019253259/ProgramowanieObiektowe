#include <string>

#ifndef tablica_h
#define tablica_h

struct Tabela 
{
   /*
   * @param[in] pocziloscWierszy - ilosc Wierszy
   * @param[in] pocziloscKolumn - ilosc Kolumn
   * @param[in,out] **tablica - tablica wielowymiarowa
   */
   int pocziloscWierszy = 0;
   int pocziloscKolumn = 0;
   int **tablica = new int*[pocziloscWierszy];
};

extern Tabela X;

void wczytaj_plik(Tabela tabelka);
void zapisz_plik(Tabela tabelka);
void tablica_zmien_rozmiar (Tabela tabelka, int iloscWierszy, int iloscKolumn);
void tablica_dodaj_element (Tabela tabelka);
int max(Tabela tabelka);
int min(Tabela tabelka);
float srednia(Tabela tabelka); 

#endif
