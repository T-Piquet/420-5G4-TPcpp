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

// Setters
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

// Méthodes

// Méthode pour emprunter un livre
void Book::checkOut(const string &borrowerID)
{
    this->isAvailable = false;
    this->borrowerId = borrowerID;
}

// Méthode pour retourner un livre
void Book::returnBook()
{
    this->isAvailable = true;
    this->borrowerId = "";
}

// Méthode qui sert à transformer les infos d'un livre en chaîne
// de caractères pour l'affichage
string Book::toString() const
{
    string result = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn;
    if (isAvailable)
    {
        result += "\nDisponible: Oui";
    }
    else
    {
        result += "\nDisponible: Non\nEmprunteur ID: " + borrowerId;
    }

    return result;
}