#include <iostream>
#include <fstream>
#include "tablica.h"
using namespace std;

Tabela X;

void wczytaj_plik(Tabela tabelka)
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
		tablica_zmien_rozmiar(tabelka, iloscWierszy, iloscKolumn);

		for (int i = 0; i < iloscWierszy; i++) 
		{
			for(int j = 0; j < iloscKolumn; j++)
			{
				plik >> tabelka.tablica[i][j];
			}
		}	
	}
}

void zapisz_plik(Tabela tabelka)
{
    fstream plik("tabela.txt", ios::out);

	// pierwszy wiersz w pliku - iloscWierszy
	plik << tabelka.pocziloscWierszy << endl;
	// drugi wiersz w pliku - iloscKolumn
	plik << tabelka.pocziloscKolumn << endl;

	// kolejne wiersze - wiersze i kolumny
    if(plik.good())
    {
        for (int i = 0; i < tabelka.pocziloscWierszy; i++) 
        {
			for(int j = 0; j < tabelka.pocziloscKolumn; j++) 
			{
				// kazda wartosc w nowej linii - latwiej wczytac
				plik << tabelka.tablica[i][j] << endl;
			}
        }

		plik.flush();//zapisanie całej obecnej zawartości bufora na dysk bez względu na to czy jest on zapełniony czy nie
        plik.close();
    }
}

void tablica_zmien_rozmiar (Tabela tabelka, int iloscWierszy, int iloscKolumn)
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
			if( (j < tabelka.pocziloscKolumn) && (i < tabelka.pocziloscWierszy) )
			{
				tabl[i][j] = tabelka.tablica[i][j];
			}
			else
			{
				tabl[i][j] = 0;
			}
		}
	}

	// usuniecie starej tablicy
	delete *tabelka.tablica;

	tabelka.pocziloscWierszy = iloscWierszy;
	tabelka.pocziloscKolumn = iloscKolumn;
	tabelka.tablica = tabl;

	X = tabelka;
}

void tablica_dodaj_element (Tabela tabelka) 
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
	
    tabelka.tablica[numer_wiersza - 1][numer_kolumny - 1] = wartosc;
}

void max(Tabela tabelka)
{
    int max = tabelka.tablica[0][0];
    for(int i=0; i<tabelka.pocziloscWierszy; i++)
	{
		for(int j=0; j<tabelka.pocziloscKolumn; j++)
		{
			int wartosc = tabelka.tablica[i][j];
			if(wartosc > max)
				max = wartosc;
		}
	}

	cout << max;
}

void min(Tabela tabelka)
{
        int min = tabelka.tablica[0][0];
        for(int i=0; i<tabelka.pocziloscWierszy; i++)
	{
		for(int j=0; j<tabelka.pocziloscKolumn; j++)
		{
			int wartosc = tabelka.tablica[i][j];
			if(wartosc < min)
				min = wartosc;
		}
	}

	cout << min;
}

void srednia(Tabela tabelka)
{
        float suma = 0;
        for(int i=0; i<tabelka.pocziloscWierszy; i++)
	{
		for(int j=0; j<tabelka.pocziloscKolumn; j++)
		{
			suma + tabelka.tablica[i][j];
			
		}
	}
	float ilosc = tabelka.pocziloscWierszy * tabelka.pocziloscKolumn;
	cout << suma/ilosc ;
}
