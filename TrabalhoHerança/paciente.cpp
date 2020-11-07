#include <string>

#include "paciente.hh"

using namespace std;

Paciente::Paciente(string nameIn){
    name = nameIn;
}

Paciente::~Paciente(){};

string Paciente::getName(){
    return name;
}