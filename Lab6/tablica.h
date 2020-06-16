#include <string>
using namespace std;

#ifndef tablica_h
#define tablica_h

//funkcja enum ulatwia czytanie programu
enum Typ {
   Liczba = 0,
   Tekst = 1
};

class Komorka {
   public:
      /**
      * @param [in] wartosc - zawartosc komorki jezeli Typ jest liczba
      * @param [in] tekst - zawartosc komorki jezeli Typ jest tekstem
      */
      int wartosc;
      string tekst;
      Typ typ = Liczba;

      void wyswietl();
};

class Tablica {
   private:
      /** 
      * @param [in] pocziloscWierszy - ilosc wierszy w tablicy
      * @param [in] pocziloscKolumn - ilosc kolumn w tablicy
      * @param [in,out] tab - tablica dwuwymiarowa
      */
      int pocziloscWierszy = 0;
      int pocziloscKolumn = 0;
      Komorka **tab = new Komorka*[pocziloscWierszy];

   public:
      void wyswietl();

		void wczytajPlik();

		void zapiszPlik();


		/**
		* @param [in] iloscWierszy - ilosc wierszy ktora chcemy ustawic
		* @param [in] iloscKolumn - ilosc kolumn ktora chcemy ustawic
		*/
		void zmienRozmiar(int iloscWierszy, int iloscKolumn);

		void dodajElement();

		int max();

		int min();

		float srednia();
};

#endif
