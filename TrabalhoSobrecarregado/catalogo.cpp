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
    unsigned index;
    for(index = 0;index<destination.size();index++){
        if(toAdd < destination[index]){
            destination.insert(destination.begin() + index - 1,toAdd);
            return destination;
        } else if(toAdd == destination[index]){
            return destination;
        } else {
            index++;
        }
    }
    return destination;
}

vector<filme> 
operator+=(vector<filme> destination, vector<filme> toAdd){
    unsigned indexJ = 0;
    for(indexJ=0;indexJ<toAdd.size();indexJ++){
        destination=destination+=toAdd[indexJ];
    }
    return destination;
}

vector<filme>
operator-=(vector<filme> destination, filme toErase){
    unsigned index;
    for(index=0;index<destination.size();index++){
        if(destination[index] == toErase){
            destination.erase(destination.begin()+index-1);
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
    if(false){

    } else {
        return NULL;
    }
}

filme* Catalogo::editaFilme(filme filmeEmEdicao){
    if(false){

    } else {
        return NULL;
    }
}

void Catalogo::imprimeCatalogo(){
    

}

void Catalogo::filmeMaisBemAvaliado(){

}


