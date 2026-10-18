#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>

using namespace std;

class Journal {
    private:
        string logFileName;

    public:
    //Constructeur
    Journal(const string& logFile);

    //Méthodes
    void log(const string& action, const string& details);
};

#endif
