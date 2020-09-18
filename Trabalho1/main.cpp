#include <iostream>
#include <vector>
#include <string>

#include "estadual.hh"
#include "nacional.hh"
 
using namespace std;

#define INVALID_ARGV                    2
#define TOO_MANY_INVALID_OPTS           3

int
main(int argc, char *argv[]){
    if (argc > 1){
        cout << "Este programa nao aceita argumentos iniciais" << endl 
        << "Encerrando Programa" << endl;
        exit (INVALID_ARGV);
    }
    int option = 0;
    unsigned index = 0;
    unsigned errorOpt = 0;

    vector<string> menu = {
        "Digite a opção do menu que deseja:",
        "1 - Exibir Evolucao de Porcentagem Estadual e Evolucao de Porcentagem Nacional",
        "2 - Exibir Estados em Alta, Baixa e Estabilidade",
        "3 - Exibir Status do Brasil (Alta, Baixa ou Estabilidade)",
        "4 - Estado com Maior alta e Maior baixa",
        "5 - Exibir dados acumulados no Brasil e Estados", 
        "6 - Sair do programa"
    };

    while (option != 6){
        if (errorOpt> 2){
            cout << "Voce digitou opcoes invalidas 3 vezes. Estamos encerrando o programa." << endl;
            exit (TOO_MANY_INVALID_OPTS);
        }

        for(; index < 7 ;index++){
            cout << menu[index] << endl;
        }
        cout << endl;
        cin >> option;

        if (option > 0 && option < 7){
            cout << "Você digitou:" << option << endl;
            
            switch(option){
                case 1:
                    cout << "ta chegando aa";
                    break;

                case 2:
                    
                    break;
                
                case 3:
                    break;

                case 4:
                    break;

                case 5:
                    break;
            }

            index = 0;
        } else {
            cout << "Digite uma opção valida:" << endl << endl;
            index = 1;
            errorOpt++;
        }
    }


    cout << "Encerrando o programa." << endl;
    return 0;
}