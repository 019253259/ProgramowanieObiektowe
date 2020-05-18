#include <string>

#ifndef tablica_h
#define tablica_h

extern int **Tablica;

struct Tabela 
{
   int pocziloscWierszy = 0;
   int pocziloscKolumn = 0;
   int **tablica = new int*[pocziloscWierszy];
};

void wczytaj_plik(int **tab, int pIloscWierszy, int pIloscKolumn);
void zapisz_plik(int **tab, int iloscWierszy, int iloscKolumn);
void tablica_zmien_rozmiar (int **tab, int pIloscWierszy, int pIloscKolumn, int iloscWierszy, int iloscKolumn);
void tablica_dodaj_element ();

#endif
