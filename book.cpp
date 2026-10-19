#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

// Default constructor
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

// Parameterized constructor
Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string &title) { this->title = title; }
void Book::setAuthor(const string &author) { this->author = author; }
void Book::setISBN(const string &isbn) { this->isbn = isbn; }
void Book::setAvailability(const bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string &id) { this->borrowerId = id; }

// Cheking out
void Book::checkOut(const string &borrowerId)
{
    setAvailability(false);
    setBorrowerId(borrowerId);
}

// return a book
void Book::returnBook()
{
    setAvailability(true);
    setBorrowerId("");
}

string Book::toString() const
{
    string line = "Titre: " + getTitle() + "\nAuteur: " + getAuthor() + "\nISBN: " + getISBN();
    if (getAvailability())
    {
        line += "\nDisponible: Oui";
    }
    else
    {
        line += "\nDisponible: Non \nEmprunte par: " + getBorrowerId();
    }
    return line;
}

string Book::toFileFormat() const
{
    string line = getTitle() + "|" + getAuthor() + "|" + getISBN() + "|";

    if (getAvailability())
    {
        line += "1|";
    }
    else
    {
        line += "0|" + getBorrowerId();
    }

    return line;
}

void Book::fromFileFormat(const string &line)
{
    stringstream ss(line);
    string temp;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, temp, '|');
    if (temp == "1")
    {
        isAvailable = true;
    }
    else
    {
        isAvailable = false;
    }
    borrowerId = "";
    getline(ss, borrowerId, '|');
}