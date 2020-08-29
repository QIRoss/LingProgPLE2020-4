

#ifndef _agenda_hh
#define _agenda_hh    "agenda.hh"

#include<iostream>
using namespace std;

#include<string>

class Agenda {
    public: 
        void setContatos(string,string,string);
        string getContatos();

    private:
        string contatos[3];
        string validate(string,string,string);
};


#endif