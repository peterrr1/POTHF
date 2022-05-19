#include <iostream>
#include "filekezeles.hpp"

///@param filenev - file neve ahonnan beolvassa az adatokat
///@param rhs - Lista, ahova beolvassa az adatokat
void File::fileBeolvas(const std::string& filenev, Lista& rhs) {
    std::fstream file;

    file.open(filenev, std::ios::in);
    if (!file) {
        throw std::runtime_error("Fajl megnyitasa sikertelen!\n");
    }
    else {
        std::string sor;

        while (std::getline(file, sor)) {
            std::stringstream ss(sor);

            std::string tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam;

            std::getline(ss, tmpNev, ':');
            std::getline(ss, tmpBecNev, ':');
            std::getline(ss, tmpLakcim, ':');
            std::getline(ss, tmpEmail, ':');
            std::getline(ss, tmpMunkSzam, ':');
            std::getline(ss, tmpPrivSzam, ':');

            Adatok ujAdat(tmpNev, tmpBecNev, tmpLakcim, tmpEmail, tmpMunkSzam, tmpPrivSzam);

            rhs.hozzafuz(ujAdat);
        }
    }
    file.close();
}

///@param filenev - file neve ahova kiírja az adatokat
///@param rhs - Lista, ahonnan kiírja az adatokat
void File::fileKiiras(const std::string& filenev, Lista& rhs) {
    std::fstream file;

    file.open(filenev, std::ios::out);
    if (!file) {
        throw std::runtime_error("Fajl megnyitasa sikertelen!\n");
    }
    else {
        for (Lista::Elem *tmp = rhs.elso; tmp != NULL; tmp = tmp->kov) {
            file << tmp->adat.getNev() << ':' << tmp->adat.getBecenev() << ':' << tmp->adat.getLakcim() << ':' <<
            tmp->adat.getEmail() << ':' << tmp->adat.getMunkSzam() << ':' << tmp->adat.getPrivSzam() << '\n';
        }
    }
    file.close();
}