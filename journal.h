#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>

using namespace std;

class Journal {
public:
    static void enregistrer(const string& action, const string& details);
};

#endif