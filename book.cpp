#include "book.h"
#include <sstream>

// Constructors
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

Book::Book(const string& title, const string& author, const string& isbn): title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

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
void Book::setBorrowerId(const string& id) { this->borrowerId = id; }


// Methods
void Book::checkOut(const string& borrowerId) {
    this->isAvailable = false;
    this->borrowerId = borrowerId;
}

void Book::returnBook() {
    this->isAvailable = true;
    this->borrowerId = "";
}

string Book::toString() const {
    string result = "Titre : " + title + "\nAuteur : " + author + "\nISBN : " + isbn;
    result += "\nStatut : " + string(isAvailable ? "Disponible" : "Emprunté");
    if (!isAvailable) {
        result += " (Emprunté par : " + borrowerId + ")";
    }
    return result;
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
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