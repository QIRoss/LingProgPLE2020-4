#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define NUMERO_ARGUMENTOS                       2
#define EOS                                     '\0'

#define OK                                      0
#define NUMERO_ARGUMENTOS_INVALIDO              1

struct node{
    string word;
    
    node* next[];
};

class Graph {
    int vertex;
    vector<vector<node>> **i;
};

int main(int argc, char *argv[]){
    fstream file; 
    string word, t, q, filename; 
    filename = argv[1];
    vector<string> phrase;
    unsigned index=0;

    if(argc != NUMERO_ARGUMENTOS){
        printf("Uso %s: <NomeDoArquivo.txt\n",argv[0]);
        exit(NUMERO_ARGUMENTOS_INVALIDO);
    }

    file.open(filename.c_str());

    while (file >> word) { 
        phrase.push_back(word);
        cout << phrase[index] << endl;
        index++;
    }
    file.close();

    return OK;
}