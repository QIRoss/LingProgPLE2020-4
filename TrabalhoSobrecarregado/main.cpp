#include <iostream>
#include <string>
#include <vector>

#include "catalogo.hh"

using namespace std;

#define OK                              0
#define NUMERO_ARGUMENTOS               3

#define NUMERO_ARGUMENTOS_INVALIDO      1

int
main(int argc,char *argv[]){
    if (argc != NUMERO_ARGUMENTOS){
        cout << "Uso %s:\t<arquivoBase.txt> <tamanhoMaximo>" << endl;
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }
    int option = 0;
    unsigned index = 0;

    Catalogo cat(argv[1],(unsigned) stoul(argv[2],NULL));

    vector<string> menu = {
        "Digite a opção do menu que deseja:",
        "1 - Adicionar um filme.",
        "2 - Adicionar multiplos filmes.",
        "3 - Remover um filme.",
        "4 - Buscar um filme.",
        "5 - Editar um filme.", 
        "6 - Imprimir todos os filmes.",
        "7 - Ver filme mais bem avaliado.",
        "8 - Sair do Programa."
    };

    for(index = 0; index < menu.size() ;index++){
            cout << menu[index] << endl;
        }
    cout << endl;
    // while(option !=8){
        
    // }
    cin >> cat;
    cat.imprimeCatalogo();
    return OK;
}