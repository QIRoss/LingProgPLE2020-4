#include <iostream>
#include <pqxx/pqxx> 

#include <vector>

using namespace std;
using namespace pqxx;

class Database {
    public:
        Database();
        vector<string> searchData();
        bool writeData(string, string);
    private:
};