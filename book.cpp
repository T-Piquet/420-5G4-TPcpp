#include <iostream>
#include <sstream>
#include <algorithm>

#include "book.h"

using namespace std;

//Constructor
Book::Book() : isAvailable(true), borrowerId("") {}
Book::Book(const string& title, const string& author, const string& isbn) 
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

//Getters
string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
string Book::getBorrowerId() const {return borrowerId;}

//Setters
void Book::setTitle(const string& title) {this->title = title;}
void Book::setAuthor(const string& author) {this->author = author;}
void Book::setISBN(const string& isbn) {this->isbn = isbn;}
void Book::setAvailability(bool available) {this->isAvailable = available;}
void Book::setBorrowerId(const string& id) {this->borrowerId = id;}

//Methods
void Book::checkOut(const string& borrowerId) {
    if (isAvailable) {
        this->borrowerId = borrowerId;
        isAvailable = false;
    } 
    return;
}


void Book::returnBook() {
    if (!isAvailable && borrowerId != "") {
        isAvailable = true;
        borrowerId = "";
    }
    return;
}


string Book::toString(const string& borrowerName) const {
    string result = "Titre : " + title + "\n"
    + "Auteur : " + author + "\n"
    + "ISBN : " + isbn + "\n"
    + "Statut : " + (isAvailable ? "Disponible" : "Emprunté");
    if (!isAvailable) {
        result += "\nEmprunté par : " + (borrowerName.empty() ? borrowerId : borrowerName);
    }

    return result;
}


string Book::toFileFormat() const {
    string result = title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
    return result;
}


void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availability;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availability, '|');

    borrowerId = "";
    getline(ss, borrowerId);

    if (availability == "1")
    {
        isAvailable = true;
    } else {
        isAvailable = false;
    }
    
}