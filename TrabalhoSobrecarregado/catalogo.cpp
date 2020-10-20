#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "catalogo.hh"

using namespace std;

void Catalogo::readFile(){

};

void Catalogo::setFile(string){

};

void Catalogo::writeFile(){

};

Catalogo::Catalogo(string file) {
    setFile(file);
    readFile();
};

Catalogo::~Catalogo(){
    writeFile();
};

void Catalogo::insereOrdenada(){

};

void Catalogo::removeFilme(){

};

filme* Catalogo::buscaFilme(string){

};

filme* Catalogo::editaFilme(){

};

void Catalogo::imprimeCatalogo(){

};

void Catalogo::filmeMaisBemAvaliado(){

};


