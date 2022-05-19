#include <iostream>
#include "adatok.hpp"
#include "lista.hpp"
#include "filekezeles.hpp"
#include "teszt.hpp"
#include "menu.hpp"


//A TESZT makróval lehet kiválasztani, hogy a tesztesetek fussanak le vagy a menü fusson
//Ha definiálva van a TESZT makró akkor a tesztesetek futnak le, tesztek implementációja a telefonkonyv_teszt.cpp fájlban található
//Ha nincsen defini8álva a TESZT makró akkor a menü fut le
#define TESZT

int main() {

#ifdef TESZT
    teszt1();
    teszt2();
    teszt3();
    teszt4();
#endif
#ifndef TESZT
    Lista ll;
    File ff;
    int c;
    menuKiir();
    ff.fileBeolvas("telefonkonyv.txt",ll);
    while (std::cin >> c && c != 7) {
        if (std::cin.eof()){
            return 0;
        }
        std::cin.ignore();
        switch (c) {
            case 1:
                menuBeker(ll);
                break;
            case 2:
                menuTorol(ll);
                break;  
            case 3:
                ll.listaKiir();
                std::cout << ll.getElemszam() << std::endl;
                break;
            case 4:
                menuModosit(ll);
                break;
            case 5:
                menuSzamKeres(ll);
                break;
            case 6:
                menuNevKeres(ll);
                break;
            case 7:
                break;
            default:
                std::cout << "\nHibas bemenet." << std::endl;
                break;
        }
        menuKiir();
    }
    ff.fileKiiras("telefonkonyv.txt",ll);
#endif
}