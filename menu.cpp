#include <iostream>
#include "lista.hpp" 
#include "adatok.hpp"
#include "menu.hpp"

///Kiírja a menupontokat
void menuKiir(std::ostream& os) {
    os << "\n-----> MENU <-----" << '\n'
    << "Hozzaadas [1]" << '\n'
    << "Torles [2]" << '\n'
    << "Kiiras [3]" << '\n'
    << "Modositas [4]" << '\n'
    << "Szam Kereses [5]" << '\n'
    << "Nev Kereses [6]" << '\n'
    << "Kilepes [7]" << std::endl;
}

///Bekér a felhasználótól adatokat, majd meghívja a lista hozzafuz() függvényét
///@param lista - Lista, amihez hozzáfűzi a bekért adatokat
void menuBeker(Lista& lista) {
    std::string tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam;

    std::cout << "Nev:";
    std::getline(std::cin, tmpNev);

    std::cout << "Becenev:";
    std::getline(std::cin, tmpBecNev);

    std::cout << "Lakcim:";
    std::getline(std::cin, tmpLakcim);

    std::cout << "Email:";
    std::getline(std::cin, tmpEmail);

    std::cout << "Munkahelyi szam:";
    std::getline(std::cin, tmpMunkSzam);

    std::cout << "Privat szam:";
    std::getline(std::cin, tmpPrivSzam);
    std::cout << std::endl;

    Adatok ujAdat(tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam);
    try {
        lista.hozzafuz(ujAdat);
    }
    catch (std::length_error& err) {
        std::cerr << err.what();
    }
    catch (std::invalid_argument& err) {
        std::cerr << err.what();
    }
}

///Bekér a felhasználótól egy telefonszámot, majd meghívja a lista torol() függvényét
///@param lista - Lista, amiből töröl egy elemet
void menuTorol(Lista& lista) {
    try {
        std::string telszam;
        std::cout << "\nAdja meg a torlni kivant telefonszamot: ";
        std::getline(std::cin, telszam);

        lista.torol(telszam);
    }
    catch (std::length_error& err) {
        std::cerr << err.what();
    } 
}

///Bekér a felhasználótól egy telefonszámot, majd meghívja a lista modosit() függvényét
///@param lista - Lista, amiben modosit egy elemet
void menuModosit(Lista& lista) {
    try {
        std::string telszam;
        std::cout << "\nAdja meg a modositani kivant telefonszamot: ";
        std::getline(std::cin, telszam);

        lista.modosit(telszam);
    }
    catch (std::length_error& err) {
        std::cerr << err.what();
    }
    catch (std::invalid_argument& err) {
        std::cerr << err.what();
    }
}

///Bekér a felhasználótól egy telefonszámot, majd meghívja a lista szamKeres() függvényét
///@param lista - Lista, ahol keresi a telefonszámot
void menuSzamKeres(Lista& lista) {
    std::string telszam;
    std::cout << "\nAdja meg a keresett telefonszamot: ";
    std::getline(std::cin, telszam);

    lista.szamKeres(telszam);
}

///Bekér a felhasználótól egy nevet, majd meghívja a lista nevKeres() függvényét
///@param lista - Lista, ahol keresi a nevet
void menuNevKeres(Lista& lista) {
    std::string nev;
    std::cout << "\nAdja meg a keresett nevet: ";
    std::getline(std::cin, nev);

    lista.nevKeres(nev);
}