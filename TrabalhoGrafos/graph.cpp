#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "graph.hh"
#include "node.hh"
using namespace std;

void Graph::getIncidencyList(string filename, unsigned short n){
    fstream file; 
    string word;
    string words;
    vector<Node> incidencyList;
    vector<string> queue;
    file.open(filename.c_str());
    unsigned i,j,k= 0;
    unsigned length;
    bool choice = false;
    bool lastWord = false;

    if(n==1){
        while (file >> word) {
            choice = false;
            word[0] = tolower(word[0]);
            length = word.length();
            if(word[length-1] == '.' || word[length-1] == ','){
                word.pop_back();
            }

            // begin check list
            for(j=0;j<incidencyList.size();j++){
                if(incidencyList[j].word == word){
                    incidencyList[j].count++;
                    choice = true;
                }
            }
            if (choice == false){
                Node toBeAdd;
                toBeAdd.word = word;
                toBeAdd.count = 1;
                incidencyList.push_back(toBeAdd);
            }
            // end check list 
        }
        for(i=0;i<incidencyList.size();i++){
            cout << incidencyList[i].word << "\t\t:" << incidencyList[i].count << endl;
        }
    } else {
        while(file>>word){
            choice = false;
            lastWord = false;
            word[0] = tolower(word[0]);
            length = word.length();

            if(word[length-1] == '.' || word[length-1] == ','){
                word.pop_back();
                lastWord = true;
            }
            queue.push_back(word);
            if(queue.size() == n){
                for(k=0;k<n;k++){
                    words = words + queue[k] + " ";
                }
                words.pop_back();
                // begin check list
                for(j=0;j<incidencyList.size();j++){
                    if(incidencyList[j].word == words){
                        incidencyList[j].count++;
                        choice = true;
                    }
                }
                if (choice == false){
                    Node toBeAdd;
                    toBeAdd.word = words;
                    toBeAdd.count = 1;
                    incidencyList.push_back(toBeAdd);
                }
                // end check list
                queue.erase(queue.begin());
            }
            if(lastWord == true){
                queue.clear();
            }
        }
        for(i=0;i<incidencyList.size();i++){
            cout << incidencyList[i].word << "\t\t:" << incidencyList[i].count << endl;
        }
    }

    file.close();
}