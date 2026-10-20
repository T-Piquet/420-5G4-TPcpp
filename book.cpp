#include <iostream>
#include "book.h"
using namespace std;

/* J'ai appris que si les méthodes dans le fichier .h ont été déclarés
dans une class, alors il faut mettre le nom de la class avec :: devant,
si non on crée de nouvelle méthodes pas rapport. Par exemple, ici, c'est
Book:: */
// Constructeurs
Book::Book()
{
    this->title = "";
    this->author = "";
    this->isbn = "";
    this->isAvailable = true;
    this->borrowerId = "";
}

Book::Book(const string &title, const string &author, const string &isbn)
{
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->isAvailable = true;
    this->borrowerId = "";
}

// const veut dire que la méthode ne modifie pas l'objet sur lequel elle est appelée.
// Getters
string Book::getTitle() const
{
    return this->title;
}

string Book::getAuthor() const
{
    return this->author;
}

string Book::getISBN() const
{
    return this->isbn;
}

bool Book::getAvailability() const
{
    return this->isAvailable;
}

string Book::getBorrowerId() const
{
    return this->borrowerId;
}
