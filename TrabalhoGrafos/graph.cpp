#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "graph.hh"
using namespace std;

// void Graph::addWord(vector<node> list, string nodeWords){
//     node toBeAdd;
//     toBeAdd.word = nodeWords;
//     list.push_back(toBeAdd);
// }

void Graph::getIncidencyList(string filename, unsigned short n){
    fstream file; 
    string word;
    vector<node> incidencyList;
    file.open(filename.c_str());
    unsigned i,j = 0;
    bool choice = false;

    while (file >> word) {
        choice = false;
        word[0] = tolower(word[0]);
        for(j=0;j<incidencyList.size();j++){
            if(incidencyList[j].word == word){
                incidencyList[j].count++;
                choice = true;
            }
        }
        if (choice == false){
            node toBeAdd;
            toBeAdd.word = word;
            toBeAdd.count = 1;
            incidencyList.push_back(toBeAdd);
        }
    }
    for(i=0;i<incidencyList.size();i++){
        cout << incidencyList[i].word << "\t\t:" << incidencyList[i].count << endl;
    }

    file.close();
}