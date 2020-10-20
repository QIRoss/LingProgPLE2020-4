// #include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef _CATALOGO_HH_
#define _CATALOGO_HH                "catalogo.hh"

struct filme {
    string nomeFilme;
    string nomeProdutora;
    double notaFilme;
};

class Catalogo {
    private:
        string file;
        vector<filme> estrutura[10];

    public:
        Catalogo(string);
        ~Catalogo();
        void insereOrdenada();
        void removeFilme();
        filme* buscaFilme(string);
        filme* editaFilme();
        void imprimeCatalogo();
        void filmeMaisBemAvaliado();
        void setFile(string);
        void readFile();
        void writeFile();
};

#endif