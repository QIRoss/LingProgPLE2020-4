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
    string any;
    filme test;
    test.nomeFilme = "Teste";
    test.nomeProdutora = "algo";
    test.notaFilme = 4;

    Catalogo cat(argv[1],(unsigned) stoul(argv[2],NULL));

    vector<string> menu = {
        "Digite a opção do menu que deseja:",
        "1 - Adicionar/Remover filmes.",
        "2 - Buscar um filme.",
        "3 - Editar um filme.", 
        "4 - Imprimir todos os filmes.",
        "5 - Ver filme mais bem avaliado.",
        "6 - Sair do Programa."
    };
    while(option != 6){
        for(index = 0; index < menu.size() ;index++){
            cout << menu[index] << endl;
        }
        cout << endl;
        cin >> option;

        if (option > 0 && option < 6){
            cout << "Você digitou:" << option << endl;
            switch(option){
                case 1:
                    cin >> cat;
                    break;

                case 2:
                    cat.buscaFilme(cat, test);
                    break;

                case 3:
                    cat.editaFilme(cat, test);
                    break;

                case 4:
                    cat.imprimeCatalogo();
                    break;

                case 5:
                    cat.filmeMelhorAvaliado();
                    break;
            }
            cout << "Pressione alguma tecla para continuar: " << endl;
            cin >> any;
            cout << endl;
            index = 0;
            cout << "Digite uma nova opção:" << endl;
        }
    }
    cout << "Encerrando o programa." << endl;
    return OK;
}