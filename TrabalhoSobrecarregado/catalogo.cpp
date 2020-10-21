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
}

void Catalogo::setFile(string file){
    txt = file;
}
 
void Catalogo::writeFile(){
    ofstream file(txt);
    unsigned index;
    // file.open(txt.c_str());
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
}

Catalogo::Catalogo(string file, unsigned maxVector = 10) {
    setFile(file);
    readFile();
}

Catalogo::~Catalogo(){
    writeFile();
}

bool
operator<(filme left, filme right){
        if(left.nomeFilme < right.nomeFilme) return true;
        return false;
}

bool
operator>(filme left, filme right){
        if(left.nomeFilme > right.nomeFilme) return true;
        return false;
}

bool
operator==(filme left, filme right){
    if(left.nomeFilme == right.nomeFilme) return true;
    return false;
}

vector<filme> 
operator+=(vector<filme> destination, filme toAdd){
    destination.push_back(toAdd);
    return destination;
}

vector<filme> 
operator+=(vector<filme> destination, vector<filme> toAdd){
    unsigned index = 0;
    for(index=0;index<toAdd.size();index++){
        destination.push_back(toAdd[index]);
    }
    return destination;
}

vector<filme>
operator-=(vector<filme> destination, filme toErase){
    unsigned index;
    for(index=0;index<destination.size();index++){
        if(destination[index] == toErase){
            destination.erase(destination.begin()+index);
            return destination;
        }
    }
    return destination;
}

void Catalogo::insereOrdenada(filme filmeInicializado){
    estrutura = estrutura+=filmeInicializado;
}

void Catalogo::insereOrdenada(vector<filme> filmesInicializados){
    estrutura = estrutura+=filmesInicializados;
}

void Catalogo::removeFilme(filme toDelete){
    estrutura = estrutura-=toDelete;
}

filme* Catalogo::buscaFilme(string filmeEmBusca){

}

filme* Catalogo::editaFilme(filme filmeEmEdicao){
    return NULL;
}

void Catalogo::imprimeCatalogo(){
    

}

void Catalogo::filmeMaisBemAvaliado(){

}


