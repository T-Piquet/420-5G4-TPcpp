#include "book.h"
#include <sstream>
using namespace std;


//constructeur par defaut
Book::Book() : title(""), author(""), isbn(""), isAvailable(true) {}
// Constructor avec parametres
Book::Book(const string& title, const string& author, const string& isbn)    : title(title), author(author), isbn(isbn), isAvailable(true)   {}

//les getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

//les setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool isAvailable) { this->isAvailable = isAvailable; }
void Book::setBorrowerId(const string& borrowerId) { this->borrowerId = borrowerId; }   


//methode pour emprunter un livre #9
void Book::checkOut(const string& borrowerId){
    if (isAvailable) {
        isAvailable = false;
        this->borrowerId = borrowerId;
    }
}

//méthode pour retourner un livre #10
void  Book::returnBook(){
    if (!isAvailable) {
        isAvailable = true;
        borrowerId = "";
    }
}

//méthode pour afficher un livre? #5 ou #6 ?
string Book::toString(const string& borrowerName) const{
    string nomEmprunteur = borrowerName.empty() ? borrowerId : borrowerName;
    return "Titre: " + title + "\nAuteur: "+ author + "\nISBN: "+ isbn + "\nStatus: "+ (isAvailable ? "Disponible" : "Emprunté par " + nomEmprunteur);
}

//Pour le mettre au format pour sauvegarder dans le fichier books.txt donc dois etre parreil que dans le fichier
string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, token, '|');
    isAvailable = (token == "1");
    getline(ss, borrowerId, '|');
}
