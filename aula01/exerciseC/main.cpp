#include <iostream>
#include <string>
#include "agenda.hh"
using namespace std;

int main (int argc, char *argv[]){
    if (argc != 4){
        cout << "É necessário 3 argumentos de entrada" << endl;
        return 1;
    }

    Agenda agenda;
    agenda.setContatos(argv[1],argv[2],argv[3]);

    cout << agenda.getContatos() << endl;
  
    return 0;
}