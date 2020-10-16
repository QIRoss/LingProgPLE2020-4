#include <iostream>

#include "linha.hh"

using namespace std;
void printCoordenadas (Ponto p) {

    static int count = 1;
    cout << "[Impressao no. " << count
    << "] : Coordenadas de p (" << p.getCoordX ()
    << ", " << p.getCoordY ()
    << ", " << p.getCoordZ ()
    << ")" << endl;
    count++;
}
int main () {
    Ponto p1 (2, 2, 1);
    Ponto p2;
    Linha linha (p1, p2);
    printCoordenadas (p1);
    printCoordenadas (p2);
    cout << "== O comprimento da linha eh: " << linha.getComprimento () << endl;
    cout << "\nNovas coordenadas para p2...\n" << endl;
    p2.setCoordX(2);
    printCoordenadas (p2);
    linha.setP2 (p2);
    cout << "== O NOVO comprimento da linha eh: " << linha.getComprimento () << endl;
    return 0;
}