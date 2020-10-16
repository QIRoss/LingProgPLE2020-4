#include <string>
#include <vector>

using namespace std;

#ifndef _nacional_hh
#define _nacional_hh    "nacional.hh"


class Nacional {
    public:
        vector<string> ufs = {
        "AC","AL","AM","AP","BA","CE","DF","ES","GO",
        "MA","MG","MS","MT","PA","PB","PE","PI","PR",
        "RJ","RN","RO","RR","RS","SC","SE","SP","TO"
    };
        vector<int> calcAllPercentages(string , string , string , string);
        vector<string> allStatus(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha);
        void brazilStatus(string initialDate,string finalDate, string initialDateLinha, string finalDateLinha);
        void higherAndLower(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha);
        void accumulatedData(string initialDate,string finalDate, string initialDateLinha, string finalDateLinha);
        void printAllEstados(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha);
};


#endif