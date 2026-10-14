#include "book.h"
#include <iostream>
#include <sstream>

//Constructeur par defaut
Book::Book() : title(""), author(""), isAvailable(true), borrowerId(""){

}

//Constructeur avec parametre
Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {

}

//Getters
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

std::string Book::getBorrowerId() const {
    return borrowerId;
}

//Setters
void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setISBN(const std::string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool available) {
    this->isAvailable = available;
}

void Book::setBorrowerId(const std::string& id) {
    this->borrowerId = id;
}

//methode pour emprunter un livre
void Book::checkOut(const std::string& borrowerId) {
    if (isAvailable)
    {
        this->isAvailable = false;
        this->borrowerId = borrowerId;
    }
}

//methode pour retourner un livre
void Book::returnBook() {
    this->isAvailable = true;
    this->borrowerId = "";
}

//methode daffichage
std::string Book::toString() const {
    std::string result = "Titre: " + title +
                         "\nAuteur: " + author +
                         "\nISBN: " + isbn;

    if (isAvailable) {
        result += "\nDisponible: Oui";
    } else {
        result += "\nDisponible: Non";
        result += "\nEmprunteur: " + borrowerId;
    }

    return result;
}

//conversion du livre en format fichier
std::string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

//lecture d'un livre depuis une ligne du fichier
void Book::fromFileFormat(const std::string& line) {
    std::stringstream ss(line);
    std::string available;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, available, '|');
    getline(ss, borrowerId, '|');

    isAvailable = (available == "1");
}