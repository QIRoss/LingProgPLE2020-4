#include <string.h>
using namespace std;

#ifndef _estadual_hh
#define _estadual_hh    "estadual.hh"

class Estadual {
    public:
        Estadual(char[2]);

        void setEstado(char[2]);

        int getObitos();
    private:
        char uf[2];
        int CalcularObitos(char[2]);        
};


#endif