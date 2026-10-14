#include <fstream>
#include <iostream>
#include <filesystem>
#include <iostream>

#include "logManager.h"
#include "book.h"

// Constructeur avec paramètre
LogManager::LogManager(const string& fileName) : fileName(fileName) {}

// Méthodes
bool LogManager::writeLog(const string& activity, const Book& book) const {
    ofstream file(fileName, std::ios::app);

    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << fileName << " en écriture.\n";
        return false;
    }

    std::time_t now = std::time(nullptr);
    std::tm* tm = std::localtime(&now);

    file << std::put_time(tm, "%Y-%m-%d %H:%M:%S") << " | "
         << activity << " " << book.toFileFormat() << "\n";

    return file.good();
}