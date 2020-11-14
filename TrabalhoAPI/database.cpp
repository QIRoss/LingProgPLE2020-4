#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include <string>

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

// ANTI SQL INJECTION FUNCTION
bool Database::invalidCharacters(string input){
   unsigned index;
   for(index=0;index<input.length();index++){
      if((input[index] == '\'')||(input[index]==';'))
         return true;
      if((input[index]=='-')&&(input[index+1]=='-'))
         return true;
   }
   return false;
}

// WRITE DATA ON POSTGRESQL
bool Database::writeData(string title, string url){
   if(invalidCharacters(title)){
      cout << "<h1>ARGUMENTO INVALIDO:ANTISQL INJECTION MODE</h1>" << endl;
      exit(1);
   }
   if(invalidCharacters(url)){
      cout << "<h1>ARGUMENTO INVALIDO:ANTISQL INJECTION MODE</h1>" << endl;
      exit(1);
   }
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

//QUERY TO POSTGRESQL
result Database::query(string title){
   if(invalidCharacters(title)){
      cout << "<h1>ARGUMENTO INVALIDO:ANTISQL INJECTION MODE</h1>" << endl;
      exit(1);
   }
   connection c{"dbname = lingprog user = postgres password = abcd \
         hostaddr = 127.0.0.1 port = 5432"};
   work transaction{c};
   result r{transaction.exec("SELECT url FROM memes WHERE title = '" + title +  "';")};
   transaction.commit();
   return r;
}