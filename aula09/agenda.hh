#include <iostream>
#include <string>
#include <vector>
#include "contato.hh"
using namespace std;
#ifndef AGENDA_H
#define AGENDA_H
class Agenda {
friend ostream &operator<< (ostream &, Agenda &);
public:
Agenda ();
Agenda (const Agenda &);
/* Optei inserir contatos diretamente porque assim a agenda fica
mais genérica. Ou seja, ela continua valendo, independente de
quais atributos a classe Contato possui.*/
void insereContato (Contato &);
/* Optei apagar contatos baseando a busca pelo nome. Estou
assumindo que todo contato tem pelo menos o método getNome. */
void apagaContato (string);
Agenda operator- (const Agenda &);
Agenda operator+ (const Agenda &);
private:
vector <Contato *> vContatos;
};
#endif