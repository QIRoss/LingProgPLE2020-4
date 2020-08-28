#include "fibonacci.hh"

int
CalcularSerieFibonacci(int input){
    if (input == 0) {
        return 0;
    } else if(input == 1) {
        return 1;
    }   else {
        return (CalcularSerieFibonacci(input-1) + CalcularSerieFibonacci(input-2));
    }
}