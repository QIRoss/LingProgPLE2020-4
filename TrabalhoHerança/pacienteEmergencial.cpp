#include <string>
#include "paciente.hh"
#include "pacienteEmergencial.hh"

using namespace std;

// PacienteDerivado::PacienteDerivado(string nameIn){
//     name = nameIn;
// }

PacienteDerivado::~PacienteDerivado(){};

string PacienteDerivado::getName(){
    return '!'+name+'!';
}