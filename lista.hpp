#ifndef lista_hpp
#define lista_hpp

#include <iostream>
#include <string>
#include <exception>
#include "adatok.hpp"

class Lista {
    struct Elem {
        Adatok adat;
        Elem* kov;
        ///Konstruktor (Elem)
        ///@param adat 
        Elem(Adatok& adat) : adat(adat), kov(NULL) {}
    };
    
    Elem* elso;
    size_t elemszam;
public:
    ///Konstruktor
    Lista() : elso(NULL), elemszam(0) {}

    ///Másoló konstruktor
    ///@param lista - Lista, amit másol
    Lista(const Lista& lista);

    Elem* getElso() const {
        return elso;
    }

    ///operator=
    ///@param rhs - Lista
    ///@return Lista&
    Lista& operator=(const Lista& rhs);

    size_t getElemszam() const {
        return elemszam;
    }

    ///Hozzáfűz egy elemet a lista végéhez
    ///@param adat - Adatok amit hozzáfűz a listához
    void hozzafuz(Adatok& adat);

    ///Ellenőrzi, hogy a megadott telefonszám benne van-e a listában
    ///@param telSzam - string amit ellenőriz, hogy benne van-e
    bool benne_van(const std::string& telSzam) const;

    ///A listában lévő összes elemet kiirja
    ///@param os - ostream amire kiírja az adatokat, default ostream -> std::cout
    void listaKiir(std::ostream& os = std::cout) const;

    ///Minden elemet töröl a listából
    void listaTorol();

    ///Törli a megadott elemet a listából
    ///@param telSzam - string ami alapján törli az elemet
    void torol(const std::string& telSzam);

    ///Megkeresi a megadott telefonszám benne van-e a listában, ha benne van kiirja az adatait
    ///@param telSzam - string amit keres
    bool szamKeres(const std::string& telSzam) const;

    ///Megkeresi a megadott név benne van-e a listában, ha benne van kiiírja az adatait
    ///@param nev - string amit keres
    bool nevKeres(const std::string& nev) const;

    ///Telefonszám formátumának ellenőrzése
    ///@param telSzam - string aminek ellőrzi a formátumát(csak számokat tartalmaz-e)
    bool szam_e(const std::string& telSzam) const;

    ///Módosítja a megadott telefonszámú elemet a lsitában
    ///@param telSzam - telefonszám ami alapján módodítja az elemet
    void modosit(const std::string& telSzam);


    ///Destruktor
    ~Lista();

    ///Azért kell a friend, hogy a File osztály hozzáférjen a lista első eleméhez
    friend class File;
};


#endif