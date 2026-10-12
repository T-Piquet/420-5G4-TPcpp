#include <iostream>
#include <algorithm>
#include <sstream>
#include "book.h"

using namespace std;

// Constructor
Book::Book() {}
Book::Book(const string& title, const string& author, const string& isbn) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
};

    string Book::getTitle() const {return title;}
    string Book::getAuthor() const {return author;}
    string Book::getISBN() const {return isbn;}
    bool Book::getAvailability() const {return isAvailable;}
    string Book::getBorrowerId() const {return borrowerId;}

    // Setters
    void Book::setTitle(const string& title){this->title = title;}
    void Book::setAuthor(const string& author){this->author = author;}
    void Book::setISBN(const string& isbn){this->isbn = isbn;}
    void Book::setAvailability(bool available) {this->isAvailable = available;}
    void Book::setBorrowerId(const string& id) {this->borrowerId = id;}

    // Methods
    void Book::checkOut(const string& borrowerId) {
        setAvailability(false);
        setBorrowerId(borrowerId);
    };
    void Book::returnBook() {
        setAvailability(true);
        setBorrowerId("");
    };
    string Book::toString() const {
        string available;
        if (isAvailable) {
            available = "Oui";
        } else {
            available = "Non";
        }
        return "Titre: " + title + "\nAuteur: " + author +
             "\nISBN: " + isbn + "\nDisponible: " + available;
    };
    string Book::toFileFormat() const {
        return title + "|" + author +
             "|" + isbn + "|" + to_string(isAvailable) + "|" + borrowerId;
    };
    void Book::fromFileFormat(const string& line) {
        stringstream ss(line);
        string availableStr;
        
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, isbn, '|');
        getline(ss, availableStr, '|');
        getline(ss, borrowerId, '|');
        this->isAvailable = availableStr == "1";

        borrowerId.erase(
            remove(borrowerId.begin(), borrowerId.end(), '\r'),
            borrowerId.end()
        );
    };