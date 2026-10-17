#include <iostream>
#include <algorithm>
#include <sstream>

#include "book.h" 

//Constructor
using namespace std;
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { isAvailable = available; }
void Book::setBorrowerId(const string& id) { borrowerId = id; }

//Checkout
void Book::checkOut(const string& borrowerId) {
    if (isAvailable) {
        isAvailable = false;
        this->borrowerId = borrowerId;
    } else {
        cout << "Le livre est déjà emprunté" << endl;
    }
}

//ReturnBook
void Book::returnBook() {
    if (!isAvailable) {
        isAvailable = true;
        borrowerId = "";
    } else {
        cout << "Le livre n'est pas emprunté" << endl;
    }
}

//ToString
string Book::toString() const {
    string result = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nDisponibilité: " + (isAvailable ? "Disponible" : "Emprunté");
    return result;
}

//ToFileFormat
string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

//FromFileFormat
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, token, '|');
    isAvailable = (token == "1");
    getline(ss, borrowerId, '|');
}
