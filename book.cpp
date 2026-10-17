#include <iostream> // utiliser librairies standard
#include <algorithm>
#include <sstream> // biblio de Cpp, manipuler chaînes de caractères

#include "book.h"  // utiliser librairie développée

using namespace std;

// Default constructor
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

// Parameterized constructor
Book::Book(const string& title, const string& author, const string& isbn) : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

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
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& borrowerId) { this->borrowerId = borrowerId; }

// MÉTHODES

// Check out a book
void Book::checkOut(const string& borrowerId) {
    setAvailability(false);
    setBorrowerId(borrowerId);
}

// Return a book
void Book::returnBook() {
    setAvailability(true);
    setBorrowerId("");
}

// Show me information of a book/ books
string Book::toString() const {

    string siDispo = "";

    if (isAvailable == true) {
        siDispo = "Prêt à emprunter";
    } else {
        siDispo = "Emprunté";
    }

    string result = "Titre: " + title 
        + "\nAuteur: " + author 
        + "\nISBN: " + isbn 
        + "\nDisponibilité: " + siDispo 
        + "\nEmprunté par : " + borrowerId;

    return result;
}

// Export : Format for file storage
string Book::toFileFormat() const {
     string siDispo = "";

    if (isAvailable == true) {
        siDispo = "Prêt à emprunter";
    } else {
        siDispo = "Emprunté";
    }

    string result = title + "|" 
        + author + "|" 
        + isbn + "|" 
        + siDispo + "|"  
        + borrowerId;

    return result;
}


// Import book information from a file format
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availabilityStr;
    
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availabilityStr, '|');
    getline(ss, borrowerId, '|');

    if (availabilityStr == "Emprunté") {
        isAvailable = false;
    } else {
        isAvailable = true;
    }
}