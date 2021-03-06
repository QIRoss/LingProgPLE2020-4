#include <iostream>
#include <fstream>
#include <vector>
#include <string>
 
using namespace std;

vector<string> ufs = {
        "AC","AL","AM","AP","BA","CE","DF","ES","GO",
        "MA","MG","MS","MT","PA","PB","PE","PI","PR",
        "RJ","RN","RO","RR","RS","SC","SE","SP","TO"
    };

int 
*estadualDeaths(string initialData, string finalData, string uf){
    int* r = new int[2];
    ifstream csvFile;
    vector<string> line(3);
    csvFile.open("covid.csv");
    unsigned long deaths = 0;
    unsigned totalDays = 0;
    unsigned firstDeath = 0;
    
    while (csvFile.good()) {
        getline(csvFile, line[0], ',');
        getline(csvFile, line[1], ',');
        getline(csvFile, line[2], '\n');
        if((line[0] > initialData) && (line[0] < finalData)){                                    
            if(line[1] == uf){
                if(firstDeath > 0){
                    totalDays++;
                }
                if(line[2] != ""){
                    firstDeath++;
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

int
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

    // cout 
    // << "Estado: " << uf << endl << endl
    // << "Período de " << initialDate << " a " << finalDate << endl
    // << "Numero total de dias foi: " << totalDays << endl
    // << "Media de mortes é: " << media << endl
    // << "Numero total de mortes é: " << deaths << endl << endl
    // << "Período de " << initialDateLinha << " a " << finalDateLinha << endl
    // << "Numero total de dias foi: " << totalDaysLinha << endl
    // << "Media de mortes é: " << mediaLinha << endl
    // << "Numero total de mortes é: " << deathsLinha << endl << endl
    // << "Diferença de percentual entre os períodos: " << deathRate << "%"<< endl;

    return deathRate;
}


vector<int>
calcAllPercentages(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
    unsigned index=0;
    vector<int> percents(27);
    for (index=0;index<ufs.size();index++){
        percents[index] = deathRate(initialDate,finalDate,initialDateLinha,finalDateLinha,ufs[index]);
    }
    return percents;
}

vector<string>
allStatus(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
    vector<string> showStatus(27);
    vector<int> percents = calcAllPercentages(initialDate,finalDate,initialDateLinha, finalDateLinha);
    unsigned index;
    for (index=0;index<ufs.size();index++){
        if(percents[index] < -15){
            showStatus[index] = "BAIXA";
        } else if(percents[index] > 15){
            showStatus[index] = "ALTA";
        } else {
            showStatus[index] = "ESTÁVEL";
        }
    }
    return showStatus;
}

void
brazilStatus(string initialDate,string finalDate, string initialDateLinha, string finalDateLinha){
    float deaths=0;
    float deathsLinha=0;
    int *results;
    float index;
    float totalDays = 0;
    float totalDaysLinha = 0;
    float media;
    float mediaLinha;
    for(index=0;index<ufs.size();index++){
        results = estadualDeaths(initialDate,finalDate, ufs[index]);
        deaths+=results[0];
        totalDays=results[1];
    }
    for(index=0;index<ufs.size();index++){
        results = estadualDeaths(initialDateLinha,finalDateLinha, ufs[index]);
        deathsLinha+=results[0];
        totalDaysLinha=results[1];
    }
    media = deaths/totalDays;
    mediaLinha = deathsLinha/totalDaysLinha;
    float rate = (mediaLinha/media)*100 - 100;
    string status;
    if (rate > 15){
        status = "ALTA";
    } else if (rate < -15){
        status = "BAIXA";
    } else {
        status = "ESTÁVEL";
    }

    cout << endl << "Mortes no Brasil ate de " <<initialDate<< " a " << finalDate << ": " << deaths << endl
    << "Dias: " << totalDays << endl
    << "Media: " << deaths/totalDays << endl
    << "Mortes no Brasil ate de " <<initialDateLinha<< " a " << finalDateLinha 
    << ": " << deathsLinha << endl
    << "Dias: " << totalDaysLinha << endl
    << "Media: " << deathsLinha/totalDaysLinha << endl
    << "Variação: " << rate << "%" << endl
    << "Status: " << status << endl;
}

void higherAndLower(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
    vector<int> percents = calcAllPercentages(initialDate,finalDate, initialDateLinha, finalDateLinha);
    int index=0;
    int higher=percents[0];
    int higherIndex=0;
    int lowerIndex=0;
    int lower=percents[0];
    for(index=1;index<ufs.size();index++){
        if(percents[index] > higher){
            higher = percents[index];
            higherIndex = index;
        }
        if(percents[index] < lower){
            lower = percents[index];
            lowerIndex = index;
        }
    }
    cout << "Estado com maior aumento é " << ufs[higherIndex] << " com " << higher << "% de aumento" << endl << "Estado com maior baixa é " << ufs[lowerIndex] << " com " << lower << "% de aumento" << endl;
}

void
printedDeathRates(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha, string uf){
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
}

int
main(int argc,char *argv[]){
    unsigned index;
    vector<string> status = allStatus("2020-07-07","2020-08-07","2020-08-07","2020-09-07");
    vector<int> percents = calcAllPercentages("2020-07-07","2020-08-07","2020-08-07","2020-09-07");
    for(index=0;index<ufs.size();index++){
        cout << ufs[index] << "\t" << percents[index] << "%\t" << status[index] << endl;
    }
    brazilStatus("2020-07-07","2020-08-07","2020-08-07","2020-09-07");
    higherAndLower("2020-07-07","2020-08-07","2020-08-07","2020-09-07");
    return 0;
}