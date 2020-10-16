#include <iostream>

#include "forca.hh"

using namespace std;
    int main() {
    Forca forca (5);
    forca.configure ();
    while (forca.teste());
    return 0;
}