#include "journal.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// Constructeur
Journal::Journal(const string& filePath) : filePath(filePath) {
    // Creer le fichier s'il n'existe pas
    ofstream fichier(filePath, ios::app);

    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le journal.\n";
    }
}

// Enregistrer une activite
void Journal::enregistrer(const string& action, const string& details) {
    ofstream fichier(filePath, ios::app);

    if (!fichier) {
        cerr << "Erreur : impossible d'ecrire dans le journal.\n";
        return;
    }

    time_t maintenant = time(nullptr);
    tm* date = localtime(&maintenant);

    fichier << put_time(date, "%Y-%m-%d %H:%M:%S")
            << " - [" << action << "] "
            << details << "\n";
}