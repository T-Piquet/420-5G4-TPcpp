#include <sstream>
#include <iostream>

#include "book.h"

using namespace std;

Book::Book(){}
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn){}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerId() const {
    return borrowerId;
}

void Book::setTitle(const string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const string& newAuthor) {
    author = newAuthor;
}

void Book::setISBN(const string& newIsbn) {
    isbn = newIsbn;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

void Book::setBorrowerId(const string& id) {
    borrowerId = id;
}

void Book::returnBook() {
    setAvailability(true);
    setBorrowerId("");
}

void Book::checkOut(const string& borrowerId) {
    setAvailability(false);
    setBorrowerId(borrowerId);
}

string Book::toString() const {
    return "Titre : " + title + "\nAuteur : " + author + "\nDisponible : Oui";
}

string Book::toString(const string& borrowerName) const {
    return "Titre : " + title + "\nAuteur : " + author + "\nDisponible : Non" + "\nNom de l'emprunteur : " + borrowerName;
}

string Book::toFileFormat() const {
    string available;
    string result;
    if(isAvailable) {
        result = title + "|" + author + "|" + isbn + "|" + "1" + "|";
    }else {
        result = title + "|" + author + "|" + isbn + "|" + "0" + "|" + borrowerId;
    }
    
    return result;
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    string available;
    getline(ss, available, '|');
    getline(ss, borrowerId, '|');

    if(available == "1") {
        isAvailable = true;
    } else {
        isAvailable = false;
    }
}