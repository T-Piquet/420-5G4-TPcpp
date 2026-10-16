#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "book.h"

using namespace std;


Book::Book() {}

Book::Book(const string& title, const string& author, const string& isbn) 
    : title(title), author(author), isbn(isbn){}

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

void Book::checkOut(const string& borrowerId) {
    setAvailability(false);
    setBorrowerId(borrowerId);
}
void Book::returnBook(){
    setAvailability(true);
    setBorrowerId("");
}
string Book::toString() const {
    string result = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn;
    if (!isAvailable) {
        result += "\nEmprunter par: " + borrowerId;
    }
    return result;
}
string Book::toStringAvecNom(const string& name) {
    string result = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn;
    if (!isAvailable) {
        result += "\nEmprunter par: " + name;
    }
    return result;
}
string Book::toFileFormat() const {
    string result = title + "|" + author + "|" + isbn + "|";
    if (isAvailable)
    {
        return result += "1|";
    }
    return result += "0|"+ borrowerId;
    
}
void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    string available;
    getline(ss, available, '|');
    if (available == "0") {
        setAvailability(false);
        getline(ss, borrowerId, '|');
    } else {
        setAvailability(true);
    }
}

