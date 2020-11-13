#include <iostream>
#include <pqxx/pqxx> 
#include <string>

#include <vector>

using namespace std;
using namespace pqxx;

class Database {
    public:
        Database();
        bool writeData(string, string);
        result query(string);
    private:
};