#include <sstream>
#include "book.h"

using namespace std;

//Constructeurs
Book::Book() : title(""), author (""), isbn(""), isAvailable(true), borrowerId(""){}

Book::Book(const string & title, const string & author, const string & isbn) 
    : title(""), author (""), isbn(""), isAvailable(true), borrowerId(""){}

//Getters
string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
string Book::getBorrowerId() const {return borrowerId;}

//Setters
void Book::setTitle(const string & title) {this->title = title;}
void Book::setAuthor(const string & author) {this->author = author;}
void Book::setISBN(const string & isbn) {this->isbn = isbn;}
void Book::setAvailability(bool avalable) {this->isAvailable = avalable;}
void Book::setBorrowerId(const string & id) {this->borrowerId = id;}

//Emprunt 
void Book::checkOut(const string & borrowerID){
    isAvailable = false;
    this->borrowerId = borrowerID;
}

//Retour 
void Book::returnBook(){
    isAvailable = true;
    borrowerId.clear();
}

//toString
string Book::toString() const{
    string disponibilite;
    if(isAvailable){
        disponibilite += "Disponible";
    }else{
        disponibilite += "Indisponible, emprunté par: " + borrowerId;
    }
    string texte = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nStatu: " + disponibilite;
    return texte;
}

//Sauvegarde 
string Book::toFileFormat() const{
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

//Lecture dune ligne 
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string available;
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, available, '|');
    getline(ss, borrowerId, '|');
    isAvailable = (available != "0");
}