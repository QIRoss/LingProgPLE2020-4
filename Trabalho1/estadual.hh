#include <string>
using namespace std;

#ifndef _estadual_hh
#define _estadual_hh    "estadual.hh"
 
class Estadual {
    public:
        Estadual(string);


    private:
        string uf;
        int *estadualDeaths(string , string , string);
        int deathRate(string , string , string , string , string );

        friend class Nacional;
};


#endif