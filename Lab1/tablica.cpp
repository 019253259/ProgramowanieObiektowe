#include <iostream>
#include "tablica.h"

using namespace std;

int pocziloscWierszy=0;
int pocziloscKolumn=0;

int **Tablica = new int*[pocziloscWierszy];

void tablica_zmien_rozmiar (int **tab, int pIloscWierszy, int pIloscKolumn, int iloscWierszy, int iloscKolumn)
{
	//rezerwacja pamieci
	int** tabl = new int*[iloscWierszy];

	for(int i=0; i<iloscWierszy; i++)
	{
		tabl[i] = new int[iloscKolumn];
	}

	// kopiowanie zawartosci poprzedniej tablicy do nowej
	for (int i = 0; i < iloscWierszy; i++) 
	{
		for(int j = 0; j < iloscKolumn; j++)
		{
			if( (j < pIloscKolumn) && (i < pIloscWierszy) )
			{
				tabl[i][j] = Tablica[i][j];
			}
			else
			{
				tabl[i][j] = 0;
			}
		}
	}

	// usuniecie starej tablicy
	delete *Tablica;
	pocziloscWierszy = iloscWierszy;
	pocziloscKolumn = iloscKolumn;
	Tablica = tabl;
}

void tablica_dodaj_element () {

    int numer_wiersza = 0;
    cout << "Podaj nr wiersza: " <<endl;
    cin >> numer_wiersza;

    int numer_kolumny = 0;
    cout << "Podaj nr kolumny: " <<endl;
    cin >> numer_kolumny;

    int wartosc= 0;
    cout << "Podaj wartosc do wpisania: " <<endl;
    cin >> wartosc;
	
    Tablica[numer_wiersza - 1][numer_kolumny - 1] = wartosc;
}
