#include "teszt.hpp"
#include <iostream>
#include "gtest_lite.h"

void teszt1() {
    Lista ll;
    File ff;

    std::cout << "\n----------> Adatok osztaly tesztesetei: <-----------" << std::endl;
    ///Adatok osztály tesztelése: 
    ///Getterek tesztjei + adatKiir() függvény tesztje

    ff.fileBeolvas("telefonkonyv.txt", ll);
    //Beolvasott lista elso elemével tesztelunk
    TEST (getterTeszt, getAdat_elsoElem) 
        EXPECT_EQ("Kis Norbert", ll.getElso()->adat.getNev());
        EXPECT_EQ("Norbi", ll.getElso()->adat.getBecenev());
        EXPECT_EQ("Szeged", ll.getElso()->adat.getLakcim());
        EXPECT_EQ("k.norbert@gmail.com", ll.getElso()->adat.getEmail());
        EXPECT_EQ("06708987665", ll.getElso()->adat.getMunkSzam());
        EXPECT_EQ("06209988721", ll.getElso()->adat.getPrivSzam());
    END

    TEST (adatKiirTeszt, adatKiir_elsoElem)
        std::stringstream s1;
        ll.getElso()->adat.adatKiir(s1);
        EXPECT_EQ("Kis Norbert\nNorbi\nSzeged\nk.norbert@gmail.com\n06708987665\n06209988721\n\n", s1.str());
    END

    //==================================

    //Beolvasott listának nem az elso elemével tesztelunk
    TEST (getterTeszt, getAdat_nemElsoELem)
        EXPECT_EQ("Albert Robert", ll.getElso()->kov->adat.getNev());
        EXPECT_EQ("Robi", ll.getElso()->kov->adat.getBecenev());
        EXPECT_EQ("Kecskemet", ll.getElso()->kov->adat.getLakcim());
        EXPECT_EQ("albrobert@gmail.com", ll.getElso()->kov->adat.getEmail());
        EXPECT_EQ("06209900123", ll.getElso()->kov->adat.getMunkSzam());
        EXPECT_EQ("06204399212", ll.getElso()->kov->adat.getPrivSzam());
    END

    TEST (adatKiir, adatKiir_nemElsoElem)
        std::stringstream s2;
        ll.getElso()->kov->kov->adat.adatKiir(s2);
        EXPECT_EQ("Nagy Renata\nReni\nSzekesfehervar\nrenata@gmail.com\n06707080987\n06204044432\n\n", s2.str());
    END

    //==================================

    //Helyben példányosított Adatok objektumon tesztelünk
    Adatok ujAdat("Janosi Mark", "Mark", "Esztergom", "jano.m@gmail.com", "06303040553", "06708999330");

    TEST (getterTeszt, getAdat_adatokObjektum)
        EXPECT_EQ("Janosi Mark", ujAdat.getNev());
        EXPECT_EQ("Mark", ujAdat.getBecenev()); 
        EXPECT_EQ("Esztergom", ujAdat.getLakcim());   
        EXPECT_EQ("jano.m@gmail.com", ujAdat.getEmail());   
        EXPECT_EQ("06303040553", ujAdat.getMunkSzam());
        EXPECT_EQ("06708999330",ujAdat.getPrivSzam());
    END

    TEST (adatKiir, adatKiir_adatokObj)
        std::stringstream s3;
        ujAdat.adatKiir(s3);
        EXPECT_EQ("Janosi Mark\nMark\nEsztergom\njano.m@gmail.com\n06303040553\n06708999330\n\n", s3.str());
    END

    //==================================


    ff.fileKiiras("telefonkonyv.txt", ll);
}

void teszt2() {
    Lista ll;
    File ff;
    std::cout << "\n----------> Lista osztaly tesztesetei: <----------" << std::endl;

    //14 nevet olvasunk be
    TEST (fileBeolvasTeszt, fileBeolvasasa)
        EXPECT_NO_THROW(ff.fileBeolvas("telefonkonyv.txt", ll));
    END

    //elemszám tesztelése
    TEST (getElemszamTeszt, beolvasottAdatokSzama)
        EXPECT_EQ(51, ll.getElemszam());
    END

    //hozzáadunk még egy nevet
    TEST (listaHozzafuzTeszt, adatHozzafuzes)
        Adatok balazs("Kis Balazs", "Balazs", "Budapest", "k.balazs@gmail.com", "06479261335", "06219265394");
        EXPECT_NO_THROW(ll.hozzafuz(balazs));
    END

    //elemszám tesztelése
    TEST (getElemszamTeszt, listabanLevoAdatokSzama)
        EXPECT_EQ(52, ll.getElemszam());
    END

    //elem törlése a listából
    TEST (torolTeszt, egyAdatTorlese) 
        EXPECT_NO_THROW(ll.torol("06219265394")); // bemenet : i vagy I
    END

    //elemszám tesztelése
    TEST (getElemszamTeszt, listabanLevoAdatokSzama)
        EXPECT_EQ(51, ll.getElemszam());
    END

    //első elem módosítása
    TEST (modositTeszt, modositElsoElem)
        EXPECT_NO_THROW(ll.modosit("06209988721"));
        std::stringstream s;
        ll.getElso()->adat.adatKiir(s);
        EXPECT_EQ("Kis Norbert\nNorbi\nBudapest\nk.norbert@gmail.com\n06708987665\n06209988721\n\n", s.str());
    END

    TEST (modositTeszt, modositElsoElemKivetel)
        EXPECT_THROW(ll.modosit("06209988721"), std::invalid_argument&);
    END

    TEST (modositTeszt, modositElem)
        EXPECT_NO_THROW(ll.modosit("06707080987"));
        std::stringstream str;
        ll.getElso()->kov->kov->adat.adatKiir(str);
        EXPECT_EQ("Nagy Renata\nReni\nSzekesfehervar\nrenata.nagy@gmail.com\n06707080987\n06204044432\n\n" ,str.str());
    END

    TEST (modositTeszt, modositElem)
        EXPECT_THROW(ll.modosit("06707080987"), std::length_error&);
    END

    //egész lista törlése
    TEST (listaTorol, egeszListaTorlese) 
        ll.listaTorol();
        EXPECT_EQ(nullptr, ll.getElso());
        EXPECT_THROW(ll.torol("06206745912"), std::length_error&);
    END

    TEST (copyCtorTeszt, copyCtorUresLista)
        Lista ll2(ll);
        EXPECT_EQ(nullptr, ll2.getElso());
        EXPECT_EQ(0, ll2.getElemszam());
    END

    TEST (operator=Teszt, operator=UresLista)
        Lista ll3;
        ll3 = ll;
        EXPECT_EQ(nullptr, ll3.getElso());
        EXPECT_EQ(0, ll3.getElemszam());
    END

    //elemszám tesztelése
    TEST (getElemszamTeszt, listabanLevoAdatokSzama)
        EXPECT_EQ(0, ll.getElemszam());
    END

    TEST (modositasTeszt, modositasUresLista)
        EXPECT_THROW(ll.modosit("06209988721"), std::length_error&);
    END

    //ismét beolvasunk fájlból
    TEST (fileBeolvasasTeszt, fileBeolvasas)
        EXPECT_NO_THROW(ff.fileBeolvas("telefonkonyv.txt", ll));
    END

    //elemszám tesztelése
    TEST (getElemszamTeszt, listabanLevoAdatokSzama)
        EXPECT_EQ(51, ll.getElemszam());
    END

    //hibás hozzáfűzés (túl hosszú telefonszám)
    TEST (listaHozzafuzTeszt, adatHozzafuzesKivetel)
        Adatok bela("Nagy Bela Odon", "Odon", "Budapest", "bela@gmail.com", "062098223211", "06205699871");
        EXPECT_THROW(ll.hozzafuz(bela), std::length_error&);
        EXPECT_EQ(51, ll.getElemszam());
    END

    //hibás hozzáfűzés (betű van a telefonszámban)
    TEST (listaHozzafuzTeszt, adatHozzafuzesKivetel)
        Adatok tamas("Kis-Nagy Tamas", "Tomi", "Gyor", "kn.tamas@gmail.com", "062w0798556", "06229899526");
        EXPECT_THROW(ll.hozzafuz(tamas), std::invalid_argument&);
        EXPECT_EQ(51, ll.getElemszam());
    END

    TEST (torolTeszt, egyElemTorlese)
        std::cout << "Bemenet: n vagy N\n";
        EXPECT_NO_THROW(ll.torol("73814138166"));    //bemenet: n vagy N
        EXPECT_EQ(51, ll.getElemszam());

        std::cout << "Bemenet: nem i, nem n\n";
        EXPECT_NO_THROW(ll.torol("83450501869"));    //bemenet: bármi
        EXPECT_EQ(51, ll.getElemszam());
    END

    TEST (szam_eTeszt, bemenetSzam_e)
        EXPECT_TRUE(ll.szam_e("06204577898"));
        EXPECT_FALSE(ll.szam_e("062089sd56w"));
        EXPECT_FALSE(ll.szam_e("asdadad"));
        EXPECT_TRUE(ll.szam_e("06709989543"));
    END


    TEST (szamBenneVanTeszt, szamBenneVan)
        EXPECT_TRUE(ll.benne_van("06204399212"));
        EXPECT_FALSE(ll.benne_van("06101010101"));
        EXPECT_TRUE(ll.benne_van("06708351995"));
        EXPECT_TRUE(ll.benne_van("06707080987"));
        EXPECT_FALSE(ll.benne_van("06202020202"));
    END

    TEST (szamKeresTeszt, szamKeres)
        EXPECT_TRUE(ll.szamKeres("69378905533"));
        EXPECT_TRUE(ll.szamKeres("88966878292"));
        EXPECT_FALSE(ll.szamKeres("99999999999"));
        EXPECT_FALSE(ll.szamKeres("37907545366"));
    END

    TEST (nevKeresTeszt, nevKereses)
        EXPECT_TRUE(ll.nevKeres("Balogh Kata"));
        EXPECT_TRUE(ll.nevKeres("Pap Izabella"));
        EXPECT_FALSE(ll.nevKeres("Varga-Nagy Szabolcs"));
        EXPECT_FALSE(ll.nevKeres("Tasnadi Orsolya"));
    END

    TEST (listaHuzzafuzTeszt, adatHozzafuzesKivetel)
        Adatok ruben("Nagy Ruben", "Ruben", "Budapest", "ruben@gmail.com", "06204567112", "62967142189");
        EXPECT_THROW(ll.hozzafuz(ruben), std::invalid_argument&);
    END

    TEST (copyCtorTeszt, copyCtor)
        Lista lista(ll);
        EXPECT_EQ(51, lista.getElemszam());
        std::stringstream ss;
        lista.getElso()->adat.adatKiir(ss);
        EXPECT_EQ("Kis Norbert\nNorbi\nSzeged\nk.norbert@gmail.com\n06708987665\n06209988721\n\n", ss.str());
    END

    TEST (operator=Teszt, operator=)
        Lista lista2;
        lista2 = ll;
        EXPECT_EQ(51, lista2.getElemszam());
        std::stringstream ss2;
        lista2.getElso()->kov->adat.adatKiir(ss2);
        EXPECT_EQ("Albert Robert\nRobi\nKecskemet\nalbrobert@gmail.com\n06209900123\n06204399212\n\n", ss2.str());
    END
    
    TEST (fileKiirasTeszt, fileKiiras)
        EXPECT_NO_THROW(ff.fileKiiras("telefonkonyv.txt",ll));
    END
}

void teszt3() {
    Lista ll;
    File ff;
    std::cout << "\n----------> File osztaly tesztesetei: <----------" << std::endl;
    
    TEST (fileBeolvasTeszt, fileBeolvas)
        EXPECT_NO_THROW(ff.fileBeolvas("telefonkonyv.txt", ll));
    END

    TEST (fileKiirasTeszt, fileKiiras)
        EXPECT_NO_THROW(ff.fileKiiras("telefonkonyv.txt", ll));
    END

    TEST (fileBeolvasTeszt, fileBeolvasKivetel)
        EXPECT_THROW(ff.fileBeolvas("", ll), std::runtime_error&);
    END

    TEST (fileKiirasTeszt, fileKiirasKivetel)
        EXPECT_THROW(ff.fileKiiras("", ll), std::runtime_error&);
    END
}

void teszt4() {
    Lista ll;
    File ff;

    std::cout << "Menu fuggvenyek tesztelese: " << std::endl;

    ff.fileBeolvas("telefonkonyv.txt",ll);

    TEST (menuKiirTeszt, menuKiir)
        std::stringstream s1;
        menuKiir(s1);
        EXPECT_EQ("\n-----> MENU <-----\nHozzaadas [1]\nTorles [2]\nKiiras [3]\nModositas [4]\nSzam Kereses [5]\nNev Kereses [6]\nKilepes [7]\n", s1.str());
    END

    TEST (menuBekerTeszt, MenuBeker)
        EXPECT_NO_THROW(menuBeker(ll));
        EXPECT_EQ(52, ll.getElemszam());
    END

    TEST (menuTorolTeszt, menuTorol)
        EXPECT_NO_THROW(menuTorol(ll));
        EXPECT_EQ(51, ll.getElemszam());
        ll.listaTorol();
    END

    ff.fileBeolvas("telefonkonyv.txt", ll);

    ff.fileKiiras("telefonkonyv.txt", ll);
}

