#include <iostream>
#include <pqxx/pqxx>
#include <vector>

#include "database.hh"

using namespace std;
using namespace pqxx;

Database::Database(){
   try {
      connection C("dbname = lingprog user = postgres password = abcd \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "<h3>Status: opened database " << C.dbname() << " successfully.</h3>"<< endl;
      } else {
         cout << "<h3>Can't open database" << "</h3>" <<endl;
      }
      C.disconnect ();
   } catch (const exception &e) {
      cerr << "<h3>" << e.what() << "</h3>" << endl;
   }
}

bool Database::writeData(string title, string url){
   connection C("dbname = lingprog user = postgres password = abcd \
      hostaddr = 127.0.0.1 port = 5432");
   work transaction{C};
   if (C.is_open()) {
      transaction.exec0(
         "INSERT INTO memes VALUES ('" + title +  "','" + url +  "');"
      );
      transaction.commit();
      C.disconnect ();
      return true;
   }
   return false;
}

vector<string> Database::searchData(){
   
}