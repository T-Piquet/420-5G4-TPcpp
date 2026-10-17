#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <string>
#include "book.h"

using namespace std;

class ActivityLog {
private:
    string fileName;
    static string currentTimestamp();

public:
    explicit ActivityLog(const string& fileName);
    bool log(const string& action, const Book& book, const string& userName = "");
    bool logMessage(const string& action, const string& details);
};

#endif