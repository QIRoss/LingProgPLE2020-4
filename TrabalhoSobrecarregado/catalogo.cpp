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

Catalogo::Catalogo(string file, unsigned maxVec = 10) {
    maxVector = maxVec;
    txt = file;
    // setFile(file);
    readFile();
    cout << "Construindo Catalogo from File " << txt << " limite de tamanho de vetor " << maxVector << "." << endl;
}

Catalogo::~Catalogo(){
    cout << "Destruindo Objeto Catalogo e reescrevendo arquivo " << txt << "." << endl;
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

vector<filme> operator+=(vector<filme> destination, filme toAdd){
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
        if(initialSize != estrutura.size()) {
            return true;
        }
    } else {
        cout << "CATALOGO CHEIO" << endl;
    }
    return false;
}

bool Catalogo::insereOrdenada(vector<filme> filmesInicializados){
    unsigned const initialSize = estrutura.size();
    if (estrutura.size() < maxVector){
        estrutura = estrutura+= filmesInicializados;
        if(initialSize != estrutura.size()) {
            return true;
        }
    } else {
        cout << "CATALOGO CHEIO" << endl;
    }
    return false;
}

bool Catalogo::removeFilme(filme toDelete){
        unsigned size = estrutura.size();
        estrutura = estrutura-=toDelete;
        if(size != estrutura.size()) {
            return true;
        }
        return false;
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

filme* Catalogo::operator()(filme search){
    unsigned index;
    filme *myPointer;
    if(estrutura.size() != 0){
        for(index = 0;index<estrutura.size();index++){
            if(search == estrutura[index]){
                myPointer = &estrutura[index];
                return myPointer;
            }
        }
    } 
    return NULL;
}

void Catalogo::buscaFilme(Catalogo cat, filme search){
    if (cat(search) == NULL){
        cout << "Filme nao encontrado." << endl;
    } else {
        filme thePointer = *cat(search);
        cout << thePointer;
    }
}

void Catalogo::editaFilme(Catalogo cat, filme toEdit){
    if (cat(toEdit) == NULL){
        cout << "Filme nao encontrado." << endl;
    } else {
        char verify;
        filme changer;
        cout << "O quer editar?" << endl << "Digite 1 p/ Produtora" << endl << "Digita 2 p/ Nota" << endl;
        cin >> verify;
        if(verify == '1'){
            cout << "Digite a nova produtora: " << endl;
            cin >> changer.nomeProdutora;
            cat(toEdit)->nomeProdutora = changer.nomeProdutora;
        } else if(verify == '2'){
            cout << "Digite a nova nota: " << endl;
            cin >> changer.notaFilme;
            cat(toEdit)->notaFilme = changer.notaFilme;
        } else {
            cout << "Nenhuma opção correta, nada foi feito." << endl;
        }
    }
}

void Catalogo::imprimeCatalogo(){
    cout << *this;
}
 
istream & operator>>(istream &in, Catalogo c){
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


