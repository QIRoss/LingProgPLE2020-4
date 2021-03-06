#include <iostream>
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
bool operator<(filme, filme);
bool operator>(filme, filme);
bool operator==(filme,filme);
vector<filme> operator-=(vector<filme>, filme);

class Catalogo {
    private:
        string txt;
        unsigned maxVector;
        vector<filme> estrutura;
    public:
        friend class ostream;
        Catalogo(string, unsigned);
        Catalogo & operator()(string &);
        ~Catalogo();
        bool insereOrdenada(filme);
        bool insereOrdenada(vector<filme>);
        bool removeFilme(filme);
        filme* operator()(filme);
        void buscaFilme(Catalogo, filme);
        void editaFilme(Catalogo, filme);
        void imprimeCatalogo();
        void filmeMelhorAvaliado();
        void readFile();
        void writeFile();
        friend ostream & operator<<(ostream &,const Catalogo &);
        friend istream & operator>>(istream &, Catalogo &);
        friend ostream & operator<<(ostream &, filme &);
};



#endif