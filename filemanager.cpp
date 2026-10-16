#include <fstream>
#include <iostream>
#include <filesystem>
#include "filemanager.h"

using namespace std;

// Constructor
FileManager::FileManager(const string& booksFile, const string& usersFile, const string& journalFile)
    : booksFileName(booksFile), usersFileName(usersFile), journalFileName(journalFile) {}

// Save all library data
bool FileManager::saveLibraryData(Library& library) {
    return saveBooksToFile(library) && saveUsersToFile(library);
}

// Load all library data
bool FileManager::loadLibraryData(Library& library) {
    bool booksLoaded = loadBooksFromFile(library);
    bool usersLoaded = loadUsersFromFile(library);
    return booksLoaded || usersLoaded; // Return true if at least one file was loaded
}

// Save books to file
bool FileManager::saveBooksToFile(Library& library) {
    ofstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Impossible d'ouvrir " << booksFileName << " écriture vers tempBooks.txt\n";
        ofstream file1;
        file1.open("tempBooks.txt");
        if (!file1.is_open()) {
            cout << "Erreur : Sauvegarde na pas marcher\n";
            return false;
        }
        auto books = library.getAllBooks();
        for (Book* book : books) {
            file1 << book->toFileFormat() << "\n";
        }
    
        file1.close();
        return true;
    }
    
    auto books = library.getAllBooks();
    for (Book* book : books) {
        file << book->toFileFormat() << "\n";
    }
    
    file.close();
    return true;
}

// Save users to file
bool FileManager::saveUsersToFile(Library& library) {
    ofstream file(usersFileName);
    if (!file.is_open()) {
        cout << "Impossible d'ouvrir " << usersFileName << " écriture vers tempUsers.txt\n";
        ofstream file1;
        file1.open("tempUsers.txt");
        if (!file1.is_open()) {
            cout << "Erreur : Sauvegarde na pas marcher\n";
            return false;
        }
        auto users = library.getAllUsers();
        for (User* user : users) {
            file1 << user->toFileFormat() << "\n";
        }
        
        file1.close();
        return true;
    }
    
    auto users = library.getAllUsers();
    for (User* user : users) {
        file << user->toFileFormat() << "\n";
    }
    
    file.close();
    return true;
}

// Load books from file
bool FileManager::loadBooksFromFile(Library& library) {
    ifstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier de livres existant trouvé. Démarrage avec une bibliothèque vide.\n";
        return false;
    }
    
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            Book book;
            book.fromFileFormat(line);
            library.addBook(book);
            count++;
        }
    }
    
    file.close();
    cout << "Chargé " << count << " livre(s) depuis le fichier.\n";
    return true;
}

// Load users from file
bool FileManager::loadUsersFromFile(Library& library) {
    ifstream file(usersFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier d'utilisateurs existant trouvé. Démarrage sans utilisateurs enregistrés.\n";
        return false;
    }
    
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            User user;
            user.fromFileFormat(line);
            library.addUser(user);
            count++;
        }
    }
    
    file.close();
    cout << "Chargé " << count << " utilisateur(s) depuis le fichier.\n";
    return true;
}

// Check if file exists
bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

// Create backup
void FileManager::createBackup() {
    if (fileExists(booksFileName)) {
        filesystem::copy_file(booksFileName, booksFileName + ".backup");
    }
    
    if (fileExists(usersFileName)) {
        filesystem::copy_file(usersFileName, usersFileName + ".backup");
    }
    
    cout << "Fichiers de sauvegarde créés.\n";
}

void FileManager::journalAdd(string message){
    ifstream fileL(journalFileName);
    if (!fileL.is_open()) {
        cout << "Impossible d'ouvrir " << journalFileName << " écriture vers tempJournal.txt\n";
        ifstream file1;
        file1.open("tempJournal.txt");
        if (!file1.is_open()) {
            cout << "Erreur : Saugarde de journal impossible.\n";
        }
        string line;
        int count = 0;
        while (getline(file1, line)) {
            if (!line.empty()) {
                message += "\n" + line;
                count++;
            }
        }
        file1.close();
    }else{
        string line;
        int count = 0;
        while (getline(fileL, line)) {
            if (!line.empty()) {
                message += "\n" + line;
                count++;
            }
        }
        fileL.close();
    }
    
    
    ofstream fileE(journalFileName);
    if (!fileE.is_open()) {
        cout << "Impossible d'ouvrir " << journalFileName << " écriture vers tempJournal.txt\n";
        ofstream file1;
        file1.open("tempJournal.txt");
        if (!file1.is_open()) {
            cout << "Erreur : Saugarde de journal impossible.\n";
        }
        file1 << message;
        file1.close();
    }else{
        fileE << message;
        fileE.close();
    }
    
    
}