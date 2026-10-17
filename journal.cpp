#include "journal.h"
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>

using namespace std;

void Journal::enregistrer(const string& action, const string& details) {
   
    filesystem::create_directories("data");

    ofstream fichierLog("data/activity.log", ios::app);
    if (fichierLog.is_open()) {
        auto now = chrono::system_clock::now();
        auto in_time_t = chrono::system_clock::to_time_t(now);

        fichierLog << put_time(localtime(&in_time_t), "%Y-%m-%d %H:%M:%S") 
                   << " - [" << action << "] " << details << "\n";
    }
}