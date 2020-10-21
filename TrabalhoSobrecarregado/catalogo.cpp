#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "catalogo.hh"

using namespace std;

void Catalogo::readFile(){
    fstream file;
    string line;
    filme buffer;
    file.open(txt.c_str());
    while (file>>line){
        buffer.nomeFilme = line;
        file>>line;
        buffer.nomeProdutora = line;
        file>>line;
        buffer.notaFilme = stod(line,NULL);
        estrutura.push_back(buffer);
    }
    file.close();
};

void Catalogo::setFile(string file){
    txt = file;
};

void Catalogo::writeFile(){
    ofstream file(txt);
    unsigned index;
    if(file.is_open()){
        for(index=0;index<estrutura.size();index++){
                file << estrutura[index].nomeFilme;
                file << '\n';
                file << estrutura[index].nomeProdutora;
                file << '\n';
                file << estrutura[index].notaFilme;
                file << '\n';
        }
        file.close();
    }
};

Catalogo::Catalogo(string file, unsigned maxVector = 10) {
    setFile(file);
    readFile();
};

Catalogo::~Catalogo(){
    writeFile();
};

void operator+=(vector<filme> destination, filme some){
    cout << destination.size() << endl;
    destination.push_back(some);
    cout << destination.size() << endl;
    cout << destination[0].nomeFilme << destination[1].nomeFilme << destination[2].nomeFilme << destination[3].nomeFilme << endl;
};

void Catalogo::insereOrdenada(filme filmeInicializado){
    estrutura+=filmeInicializado;
};

void Catalogo::removeFilme(filme nomeDoFilme){

};

filme* Catalogo::buscaFilme(string filmeEmBusca){
    return NULL;
};

filme* Catalogo::editaFilme(filme filmeEmEdicao){
    return NULL;
};

void Catalogo::imprimeCatalogo(){

};

void Catalogo::filmeMaisBemAvaliado(){

};


