// #include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#ifndef _CATALOGO_HH_
#define _CATALOGO_HH                "catalogo.hh"

struct filme {
    string nomeFilme;
    string nomeProdutora;
    double notaFilme;
};

vector<filme> operator+=(vector<filme>, filme);
vector<filme> operator+=(vector<filme>,vector<filme>);

class Catalogo {
    private:
        string txt;
        unsigned maxVector;
        vector<filme> estrutura;
    public:
        Catalogo(string, unsigned);
        Catalogo & operator<(filme &);
        Catalogo & operator>(filme &);
        Catalogo & operator==(filme &);
        Catalogo & operator-=(filme &);
        Catalogo & operator()(string &);
        ~Catalogo();
        void insereOrdenada(filme);
        void insereOrdenada(vector<filme>);
        void removeFilme(filme);
        filme* buscaFilme(string);
        filme* editaFilme(filme);
        void imprimeCatalogo();
        void filmeMaisBemAvaliado();
        void setFile(string);
        void readFile();
        void writeFile();
};

#endif