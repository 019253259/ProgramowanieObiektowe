#include <iostream>
#include <fstream>
#include "tablica.h"
using namespace std;

int pocziloscWierszy=0;
int pocziloscKolumn=0;

int **Tablica = new int*[pocziloscWierszy];

void wczytaj_plik(int **tab, int pIloscWierszy, int pIloscKolumn)
{
	fstream plik;
	plik.open("tabela.txt", ios::in);

	if(plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}
	else
	{
		// wczytaj iloscWierszy
		int iloscWierszy = 0;
		plik >> iloscWierszy;

		// wczytaj iloscKolumn
		int iloscKolumn = 0;
		plik >> iloscKolumn;	

		// teraz trzeba ustawic rozmiar tablicy
		tablica_zmien_rozmiar(tab, pIloscWierszy, pIloscKolumn, iloscWierszy, iloscKolumn);

		for (int i = 0; i < iloscWierszy; i++) 
		{
			for(int j = 0; j < iloscKolumn; j++)
			{
				plik >> Tablica[i][j];
			}
		}	
	}
}

void zapisz_plik(int **tab, int iloscWierszy, int iloscKolumn)
{
    fstream plik("tabela.txt", ios::out);

	// pierwszy wiersz w pliku - iloscWierszy
	plik << iloscWierszy << endl;
	// drugi wiersz w pliku - iloscKolumn
	plik << iloscKolumn << endl;

	// kolejne wiersze - wiersze i kolumny
    if(plik.good())
    {
        for (int i = 0; i < iloscWierszy; i++) 
        {
			for(int j = 0; j < iloscKolumn; j++) 
			{
				// kazda wartosc w nowej linii - latwiej wczytac
				plik << Tablica[i][j] << endl;
			}
        }

		plik.flush();
        plik.close();
    }
}

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

void tablica_dodaj_element () 
{
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
