#include "book.h"
#include "library.h"
#include <sstream>
#include <fstream>

using namespace std;

Book::Book()
    : title(""),
      author(""),
      isbn(""),
      isAvailable(true),
      borrowerId("") {
}


Book::Book(const string& title, const string& author, const string& isbn)
    : title(title),
      author(author),
      isbn(isbn),
      isAvailable(true),
      borrowerId("") {
}

string Book::getTitle() const{
    return title;
}


string Book::getAuthor() const{
    return author;
}
string Book::getISBN() const{
    return isbn;
}
bool Book::getAvailability() const{
    return isAvailable;
}
string Book::getBorrowerId() const{
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

void Book::setBorrowerId(const string& id) {
    borrowerId = id;
}


void Book::checkOut(const string& borrowerId) {
    setAvailability(false);
    setBorrowerId(borrowerId);

}

void Book::returnBook() {
    setAvailability(true);
    setBorrowerId("");
}

string Book::toString(Library& library) const {
    string result = "Titre: " + title +
                    "\nAuteur: " + author +
                    "\nISBN: " + isbn +
                    "\nDisponible: " + (isAvailable ? "Oui" : "Non");

    if (!isAvailable) {

        User* user = library.findUserById(borrowerId);

        if (user != nullptr) {
            result += "\nEmprunté par: " + user->getName();
        } else {
            result += "\nEmprunté par: UTILISATEUR INTROUVABLE";
        }
    }

    return result;
}

string Book::toFileFormat() const{
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

void Book::fromFileFormat(const string& line){
    stringstream book(line);
    string disponible;

    getline(book, title, '|');
    getline(book, author, '|');
    getline(book, isbn, '|');
    getline(book, disponible, '|');
    getline(book, borrowerId, '|');
    getline(book, borrowerId);

if (!borrowerId.empty() && borrowerId.back() == '\r') {
    borrowerId.pop_back();
}

    isAvailable = (disponible == "1");
}
