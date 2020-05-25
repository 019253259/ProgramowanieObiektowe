#include <iostream>
#include <fstream>
#include "tablica.h"
using namespace std;

class Komurka {
	public:
	   int wartosc;
};

Komurka komurka;

void Tablica::wczytajPlik()
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
		zmienRozmiar(iloscWierszy, iloscKolumn);

		for (int i = 0; i < iloscWierszy; i++) 
		{
			for(int j = 0; j < iloscKolumn; j++)
			{
				plik >> tab[i][j].wartosc;
			}
		}	
	}
}

void Tablica::zapiszPlik()
{
	fstream plik("tabela.txt", ios::out);

	// pierwszy wiersz w pliku - iloscWierszy
	plik << pocziloscWierszy << endl;
	// drugi wiersz w pliku - iloscKolumn
	plik << pocziloscKolumn << endl;

	// kolejne wiersze - wiersze i kolumny
	if(plik.good())
	{
		for (int i = 0; i < pocziloscWierszy; i++) 
		{
			for(int j = 0; j < pocziloscKolumn; j++) 
			{
				// kazda wartosc w nowej linii - latwiej wczytac
				plik << tab[i][j].wartosc << endl;
			}
		}

		plik.flush();
		plik.close();
	}
}

void Tablica::zmienRozmiar(int iloscWierszy, int iloscKolumn)
{
	//rezerwacja pamieci
	int** nowaTab = new int*[iloscWierszy];

	for(int i=0; i<iloscWierszy; i++)
	{
		nowaTab[i] = new int[iloscKolumn];
	}

	// kopiowanie zawartosci poprzedniej nowaTabicy do nowej
	for (int i = 0; i < iloscWierszy; i++) 
	{
		for(int j = 0; j < iloscKolumn; j++)
		{
			if( (j < pocziloscKolumn) && (i < pocziloscWierszy) )
			{
				nowaTab[i][j] = tab[i][j].wartosc;
			}
			else
			{
				nowaTab[i][j] = 0;
			}
		}
	}

	// usuniecie starej tablicy
	delete * [];

	pocziloscWierszy = iloscWierszy;
	pocziloscKolumn = iloscKolumn;
	tab.wartosc = nowaTab;
}

void Tablica::dodajElement() 
{
	int numer_wiersza = 0;
	cout << "Podaj nr wiersza: " <<endl;
	cin >> numer_wiersza;

	int numer_kolumny = 0;
	cout << "Podaj nr kolumny: " <<endl;
	cin >> numer_kolumny;

	int wart= 0;
	cout << "Podaj wartosc do wpisania: " <<endl;
	cin >> wart;
	
	tab[numer_wiersza - 1][numer_kolumny - 1] = wart;
}

int Tablica::max()
{
	int max = tab[0][0].wartosc;
	for(int i=0; i<pocziloscWierszy; i++)
	{
		for(int j=0; j<pocziloscKolumn; j++)
		{
			int war = tab[i][j].wartosc;
			if(war > max)
				max = war;
		}
	}

	return max;
} 

int Tablica::min()
{
        int min = tab[0][0].wartosc;
        for(int i=0; i<pocziloscWierszy; i++)
	{
		for(int j=0; j<pocziloscKolumn; j++)
		{
			int war = tab[i][j].wartosc;
			if(war < min)
				min = war;
		}
	}

	return min;
}

float Tablica::srednia()
{
        float suma = 0;
        for(int i=0; i<pocziloscWierszy; i++)
	{
		for(int j=0; j<pocziloscKolumn; j++)
		{
			suma += tab[i][j].wartosc;
		}
	}
	float ilosc = pocziloscWierszy * pocziloscKolumn;
	float srednia =suma/ilosc;
	return srednia;
}
