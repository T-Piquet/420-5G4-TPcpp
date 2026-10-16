#include "book.h"
#include <sstream>

Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {

}

Book::Book(const string& title, const string& author, const string& isbn) : title(title),
author(author), isbn(isbn), isAvailable(true), borrowerId("") {
}

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

void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

void Book::setBorrowerId(const string& borrowerId) {
    this->borrowerId = borrowerId;
}

void Book::checkOut(const string& borrowerId) {
    isAvailable = false;
    this->borrowerId = borrowerId;
}

void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    string affichage = "Title: " + title + "\nAuthor: " + author + "\nISBN: " + isbn;
    if (isAvailable) {
        affichage += " | Available";
    }else {
        affichage += " | Borrowed by : " + borrowerId;
    }
    return affichage;
}

string Book::toFileFormat() const {
    string resultat = title + "|" + author + "|" + isbn + "|";
    if (isAvailable) {
        resultat += "1";
    } else {
        resultat += "0";
    }
    resultat += "|" + borrowerId;
    return resultat;
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