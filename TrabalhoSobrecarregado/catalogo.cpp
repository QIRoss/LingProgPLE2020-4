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
            file << estrutura[index].nomeProdutora;
            file << estrutura[index].notaFilme;
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

void Catalogo::insereOrdenada(filme filmeInicializado){

};

void Catalogo::removeFilme(filme nomeDoFilme){

};

filme* Catalogo::buscaFilme(string filmeEmBusca){

};

filme* Catalogo::editaFilme(filme filmeEmEdicao){

};

void Catalogo::imprimeCatalogo(){

};

void Catalogo::filmeMaisBemAvaliado(){

};


