#include <string>

using namespace std;

#ifndef _PACIENTE_HH_
#define _PACIENTE_HH_               "paciente.hh"

class Paciente {
    private:
        string name;
    public:
        Paciente(string);
        ~Paciente();
        virtual string getName();
};

#endif