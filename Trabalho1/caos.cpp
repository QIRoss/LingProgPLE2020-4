#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int 
*estadualDeaths(string initialData, string finalData, string uf){
    int* r = new int[2];
    ifstream csvFile;
    vector<string> line(3);
    csvFile.open("covid.csv");
    unsigned long deaths = 0;
    unsigned totalDays = 0;
    
    while (csvFile.good()) {
        getline(csvFile, line[0], ',');
        getline(csvFile, line[1], ',');
        getline(csvFile, line[2], '\n');
        if((line[0] > initialData) && (line[0] < finalData)){                                    
            if(line[1] == uf){
                totalDays++;
                if(line[2] != ""){
                    deaths += stoul(line[2], nullptr,10);
                    // cout << line[0] << endl;
                    // cout << line[1] << endl;
                    // cout << line[2] << endl;
                }   
            }
        }
    }
    r[0]=deaths;
    r[1]=totalDays;
    csvFile.close();
    return r;
}

string
deathRate(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha, string uf){
    float deathRate = 0;
    float deaths=0;
    float totalDays=0;
    float deathsLinha=0;
    float totalDaysLinha=0;
    float media=0;
    float mediaLinha=0;
    int *results, *resultsLinha;
    results = estadualDeaths(initialDate, finalDate, uf);
    resultsLinha = estadualDeaths(initialDateLinha,finalDateLinha,uf);
    deaths = results[0];
    totalDays = results[1];
    deathsLinha = resultsLinha[0];
    totalDaysLinha = resultsLinha[1];
    media = deaths/totalDays;
    mediaLinha = deathsLinha/totalDaysLinha;
    deathRate = (mediaLinha/media)*100 - 100;
    string deathPercent = to_string(deathRate) + "%";

    cout 
    << "Estado: " << uf << endl << endl
    << "Período de " << initialDate << " a " << finalDate << endl
    << "Numero total de dias foi: " << totalDays << endl
    << "Media de mortes é: " << media << endl
    << "Numero total de mortes é: " << deaths << endl << endl
    << "Período de " << initialDateLinha << " a " << finalDateLinha << endl
    << "Numero total de dias foi: " << totalDaysLinha << endl
    << "Media de mortes é: " << mediaLinha << endl
    << "Numero total de mortes é: " << deathsLinha << endl << endl
    << "Diferença de percentual entre os períodos: " << deathRate << "%"<< endl;

    return deathPercent;
}

int
main(int argc,char *argv[]){
    
    string percent = deathRate("2020-01-01","2020-09-06","2020-01-01","2020-09-07","RJ");
    cout << "PERCENT CHECK " << percent << endl;
    return 0;
}