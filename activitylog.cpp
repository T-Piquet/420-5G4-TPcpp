#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "activitylog.h"

using namespace std;

ActivityLog::ActivityLog(const string& fileName) : fileName(fileName) {}

string ActivityLog::currentTimestamp() {
    time_t now = time(nullptr);
    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif
    ostringstream out;
    out << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return out.str();
}

bool ActivityLog::log(const string& action, const Book& book, const string& userName) {
    string details = book.getTitle() + "|" + book.getAuthor() + "|" + book.getISBN() + "|" +
                     (book.getAvailability() ? "1" : "0") + "|" + userName;
    return logMessage(action, details);
}

bool ActivityLog::logMessage(const string& action, const string& details) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cerr << "Avertissement : impossible d'écrire dans le journal " << fileName << ".\n";
        return false;
    }
    file << currentTimestamp() << " - [" << action << "] " << details << "\n";
    return true;
}