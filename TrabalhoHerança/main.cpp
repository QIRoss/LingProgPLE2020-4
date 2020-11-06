#include <iostream>
#include <string>
#include <vector>

#include "catalogo.hh"

using namespace std;

#define OK                              0
#define NUMERO_ARGUMENTOS               1
#define NUMERO_ARGUMENTOS_INVALIDO      1

int
main(int argc,char *argv[]){
    if (argc != NUMERO_ARGUMENTOS){
        cout << "Uso "<< argv[0] <<":\tEste programa não aceita argumentos." << endl;
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }
    int option = 0;
    unsigned index = 0;
    string any;
    filme temp;

    Catalogo cat(argv[1],(unsigned) stoul(argv[2],NULL,10));

    vector<string> menu = {
        "Digite a opção do menu que deseja:",
        "1 - Inserir paciente.",
        "2 - Buscar um paciente.",
        "3 - Listar todos os pacientes",
        "4 - Sair do Programa."
    };
    while(option != 4){
        for(index = 0; index < menu.size() ;index++){
            cout << menu[index] << endl;
        }
        cout << endl;
        cin >> option;

        if (option > 0 && option < 6){
            cout << "Você digitou:" << option << endl;
            switch(option){
                case 1:
                    cout << "Digite o paciente que deseja inserir:" << endl;
                    break;

                case 2:
                    cout << "Digite o Paciente que deseja buscar:" << endl;
                
                    break;

                case 3:
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