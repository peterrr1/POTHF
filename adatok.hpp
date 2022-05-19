#ifndef adatok_hpp
#define adatok_hpp

#include <iostream>
#include <string>

class Adatok {
    std::string Nev;
    std::string Becenev;
    std::string Lakcim;
    std::string Email;
    std::string MunkSzam;
    std::string PrivSzam;
public:
    ///Paraméter nélkül hívható konstruktor
    Adatok();

    ///Konstruktor
    ///az adattagokat beállítja a nekik megfelelő nevű, paraméterként kapott stringre
    Adatok(const std::string& aNev = "", const std::string& aBecNev = "", const std::string& aLakcim = "", const std::string& aEmail = "", const std::string& aMunkSzam = "", const std::string& aPrivSzam = "")
    : Nev(aNev), Becenev(aBecNev), Lakcim(aLakcim), Email(aEmail), MunkSzam(aMunkSzam), PrivSzam(aPrivSzam) {}

    ///@return std::string Nev;
    const std::string& getNev() const {
        return Nev;
    }

    ///@return std::string Becenev
    const std::string& getBecenev() const {
        return Becenev;
    }

    ///@return std::string Lakcim
    const std::string& getLakcim() const {
        return Lakcim;
    }

    ///@return std::string Email
    const std::string& getEmail() const {
        return Email;
    } 

    ///@returns std::string MunkSzam
    const std::string& getMunkSzam() const {
        return MunkSzam;
    }

    ///@returns std::string PrivSzam
    const std::string& getPrivSzam() const {
        return PrivSzam;
    }
    
    ///@param os - ostream amire kiírja az adatokat, default ostream -> std::cout
    void adatKiir(std::ostream& os = std::cout) const {
        os << Nev << '\n' << Becenev << '\n' << Lakcim <<
        '\n' << Email << '\n' << MunkSzam << '\n' << PrivSzam << '\n' << std::endl;
    }

    ///Destruktor
    ~Adatok() {}
};


#endif