#include <iostream>
#include "fibonacci.h"
using namespace std;

int main (int argc, char *argv[]){
    if (argc == 1){
        cout << "Sem args de entrada" << endl;
        return 0;
    }
    unsigned int input = (unsigned int) strtoul(argv[1],NULL,10);

    cout << "Fibonacci(" << input << "):" << CalcularSerieFibonacci(input) << endl;
  
    return 0;
}