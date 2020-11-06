#include <iostream>
#include <string>
#include <iomanip>

#include "catalogo.hh"
#include "paciente.hh"
#include "arvore.hh"

using namespace std;

#ifndef _CADASTRO_HH_
#define _CADASTRO_HH_               "cadastro.hh"

class Cadastro {
    private:

    public:
        Cadastro();
        ~Cadastro();
        Paciente* & operator+=(const Paciente &);
        friend ostream & operator<<(ostream &,const Cadastro &);
        friend ostream & operator<<(ostream &,const Paciente &);
        Paciente* operator()(Paciente &);
};


#endif