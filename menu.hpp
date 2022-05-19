#ifndef menu_hpp
#define menu_hpp

#include <iostream>
#include "lista.hpp"
#include <string>
#include <exception>


    ///Kiírja a menupontokat
    void menuKiir(std::ostream& os = std::cout);

    ///Bekér a felhasználótól adatokat, majd meghívja a lista hozzafuz() függvényét
    ///@param lista - Lista, amihez hozzáfűzi a bekért adatokat
    void menuBeker(Lista& lista);

    ///Bekér a felhasználótól egy telefonszámot, majd meghívja a lista torol() függvényét
    ///@param lista - Lista, amiből töröl egy elemet
    void menuTorol(Lista& lista);

    ///Bekér a felhasználótól egy telefonszámot, majd meghívja a lista modosit() függvényét
    ///@param lista - Lista, amiben modosit egy elemet
    void menuModosit(Lista& lista);

    ///Bekér a felhasználótól egy telefonszámot, majd meghívja a lista szamKeres() függvényét
    ///@param lista - Lista, ahol keresi a telefonszámot
    void menuSzamKeres(Lista& lista);

    ///Bekér a felhasználótól egy nevet, majd meghívja a lista nevKeres() függvényét
    ///@param lista - Lista, ahol keresi a nevet
    void menuNevKeres(Lista& lista);

#endif