#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "graph.hh"

using namespace std;

#define NUMERO_ARGUMENTOS                       2
#define EOS                                     '\0'

#define OK                                      0
#define NUMERO_ARGUMENTOS_INVALIDO              1


int main(int argc, char *argv[]){
    Graph something;

    if(argc != NUMERO_ARGUMENTOS){
        printf("Uso %s: <NomeDoArquivo.txt\n",argv[0]);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    something.getIncidencyList(argv[1], 1);

    return OK;
}