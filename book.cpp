#include "book.h"
#include <sstream>

using namespace std;


Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}


Book::Book(const string& title, const string& author, const string& isbn) 
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}


string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }


void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& id) { this->borrowerId = id; }


void Book::checkOut(const string& borrower) {
    if (isAvailable) {
        isAvailable = false;
        borrowerId = borrower;
    }
}


void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}


string Book::toString() const {
    string availability = isAvailable ? "Disponible" : "Emprunté par " + borrowerId;
    return "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nStatut: " + availability + "\n" + "maketest";
}


string Book::toFileFormat() const {
    string result = title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|";
    result += borrowerId;
    return result;
}


void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availability;
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availability, '|');
    isAvailable = (availability == "1");
    getline(ss, borrowerId);
}