#include <sstream>
#include <iostream>
#include <algorithm>

#include "book.h"

using namespace std;

// Default constructor
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

// Parameterized constructor
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn) {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string& title) { this->title = title;}
void Book::setAuthor(const string& author) { this->author = author;}
void Book::setISBN(const string& isbn) { this->isbn = isbn;}
void Book::setAvailability(bool available) { this->isAvailable = available;}
void Book::setBorrowerId(const string& id) { this->borrowerId = id;}

// Checkout a book
void Book::checkOut(const string& borrowerId) {
    if(isAvailable) {
        isAvailable = false;
        this->borrowerId = borrowerId;
    }
}

// Return a book
void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

// Display book information
string Book::toString() const {
    string bookDisplay = "Titre : " + title + "\nAuteur : " + author + 
                            "\nISBN : " + isbn;

    return bookDisplay;
}

// Format for file storage
string Book::toFileFormat() const {
    string bookFormat = title + "|" + author + "|" +
                         isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;

    return bookFormat;
}

// Parse from file format
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availBook;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availBook, '|');
    getline(ss, borrowerId);

    if(availBook == "1") {
        isAvailable = true;
    } else {
        isAvailable = false;
    }
}
