#include <iostream>
#include <fstream>
#include "tablica.h"
using namespace std;

void Komorka::wyswietl() 
{
	switch (typ)
	{
		case Liczba:
			cout << wartosc;
			break;
		case Tekst:
			cout << tekst;
			break;
	}
}

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
				int typ;
				plik >> typ;

				if (typ = (int)Typ::Liczba) 
				{
					plik >> tab[i][j].wartosc;
					tab[i][j].typ = Liczba;
				}
				else
				{
					plik >> tab[i][j].tekst;
					tab[i][j].typ = Tekst;
				}				
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
				// najpierw zapisz typ komorki
				plik << (int)tab[i][j].typ << endl;

				// kazda wartosc w nowej linii - latwiej wczytac
				switch(tab[i][j].typ) {
					case Liczba:
						plik << tab[i][j].wartosc << endl;
						break;
					case Tekst:
						plik << tab[i][j].tekst << endl;
						break;
				}
			}
		}

		plik.flush(); //zapisanie całej obecnej zawartości bufora na dysk bez względu na to czy jest on zapełniony czy nie
		plik.close();
	}
}

void Tablica::zmienRozmiar(int iloscWierszy, int iloscKolumn)
{
	//rezerwacja pamieci
	Komorka** nowaTab = new Komorka*[iloscWierszy];

	for(int i=0; i<iloscWierszy; i++)
	{
		nowaTab[i] = new Komorka[iloscKolumn];
	}

	// kopiowanie zawartosci poprzedniej nowaTabicy do nowej
	for (int i = 0; i < iloscWierszy; i++) 
	{
		for(int j = 0; j < iloscKolumn; j++)
		{
			if( (j < pocziloscKolumn) && (i < pocziloscWierszy) )
			{
				nowaTab[i][j] = tab[i][j];
			}
		}
	}

	// usuniecie starej tablicy
	for(int i=0; i<pocziloscWierszy; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;

	pocziloscWierszy = iloscWierszy;
	pocziloscKolumn = iloscKolumn;
	tab = nowaTab;
}

void Tablica::dodajElement() 
{
	int numer_wiersza = 0;
	cout << "Podaj nr wiersza: " <<endl;
	cin >> numer_wiersza;

	int numer_kolumny = 0;
	cout << "Podaj nr kolumny: " <<endl;
	cin >> numer_kolumny;

	char typ;
	cout << "Ustaw typ komorki (l - liczba, t - tekst): " <<endl;
	cin >> typ;

	if (typ == 't') 
	{
		string tekst;
		cout << "Podaj tekst do wpisania: " <<endl;
		cin >> tekst;
		
		tab[numer_wiersza - 1][numer_kolumny - 1].tekst = tekst;
		tab[numer_wiersza - 1][numer_kolumny - 1].typ = Tekst;
	} 
	else 
	{
		int wartosc = 0;
		cout << "Podaj wartosc do wpisania: " <<endl;
		cin >> wartosc;
		
		tab[numer_wiersza - 1][numer_kolumny - 1].wartosc = wartosc;
		tab[numer_wiersza - 1][numer_kolumny - 1].typ = Liczba;
	}
}

int Tablica::max()
{
	int max = tab[0][0].wartosc;
	for(int i=0; i<pocziloscWierszy; i++)
	{
		for(int j=0; j<pocziloscKolumn; j++)
		{
			int wartosc = tab[i][j].wartosc;
			if(wartosc > max)
				max = wartosc;
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
			int wartosc = tab[i][j].wartosc;
			if(wartosc < min)
				min = wartosc;
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
