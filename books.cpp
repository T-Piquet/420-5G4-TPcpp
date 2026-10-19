#include "book.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
// Constructeur par defaut
Book::Book()
    : title(""), author(""), isbn(""), isAvailable(true), borrowerId("")
{
}

// Constructeur avec params
Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("")
{
}

// getters

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return isbn;
}

bool Book::getAvailability() const
{
    return isAvailable;
}

string Book::getBorrowerId() const
{
    return borrowerId;
}

// setters

void Book::setTitle(const string &title)
{
    this->title = title;
}

void Book::setAuthor(const string &author)
{
    this->author = author;
}

void Book::setISBN(const string &isbn)
{
    this->isbn = isbn;
}

void Book::setAvailability(bool available)
{
    this->isAvailable = available;
}

void Book::setBorrowerId(const string &id)
{
    this->borrowerId = id;
}

// methodes

void Book::checkOut(const string &borrowerId)
{
    if (isAvailable)
    {
        this->borrowerId = borrowerId;
        isAvailable = false;
    }
}

void Book::returnBook()
{
    this->borrowerId = "";
    isAvailable = true;
}

string Book::toString() const
{
    string dispo = "Non disponible";
    if (isAvailable)
    {
        dispo = "Disponible";
    }
    string result = "Titre Livre: " + title +
                    "\nAuteur: " + author +
                    "\nISBN: " + isbn +
                    "\nDisponible: " + dispo;
    return result;
}

string Book::toFileFormat() const
{
    int dispo = isAvailable;
    string result = title + "|" + author + "|" + isbn + "|" + to_string(dispo) + "|" + borrowerId;
}

void Book::fromFileFormat(const string &line)
{
    stringstream ss(line);
    string isAvailableStr;
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, isAvailableStr, '|');
    getline(ss, borrowerId, '|');

    if (isAvailableStr == "1")
    {
        isAvailable = true;
    }
    else
    {
        isAvailable = false;
    }
}