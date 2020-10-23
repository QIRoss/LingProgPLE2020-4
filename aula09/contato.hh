#include <iostream>
#include <string>
using namespace std;
#ifndef CONTATO_H
#define CONTATO_H
class Contato {
public:
Contato (string, string);
string getNome ();
string getTelefone ();
void print ();
private:
string nome, telefone;
};
#endif