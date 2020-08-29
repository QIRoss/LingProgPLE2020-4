#include <iostream>
#include <string>
#include "fibonacci.hh"
using namespace std;

int main (int argc, char *argv[]){
    if (argc == 1){
        cout << "Sem args de entrada" << endl;
        return 0;
    }

    unsigned int input = (unsigned int) strtoul(argv[1],NULL,10);
    Fibonacci fibonacciObj; 

    fibonacciObj.set(input);    

    cout << "Fibonacci(" << input << "):" << fibonacciObj.get() << endl;
  
    return 0;
}