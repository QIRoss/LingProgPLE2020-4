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
            destination.insert(destination.begin() + index,toAdd);
            return destination;
        } else if(toAdd == destination[index]){
            return destination;
        }
    }
    destination.push_back(toAdd);
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
            destination.erase(destination.begin()+index);
            return destination;
        }
    }
    return destination;
}

void Catalogo::insereOrdenada(filme filmeInicializado){
    if (estrutura.size() < maxVector){
        estrutura = estrutura+=filmeInicializado;
    } else {
        cout << "CATALOGO CHEIO" << endl;
    }
}

void Catalogo::insereOrdenada(vector<filme> filmesInicializados){
    if (estrutura.size() < maxVector){
        estrutura = estrutura+= filmesInicializados;
    } else {
        cout << "CATALOGO CHEIO" << endl;
    }
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


void Catalogo::filmeMaisBemAvaliado(){

}

ostream & operator<<(ostream &out, const Catalogo &c){
    unsigned index;
    for(index=0;index<c.estrutura.size();index++){
        cout << "Filme " << index + 1 << endl
        << "Nome: " << c.estrutura[index].nomeFilme << endl
        << "Produtora: " << c.estrutura[index].nomeProdutora << endl
        << "Nota: " << c.estrutura[index].notaFilme << endl << endl;
    }
    return out;
}
 
istream & operator>>(istream &in, Catalogo &c){
    filme temp;
    cout << endl << "Digite o nome do filme: ";
    cin >> temp.nomeFilme;
    cout << endl << "Digite a produtora: ";
    cin >> temp.nomeProdutora;
    cout << endl << "Digite a nota; ";
    cin >> temp.notaFilme;
    c.insereOrdenada(temp);
    return in;
}

void Catalogo::imprimeCatalogo(){
    cout << *this;
}


