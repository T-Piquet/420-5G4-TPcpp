#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <string>
#include "book.h" 

using namespace std;

class LogManager {
private:
    string fileName;
public:
    // Constructeur
    LogManager(const string& fileName);

    // Methods
    bool writeLog(const string& activity, const Book& book) const;
};

#endif