#include <iostream>
#include <sstream>
#include "book.h"

using namespace std;

// Constructeur par defaut
Book::Book()
    : isAvailable(true) {}

// Constructeur avec params
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn) {}

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
void Book::setBorrowerId(const string& id) { this->borrowerId = borrowerId; }

// Methodes

void Book::checkOut(const string& borrowerId) {
    setAvailability(false);
    setBorrowerId(borrowerId);
}

void Book::returnBook() {
    setAvailability(true);
    setBorrowerId("");
}

string Book::toString() const {
    return "Titre : " + title + "\nAuteur : " + author + 
    "\nISBN : " + isbn + "\nDisonible : " + (isAvailable ? "Oui" : "Non");
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + getBorrowerId();
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availStr;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availStr, '|');
    getline(ss, borrowerId, '|');

    isAvailable = (availStr == "1");
}