#include <iostream>
#include "agenda.hh"
#include "contato.hh"
using namespace std;

int main() {
    Agenda agenda;
    Contato c1 ("Miguel", "111222");
    agenda.insereContato (c1);
    Contato c2 ("Joao", "222333");
    agenda.insereContato (c2);
    Agenda agendaCopia (agenda);
    cout << "Depois das inserções:" << endl;
    cout << agenda << endl;
    cout << "E a cópia, como ficou?" << endl;
    cout << agendaCopia << endl;
    agenda.apagaContato ("Miguel");
    cout << "Depois de apagar o contato Miguel:" << endl;
    cout << agenda << endl;
    cout << "Qual a diferença da cópia para a original?" << endl;
    Agenda agendaDif = (agendaCopia - agenda);
    cout << agendaDif << endl;
    cout << "Vamos concatenar tudo de novo em uma nova:" << endl;
    Agenda agendaNova = (agenda + agendaDif);
    cout << agendaNova << endl;
    return 0;
}