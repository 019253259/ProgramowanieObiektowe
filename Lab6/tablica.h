#include <string>
using namespace std;

#ifndef tablica_h
#define tablica_h

enum Typ {
   Liczba = 0,
   Tekst = 1
};

class Komorka {
   public:
      int wartosc;
      string tekst;
      Typ typ = Liczba;

      void wyswietl();
};

class Tablica {
   private:
      int pocziloscWierszy = 0;
      int pocziloscKolumn = 0;
      Komorka **tab = new Komorka*[pocziloscWierszy];

   public:
      void wyswietl();

		void wczytajPlik();

		void zapiszPlik();

		void zmienRozmiar(int iloscWierszy, int iloscKolumn);

		void dodajElement();

		int max();

		int min();

		float srednia();
};

#endif
