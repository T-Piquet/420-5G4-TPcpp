#include <sstream>
#include <algorithm>

#include "book.h"

using namespace std;

//constructeur par défaut
Book::Book() : title(""), author(""), isbn(""){}

//constructeur avec params
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId(""){}

//getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

//setters
void Book::setTitle(const string& title) {this->title = title;}
void Book::setAuthor(const string& author) {this->author = author;}
void Book::setISBN(const string& isbn) {this->isbn = isbn;}
void Book::setAvailability(bool available) {this->isAvailable = available;}
void Book::setBorrowerId(const string& id) {this->borrowerId = id;}

//methodes
void Book::checkOut(const string& userId) {
    isAvailable = false;
    borrowerId = userId;
}

void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    return "titre: " + title + "\n" +
    "auteur: " + author + "\n" +
    "ISBN: " + isbn + "\n";
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|";
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
}