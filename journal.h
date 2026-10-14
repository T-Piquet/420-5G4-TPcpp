#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>

using namespace std;

class Journal {
private:
    string filePath;

public:
    Journal(const string& filePath);
    void enregistrer(const string& action, const string& details);
};

#endif