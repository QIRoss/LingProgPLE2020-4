#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

#ifndef _ARVORE_HH
#define _ARVORE_HH_         "arvore.hh"

template <class T>
class Arvore{
    public:
        Arvore(T *head);
        ~Arvore();
        T* & operator+=(const T &);
        friend ostream & operator<<(ostream &,const T &){

        }
        T* operator()(T&);
    private:

};

#endif