#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef FORCA_HH
#define FORCA_HH

class Forca {
    public:
        Forca (int);
        
        void configure ();
        bool teste ();
        string getPalavra();
        string getDica();
        vector <char> &getSegredo ();
        vector <string> getPalavras();
        vector <string> getDicas();
        int &getCaracteresFaltantes ();
        int &getTestesRestantes ();
        int getMaxTestes();
        void setPalavra (string);
        void setDica (string);
        void setCaracteresFaltantes (int);
        void setSegredo(char);
        void imprimeSegredo ();

    private:
        string palavra, dica;
        vector <char> segredo;
        vector <string> palavras, dicas;
        int testesRestantes, maxTestes, caracteresFaltantes;
};
#endif