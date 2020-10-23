#include <iostream>
#include "agenda.hh"

ostream &operator<< (ostream &out, Agenda &a) {
    for (int i = 0; i < a.vContatos.size (); i++) {
        ((a.vContatos).at (i))->print ();
    }
return out;
}

Agenda::Agenda () {}

Agenda::Agenda (const Agenda &a) {
    vContatos = a.vContatos;
}

void Agenda::insereContato (Contato &c) {
    vContatos.push_back (&c);
}

void Agenda::apagaContato (string n) {
    vector <Contato *>::iterator it = vContatos.begin ();
    for (; it != vContatos.end (); it++) {
        if (!((*it)->getNome ()).compare (n)) {
            vContatos.erase (it);
            break;
        }
    }
}

Agenda Agenda::operator- (const Agenda &a) {
    Agenda agenda;
    bool achou;
    for (int i = 0; i < this->vContatos.size (); i++) {
        achou = false;
        for (int j = 0; j < a.vContatos.size (); j++) {
            string nome = (this->vContatos).at (i)->getNome ();
        if (!nome.compare (a.vContatos.at (j)->getNome ())) {
            achou = true; break;
        }
        }
        if (!achou) agenda.insereContato (*(this->vContatos.at (i)));
    }
    return agenda;
}

Agenda Agenda::operator+ (const Agenda &a) {
    Agenda agenda;
    for (int i = 0; i < this->vContatos.size (); i++) {
        Contato *c = this->vContatos.at (i);
        agenda.insereContato (*c);
    }
    bool achou;
    for (int i = 0; i < a.vContatos.size (); i++) {
        achou = false;
        for (int j = 0; j < this->vContatos.size (); j++) {
            string nome = (a.vContatos).at (i)->getNome ();
            if (!nome.compare (this->vContatos.at (j)->getNome ())) {
                achou = true; break;
            }
        }
        if (!achou) agenda.insereContato (*a.vContatos.at (i));
    }
    return agenda;
}