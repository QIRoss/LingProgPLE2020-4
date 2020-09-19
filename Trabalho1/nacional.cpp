#include "estadual.hh"
#include "nacional.hh"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> Nacional::calcAllPercentages(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
    unsigned index=0;
    vector<int> percents(27);
    for (index=0;index<ufs.size();index++){
        Estadual estado(ufs[index]);
        percents[index] = estado.deathRate(initialDate,finalDate,initialDateLinha,finalDateLinha,ufs[index]);
    }
    return percents;
}

vector<string> Nacional::allStatus(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
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

void Nacional::brazilStatus(string initialDate,string finalDate, string initialDateLinha, string finalDateLinha){
        float deaths=0;
    float deathsLinha=0;
    int *results;
    float index;
    float totalDays = 0;
    float totalDaysLinha = 0;
    float media;
    float mediaLinha;
    for(index=0;index<ufs.size();index++){
        Estadual estado(ufs[index]);
        results = estado.estadualDeaths(initialDate,finalDate, ufs[index]);
        deaths+=results[0];
        totalDays=results[1];
    }
    for(index=0;index<ufs.size();index++){
        Estadual estado(ufs[index]);
        results = estado.estadualDeaths(initialDateLinha,finalDateLinha, ufs[index]);
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

void Nacional::higherAndLower(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
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

void Nacional::accumulatedData(string initialDate,string finalDate, string initialDateLinha, string finalDateLinha){
    unsigned index;
    vector<string> status = allStatus(initialDate ,finalDate,initialDateLinha,finalDateLinha);
    vector<int> percents = calcAllPercentages(initialDate ,finalDate,initialDateLinha,finalDateLinha);
    for(index=0;index<ufs.size();index++){
        cout << ufs[index] << "\t" << percents[index] << "%\t" << status[index] << endl;
    }
}

void Nacional::printAllEstados(string initialDate, string finalDate, string initialDateLinha, string finalDateLinha){
    unsigned index=0;
    vector<int> percents(27);
    for (index=0;index<ufs.size();index++){
        Estadual estado(ufs[index]);
        estado.printedDeathRates(initialDate,finalDate,initialDateLinha,finalDateLinha,ufs[index]);
    }
}