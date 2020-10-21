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
    filme movieTwo;
    movie.nomeFilme = "Bianca";
    movie.nomeProdutora = "Claudia";
    movie.notaFilme = 10;

    movieTwo.nomeFilme = "Siode";
    movieTwo.nomeProdutora = "Night";
    movieTwo.notaFilme = 8;
    vector<filme> movies = {movie, movieTwo};
    cat.insereOrdenada(movies);
    return OK;
}