#include <sstream>
#include <algorithm>

#include "book.h"

using namespace std;

//constructeur
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId(""){}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn) {}

//getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

//setters

void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& borrowerId) { this->borrowerId = borrowerId; }

//methodes
void Book::checkOut(const string& borrowerId) {
    isAvailable = false;
    this->borrowerId = borrowerId;
}

void Book::returnBook(){
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    string statut = isAvailable ? "Disponible" : "Emprunté";
    string resultat = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nStatut: " + statut;
    return resultat;
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availableString;
    
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availableString, '|');
    getline(ss, borrowerId, '|');

    isAvailable = (availableString == "1");
    
}