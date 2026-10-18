#include <fstream>
#include <iomanip>
#include <ctime>
#include <iostream>

#include "journal.h"

using namespace std;

//constructeur
Journal::Journal(const string& logFile) : logFileName(logFile) {}

//Méthodes
void Journal::log(const string& action, const string& details) {
    if(logFileName.empty()) {
        return;
    }

    ofstream file(logFileName, ios::app);
    if(!file.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier de journalisation " << logFileName << " pour l'écriture.\n";
        return;
    }

    time_t now = time(nullptr);
    file << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << " - [" << action << "] " << details << "\n";
    file.close();
}