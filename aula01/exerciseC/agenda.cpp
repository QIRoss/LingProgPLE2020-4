#include "agenda.hh"

#include<iostream>
using namespace std;

#include<string>
void Agenda::setContatos(string name1,string name2,string name3) {
    contatos[0] = name1;
    contatos[1] = name2;
    contatos[2] = name3;
}

string[] Agenda::getContatos() { 
    string agenda[3];
    unsigned index;
    for(index=0;index<contatos.length;i++){
        if(contatos[index].validate == 0){
            agenda[index]=contato[index];
        }
    }
    return agenda;
}

string Agenda::validate(string name) { 
    if (name.length() > 10) {
        return 0;
    }
    return 1;
}