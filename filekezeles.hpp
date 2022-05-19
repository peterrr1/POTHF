#ifndef filekezeles_hpp
#define filekezeles_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "lista.hpp"

class File {
public:
    ///@param filenev - file neve ahonnan beolvassa az adatokat
    ///@param rhs - Lista, ahova beolvassa az adatokat
    void fileBeolvas(const std::string& filenev, Lista& rhs);

    ///@param filenev - file neve ahova kiírja az adatokat
    ///@param rhs - Lista, ahonnan kiírja az adatokat
    void fileKiiras(const std::string& filenev, Lista& rhs);
};

#endif