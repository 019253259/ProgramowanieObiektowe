#include <iostream>
#include <string>

#include "menu.h"
#include "tablica.h"

int main(int argc, char const *argv[])
{
    tablica_zmien_rozmiar(Tablica, 0, 0, 3, 3);
    std::cout << "Podstawowy rozmiar tablicy to 3x3" << std::endl;
    menu_wyswietl();
    return 0;
}
