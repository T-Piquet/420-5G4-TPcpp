#include <sstream>
#include <algorithm>

#include "book.h"
#include "user.h"
#include "library.h"

using namespace std;

// Constructeur défaut
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

// Constructeur avec paramètres
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(const bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& id) { this->borrowerId = id; }

// Check out
void Book::checkOut(const string& borrowerId) {
    setBorrowerId(borrowerId);
    setAvailability(false);
}

// Return
void Book::returnBook() {
    setBorrowerId("");
    setAvailability(true);
}

// Afficher les informations d'un livre
string Book::toString() const {
    string disponible;
    if(to_string(isAvailable) == "1"){
        disponible = "Oui";
    }else{
        disponible = "Non";
    }
    string info = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + 
                    "\nDisponible: " + disponible + "\nEmprunté par: " + borrowerId;
    
    return info;
}

string Book::toString(const User* borrower) const { //Interface et Expérience Utilisateur: Afficher le nom plutôt que l'id dans l'affichage des livres
    string disponible;
    string borrowerName = "Aucun";

    if(to_string(isAvailable) == "1"){
        disponible = "Oui";
    }else{
        disponible = "Non";
    }
    if(!borrowerId.empty()){
        borrowerName = borrower ? borrower->getName() : "Utilisateur inconnu";
    }
    string info = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + 
                    "\nDisponible: " + disponible + "\nEmprunté par: " + borrowerName;
    
    return info;
}

// Lire les textes en format fichier
string Book::toFileFormat() const {
    string fichier = title + "|" + author + "|" + isbn + "|" + to_string(getAvailability()) + "|" + borrowerId;

    return fichier;
}

// Parse from file format
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    string availableString;
    getline(ss, availableString, '|');
    isAvailable = (availableString == "1");

    getline(ss, borrowerId, '|');
    if(!borrowerId.empty() && borrowerId.back() == '\r'){
        borrowerId.pop_back();
    }
}