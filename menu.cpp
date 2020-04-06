#include <iostream>
using namespace std;

void menu_opcje () {
    cout << "Co chcesz zrobic?" << endl;
    cout << "1\t dodaj element" << endl;
    cout << "2\t wyswietl tablice" << endl;
    cout << "0\t zakoncz program" << endl;
}

void menu_wyswietl () {
    int wybrana_opcja;

    do {
        menu_opcje();
        cin >> wybrana_opcja;
        cin.ignore();
        cout << endl;

        switch (wybrana_opcja) {
            case 1:
                tablica_dodaj_element();
                break;
            case 2:
                tablica_wyswietl();
                break;
        }

    } while (wybrana_opcja != 0);
}
