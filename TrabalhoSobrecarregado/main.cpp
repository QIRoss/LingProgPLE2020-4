#include <iostream>
#include <string>
#include <vector>

#include "catalogo.hh"

using namespace std;

#define OK                              0

int
main(int argc,char *argv[]){
    Catalogo cat("filmes.txt",10);
    filme movie;
    movie.nomeFilme = "Bianca";
    movie.nomeProdutora = "Claudia";
    movie.notaFilme = 10;
    cat.insereOrdenada(movie);
    return OK;
}