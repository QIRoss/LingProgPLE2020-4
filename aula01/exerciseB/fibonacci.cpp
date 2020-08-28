#include "fibonacci.hh"

void Fibonacci::set(int input) {
    resultado = calcular(input);
}

int Fibonacci::get() { return resultado; }

int Fibonacci::calcular(int input) { 
    if (input == 0) {
        return 0;
    }   else if(input == 1) {
            return 1;
    }   else {
            return (calcular(input-1) + calcular(input-2));
    }
}