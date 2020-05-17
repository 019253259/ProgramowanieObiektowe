#include <string>

#ifndef tablica_h
#define tablica_h

struct Rekord {
  std::string tekst;
  int* kolumny = new int[100];
};

extern int rozmiar_tablicy;
extern Rekord* tablica;

void tablica_zmien_rozmiar (int nowy_rozmiar_tablicy);
void tablica_dodaj_element ();

#endif
