#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "graph.hh"

using namespace std;

#define NUMERO_ARGUMENTOS                       3
#define EOS                                     '\0'

#define OK                                      0
#define NUMERO_ARGUMENTOS_INVALIDO              1


int main(int argc, char *argv[]){
    Graph something;
    unsigned n;
    if(argc != NUMERO_ARGUMENTOS){
        printf("Uso %s: <NomeDoArquivo.txt> <numero palavras consecutivas>\n",argv[0]);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }
    n = (unsigned) stoul(argv[2], NULL,10);
    something.getIncidencyList(argv[1], n);

    return OK;
}