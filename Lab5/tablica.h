#include <string>

#ifndef tablica_h
#define tablica_h

Komurka komurka;

class Tablica {
   private:
      /*
      * @param[in] pocziloscWierszy - ilosc Wierszy
      * @param[in] pocziloscKolumn - ilosc Kolumn
      * @param[in,out] **tablica - tablica wielowymiarowa
      */
      int pocziloscWierszy = 0;
      int pocziloscKolumn = 0;
      komurka **tab = new komurka*[pocziloscWierszy];

   public:
      
      void wyswietl();

		void wczytajPlik();

		void zapiszPlik();
		
		/* 
		* @param[in] iloscWierszy - koncowa ilosc wierszy
		* @param[in] iloscKolumn - koncowa ilosc kolumn
		*/
		void zmienRozmiar(int iloscWierszy, int iloscKolumn);

		void dodajElement();

		int max();

		int min();
		
		float srednia();
};




#endif
