#include "book.h"
#include "user.h"
#include "library.h"
#include <iostream>

// Constructeur par défaut
Book::Book() : title(""), author(""), isbn("") {};

// Constructeur avec paramètre
Book::Book(const string& title, const string& author, const string& isbn) : title(title), author(author), isbn(isbn) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->isAvailable = true;
}

// Getters
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

// Setters
void Book::setTitle(const string& title) {
    this->title = title;
}
void Book::setAuthor(const string& author) {
    this->author = author;
}
void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}
void Book::setAvailability(bool availability) {
    this->isAvailable = availability;
}
void Book::setBorrowerId(const string& borrowerId) {
    this->borrowerId = borrowerId;
}

// Méthodes
void Book::checkOut(const string& borrowerId) {
    // TODO
}
void Book::returnBook() {
    this->setAvailability(true);
}
string Book::toString(const Library& library) const {
    // If unavailable
    bool borrowed = this->borrowerId.length() > 0;
    // BorrowedUser
    User* borrowedUser = library.findUserById(borrowerId);

    return 
        this->getTitle() + " | " + 
        this->getAuthor() + " | " + 
        this->getISBN() + " | " + 
        (this->isAvailable ? "Available" : "Unavailable") + 
        // Afficher le nom d'utilisateur
        (borrowed ? " | " + borrowedUser->getName() : "");
}
string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}
void Book::fromFileFormat(const string& line) {
    // Attributs objets
    string att[5];
    // Position attributs
    int posAtt = 0;
    // Loop attributs
    for (int i = 0; i < 5; ++i) {
        // Trouver |
		int endPos = line.find('|', posAtt);
        // Ajout substring pour attribut
		att[i] = line.substr(posAtt, endPos - posAtt);
		posAtt = endPos + 1;
	}
    // Stocker attributs from file
	title = att[0];
	author = att[1];
	isbn = att[2];
	isAvailable = (att[3] == "1");
	borrowerId = att[4];
}