#include "logger.h"

#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

string getDateTime() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    tm* localTime = localtime(&currentTime);

    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d %H:%M:%S");

    return ss.str();
}

void ecrireJournal(const string& message) {
    ofstream fichier("journal.txt", ios::app);

    if (fichier.is_open()) {
        fichier << getDateTime()
                << " - "
                << message
                << "\n";
    }
}