#include <string>

#ifndef tablica_h
#define tablica_h

struct Tabela 
{
   int pocziloscWierszy = 0;
   int pocziloscKolumn = 0;
   int **tablica = new int*[pocziloscWierszy];
};

extern Tabela X;

void wczytaj_plik(Tabela tabelka);
void zapisz_plik(Tabela tabelka);
void tablica_zmien_rozmiar (Tabela tabelka, int iloscWierszy, int iloscKolumn);
void tablica_dodaj_element (Tabela tabelka);
void max(Tabela tabelka);
void min(Tabela tabelka);
void srednia(Tabela tabelka);

#endif
