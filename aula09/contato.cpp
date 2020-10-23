#include "contato.hh"

Contato::Contato (string n, string t): nome (n), telefone (t) {}

string Contato::getNome () { return nome; }

string Contato::getTelefone () { return telefone; }

void Contato::print () {
    cout << getNome () << ": " << getTelefone () << endl;
}