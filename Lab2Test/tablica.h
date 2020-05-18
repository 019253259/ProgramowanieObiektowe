#include <string>

#ifndef tablica_h
#define tablica_h

extern int pocziloscWierszy;
extern int pocziloscKolumn;
extern int **Tablica;

void zapiszPlik()
void wczytPlik();
void tablica_zmien_rozmiar (int **tab, int pIloscWierszy, int pIloscKolumn, int iloscWierszy, int iloscKolumn);
void tablica_dodaj_element ();

#endif
