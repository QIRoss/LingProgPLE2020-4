#include <string>
#include "paciente.hh"

using namespace std;

#ifndef _PACIENTE_DERIVADO_HH_
#define _PACIENTE_DERIVADO_HH_               "pacienteDerivado.hh"

class PacienteDerivado : public Paciente {
    private:
        string name;
    public:
        PacienteDerivado(string);
        ~PacienteDerivado();
        string getName();
};

#endif