#include <iostream>
#include "paralelepipedo.hh"

using namespace std;
int main () {

double dx = 1.1, dy = 2.2, dz = 3.3;

Paralelepipedo paralelepipedo (dx, dy, dz);

cout << "\n\nO volume eh: " << paralelepipedo.getVolume () << endl;
cout << "\n\nmudando os valores das dimensoes..." << endl;
paralelepipedo.setDimX (-1);
paralelepipedo.setDimY (3.3);
paralelepipedo.setDimZ (4.4);
cout << "O NOVO volume eh: " << paralelepipedo.getVolume () << endl;
return 0;
}