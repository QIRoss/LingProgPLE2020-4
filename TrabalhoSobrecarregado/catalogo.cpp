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

bool Catalogo::insereOrdenada(filme filmeInicializado){
    unsigned initialSize = estrutura.size();
    if (estrutura.size() < maxVector){
        estrutura = estrutura+=filmeInicializado;
        if(initialSize != estrutura.size()) return true;
    } else {
        cout << "CATALOGO CHEIO" << endl;
    }
    return false;
}

bool Catalogo::insereOrdenada(vector<filme> filmesInicializados){
    unsigned initialSize = estrutura.size();
    if (estrutura.size() < maxVector){
        estrutura = estrutura+= filmesInicializados;
        if(initialSize != estrutura.size()) return true;
    } else {
        cout << "CATALOGO CHEIO" << endl;
    }
    return false;
}

bool Catalogo::removeFilme(filme toDelete){
        unsigned size = estrutura.size();
        estrutura = estrutura-=toDelete;
        if(size != estrutura.size()) return true;
        return false;
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

ostream & operator<<(ostream &out, filme &c){
    cout
    << "Nome: " << c.nomeFilme << endl
    << "Produtora: " << c.nomeProdutora << endl
    << "Nota: " << c.notaFilme << endl << endl;
    return out;
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

void Catalogo::imprimeCatalogo(){
    cout << *this;
}
 
istream & operator>>(istream &in, Catalogo &c){
    filme temp;
    bool verify;
    string loop;
    cout << endl << "Digite o nome do filme: ";
    cin >> temp.nomeFilme;
    cout << endl << "Digite a produtora: ";
    cin >> temp.nomeProdutora;
    cout << endl << "Digite a nota; ";
    cin >> temp.notaFilme;
    verify = c.insereOrdenada(temp);
    if(verify == true){
        cout << "Filme adicionado ao catalogo." << endl;
    } else {
        cout << "Filme ja existe no catalogo." << endl;
        verify = c.removeFilme(temp);
        if (verify == true) {
            cout << "Filme removido do catalogo." << endl;
        }
    }
    cout << "Deseja adicionar/remover mais um filme?(S/N)" << endl;
    cin >> loop;
    loop = tolower(loop[0]);
    if (loop == "s"){
        cin >> c;
    }
    return in;
}


void Catalogo::filmeMelhorAvaliado(){
    unsigned index = 0;
    double tempNota = 0;
    unsigned tempIndex=0;
    for(index=0;index<estrutura.size();index++){
        if(estrutura[index].notaFilme > tempNota){
            tempNota = estrutura[index].notaFilme;
            tempIndex = index;
        }
    }
    cout << "Filme Mais bem Avaliado:" << endl;
    cout << estrutura[tempIndex];
}


