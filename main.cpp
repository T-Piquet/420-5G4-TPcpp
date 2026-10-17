#include <iostream>
#include <limits>
#include <string>
#include <filesystem>

#include "library.h"
#include "filemanager.h"
#include "log.h"

using namespace std;

void clearScreen() {
    system("cls || clear");
}

void pauseForInput() {
    cout << "\nAppuyez sur Entrée pour continuer...";
    cin.ignore();
    cin.get();
}

void displayMenu() {
    cout << "\n=== SYSTÈME DE GESTION DE BIBLIOTHÈQUE PERSONNELLE ===\n";
    cout << "1.  Ajouter un Livre\n";
    cout << "2.  Supprimer un Livre\n";
    cout << "3.  Rechercher des Livres par Titre\n";
    cout << "4.  Rechercher des Livres par Auteur\n";
    cout << "5.  Afficher Tous les Livres\n";
    cout << "6.  Afficher les Livres Disponibles\n";
    cout << "7.  Ajouter un Utilisateur\n";
    cout << "8.  Afficher Tous les Utilisateurs\n";
    cout << "9.  Emprunter un Livre\n";
    cout << "10. Retourner un Livre\n";
    cout << "11. Statistiques de la Bibliothèque\n";
    cout << "12. Sauvegarder les Données\n";
    cout << "13. Créer une Sauvegarde\n";
    cout << "0.  Quitter\n";
    cout << "======================================================\n";
    cout << "Entrez votre choix : ";
}

string getInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void printUsage(const char* programName) {
    cerr << "Usage: " << programName << " [--data-dir|-d <répertoire>]\n";
}

int main(int argc, char* argv[]) {
    string dataDir;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--data-dir" || arg == "-d") {
            if (i + 1 >= argc) {
                cerr << "Erreur : " << arg << " nécessite un répertoire.\n";
                printUsage(argv[0]);
                return 1;
            }
            dataDir = argv[++i];
        } else {
            cerr << "Erreur : argument inconnu '" << arg << "'.\n";
            printUsage(argv[0]);
            return 1;
        }
    }

    string booksFile;
    string usersFile;
    if (!dataDir.empty()) {
        if (!filesystem::is_directory(dataDir)) {
            cerr << "Erreur : le répertoire " << dataDir << " n'existe pas.\n";
            printUsage(argv[0]);
            return 1;
        }
        booksFile = (filesystem::path(dataDir) / "books.txt").string();
        usersFile = (filesystem::path(dataDir) / "users.txt").string();
    }

    Library library;
    FileManager fileManager(booksFile, usersFile);
    Log log("../librarylogs.txt"); // Si existe pas, va créer fichier
    vector<string> message;
    
    // Load existing data
    cout << "Chargement des données de la bibliothèque...\n";
    fileManager.loadLibraryData(library);
    
    int choice;
    bool running = true;
    
    while (running) {
        message.clear();
        
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Saisie invalide. Veuillez entrer un nombre.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pauseForInput();
            continue;
        }
        cin.ignore(); // Clear newline from buffer
        
        switch (choice) {
            case 1: { // Add Book
                string title = getInput("Entrez le titre du livre : ");
                string author = getInput("Entrez l'auteur du livre : ");
                string isbn = getInput("Entrez l'ISBN du livre : ");
                
                if (library.findBookByISBN(isbn)) {
                    cout << "Erreur : Un livre avec l'ISBN " << isbn << " existe déjà.\n";
                } else {
                    Book newBook(title, author, isbn);
                    library.addBook(newBook);
                    cout << "Livre ajouté avec succès !\n";
                }
                pauseForInput();

                message.push_back(title);
                message.push_back(author);
                message.push_back(isbn);
                
                log.saveToFileLogs(AJOUT_LIVRE, message);
                break;
            }
            
            case 2: { // Remove Book
                string isbn = getInput("Entrez l'ISBN du livre à supprimer : ");
                
                if (library.removeBook(isbn)) {
                    cout << "Livre supprimé avec succès !\n";
                } else {
                    cout << "Livre non trouvé.\n";
                }
                pauseForInput();

                message.push_back(isbn);
                
                log.saveToFileLogs(SUPPRIMER_LIVRE, message);
                break;
            }
            
            case 3: { // Search by Title
                string title = getInput("Entrez le titre à rechercher : ");
                auto results = library.searchBooksByTitle(title);
                
                if (results.empty()) {
                    cout << "Aucun livre trouvé avec ce titre.\n";
                } else {
                    cout << "\n=== RÉSULTATS DE RECHERCHE ===\n";
                    for (size_t i = 0; i < results.size(); ++i) {
                        cout << "\nRésultat " << (i + 1) << " :\n";
                        cout << results[i]->toString() << "\n";
                        cout << "-----------------------------\n";
                    }
                }
                pauseForInput();

                message.push_back(title);
                
                log.saveToFileLogs(RECH_LIVRE_TITRE, message);
                break;
            }
            
            case 4: { // Search by Author
                string author = getInput("Entrez l'auteur à rechercher : ");
                auto results = library.searchBooksByAuthor(author);
                
                if (results.empty()) {
                    cout << "Aucun livre trouvé de cet auteur.\n";
                } else {
                    cout << "\n=== RÉSULTATS DE RECHERCHE ===\n";
                    for (size_t i = 0; i < results.size(); ++i) {
                        cout << "\nRésultat " << (i + 1) << " :\n";
                        cout << results[i]->toString() << "\n";
                        cout << "-----------------------------\n";
                    }
                }
                pauseForInput();

                message.push_back(author);
                
                log.saveToFileLogs(RECH_LIVRE_AUTEUR, message);
                break;
            }
            
            case 5: // Display All Books
                library.displayAllBooks();
                pauseForInput();
                log.saveToFileLogs(AFFICHAGE_LIVRES, message);
                break;
            
            case 6: // Display Available Books
                library.displayAvailableBooks();
                pauseForInput();
                
                log.saveToFileLogs(AFFICHAGE_LIVRES_DISPO, message);
                break;
            
            case 7: { // Add User
                string name = getInput("Entrez le nom de l'utilisateur : ");
                
                User newUser(name);
                bool siValider = library.addUser(newUser);

                 if (siValider) {
                    cout << "Utilisateur ajouté avec succès !\n";
                    message.push_back(newUser.getName());
                    message.push_back(newUser.getUserId());
                    message.push_back(to_string(newUser.getBorrowedBooks().size()));
                
                } else {
                     cout << "Erreur : Un utilisateur avec le même ID existe déjà.\n";
                     message.push_back("Erreur : Un utilisateur avec le même ID existe déjà.");
                }

                pauseForInput();
                
                log.saveToFileLogs(AJOUT_USER, message);
                break;
            }
            
            case 8: // Display All Users
                library.displayAllUsers();
                pauseForInput();

                log.saveToFileLogs(AFFICHAGE_USERS, message);
                break;
            
            case 9: { // Check Out Book
                string isbn = getInput("Entrez l'ISBN du livre à emprunter : ");
                string userId = getInput("Entrez l'ID de l'utilisateur : ");
                
                if (library.checkOutBook(isbn, userId)) {
                    cout << "Livre emprunté avec succès !\n";
                } else {
                    cout << "Erreur : Impossible d'emprunter le livre. Vérifiez l'ISBN, l'ID utilisateur et la disponibilité du livre.\n";
                }
                pauseForInput();

                message.push_back(isbn);
                message.push_back(userId);

                log.saveToFileLogs(EMPRUNT, message);
                break;
            }
            
            case 10: { // Return Book
                string isbn = getInput("Entrez l'ISBN du livre à retourner : ");
                
                if (library.returnBook(isbn)) {
                    cout << "Livre retourné avec succès !\n";
                } else {
                    cout << "Erreur : Impossible de retourner le livre. Vérifiez l'ISBN et que le livre est bien emprunté.\n";
                }
                pauseForInput();

                message.push_back(isbn);

                log.saveToFileLogs(RETOUR, message);
                break;
            }
            
            case 11: { // Library Statistics
                cout << "\n=== STATISTIQUES DE LA BIBLIOTHÈQUE ===\n";
                cout << "Total des Livres : " << library.getTotalBooks() << "\n";
                cout << "Livres Disponibles : " << library.getAvailableBookCount() << "\n";
                cout << "Livres Empruntés : " << library.getCheckedOutBookCount() << "\n";
                cout << "Total des Utilisateurs : " << library.getAllUsers().size() << "\n";
                pauseForInput();

                log.saveToFileLogs(STATISTIQUES, message);
                break;
            }
            
            case 12: { // Save Data
                if (fileManager.saveLibraryData(library)) {
                    cout << "Données de la bibliothèque sauvegardées avec succès !\n";
                    message.push_back("Données de la bibliothèque sauvegardées avec succès !");
                } else {
                    cout << "Erreur lors de la sauvegarde des données de la bibliothèque.\n";
                    message.push_back("Erreur lors de la sauvegarde des données de la bibliothèque.");
                }
                pauseForInput();

                log.saveToFileLogs(SAUVEGARDER, message);
                break;
            }
            
            case 13: { // Create Backup
                fileManager.createBackup();
                pauseForInput();
                log.saveToFileLogs(CREATE_BACKUP, message);
                break;
            }
            
            case 0: // Exit
                cout << "Sauvegarde des données avant la fermeture...\n";
                fileManager.saveLibraryData(library);
                cout << "Merci d'avoir utilisé le Système de Gestion de Bibliothèque Personnelle !\n";
                running = false;
                log.saveToFileLogs(QUITTER, message);
                break;
            
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
                pauseForInput();
                log.saveToFileLogs(CHOIX_INVALIDE, message);
                break;
        }
    }
    
    return 0;
}