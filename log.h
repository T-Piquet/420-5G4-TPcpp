#include <ctime> // pour date et heure
#include <fstream> // pour ofstream
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum LogAction 
{ 
    AJOUT_LIVRE, 
    SUPPRIMER_LIVRE, 
    RECH_LIVRE_TITRE,
    RECH_LIVRE_AUTEUR,
    AFFICHAGE_LIVRES,
    AFFICHAGE_LIVRES_DISPO,
    AJOUT_USER,
    AFFICHAGE_USERS,
    EMPRUNT,
    RETOUR,
    STATISTIQUES,
    SAUVEGARDER,
    CREATE_BACKUP,
    QUITTER,
    CHOIX_INVALIDE
};

class Log {
private:
    ofstream logFile;

    string actionToString(LogAction action)   
    {
        switch (action)
        {
            case AJOUT_LIVRE:
                return "AJOUT_LIVRE";

            case SUPPRIMER_LIVRE:
                return "SUPPRIMER_LIVRE";
        
            case RECH_LIVRE_TITRE:
                return "RECH_LIVRE_TITRE";
        
            case RECH_LIVRE_AUTEUR:
                return "RECH_LIVRE_AUTEUR";
        
            case AFFICHAGE_LIVRES:
                return "AFFICHAGE_LIVRES";

            case AFFICHAGE_LIVRES_DISPO:
                return "AFFICHAGE_LIVRES_DISPO";
            
            case AJOUT_USER:
                return "AJOUT_USER";

            case AFFICHAGE_USERS:
                return "AFFICHAGE_USERS";
        
            case EMPRUNT:
                return "EMPPRUNT";
            
            case RETOUR:
                return "RETOUR";
            
            case STATISTIQUES:
                return "STATISTIQUES";

            case SAUVEGARDER:
                return "SAUVEGARDER";
            
            case CREATE_BACKUP:
                return "CREATE_BACKUP";
            
            case QUITTER:
                return "QUITTER";

            case CHOIX_INVALIDE:
                return "CHOIX_INVALIDE";

            default:
                return "UNKNOWN";
        }
    }

public:
    // Default constructor
    Log();
    // Constructor: open log file in append mode
    Log(const string& filename);

    // Destructor
    ~Log();

    // Logs a message with a log action
    void saveToFileLogs(LogAction action, const vector<string>& message);

    // Format message log
    string formatMsgLog(const vector<string>& message);
};