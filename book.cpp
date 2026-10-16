#include "book.h"
#include <sstream>

using namespace std;

// Constructeur par defaut
Book ::Book() : title(""), author(""),isbn(""),isAvailable(true),borrowerId(""){}

// Constructeur avec parametres
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

// Getters 
string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
string Book::getISBN() const{return isbn;}
bool Book::getAvailability() const{return isAvailable;}
string Book::getBorrowerId() const {return borrowerId;}

// Setters
void Book::setTitle(const string& title) { this->title = title;}
void Book::setAuthor(const string& author) { this->author = author;}
void Book::setISBN(const string& isbn) {this->isbn = isbn;}
void Book::setAvailability(bool available) {this -> isAvailable = available;}
void Book::setBorrowerId(const string& id){this ->borrowerId = id;}

// Methode

// Methode pour prendre un livre, rendre le livre non disponible et mettre id
void Book::checkOut(const string& borrowerId){
    setAvailability(false);
    setBorrowerId(borrowerId);
}

// Methode pour retourner un livre, le mettre libre et enelver borrowerId
void Book::returnBook(){
    setAvailability(true);
    setBorrowerId("");

}

// Methode pour retourner un String pour la description d'un livre
string Book::toString() const { 
    string result = "";
    if (isAvailable ) {
        result = "Titre : " + title + "\n Autheur : " + author + "\n ISBN : " + isbn + "\n Status : Disponible"; 
    }
    else{
        result = "Titre : " + title + "\n Autheur : " + author + "\n ISBN : " + isbn; 
    }
    return result;
}

// Methode pour donner un format pour une sauvegarde
string Book::toFileFormat() const {
   string livreDispo = isAvailable ? "1"  : "0";

   string result = title + "|" + author + "|" + isbn + "|" + livreDispo + "|" + borrowerId;

   return result;
}

// Methode pour separer le contenu du fichier pour les atributs des livres
void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    string livreDispo;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    //livreDispo au lieu de isAvailable parce qu'en haut jai utilise livreDispo en str pour savoir si ca ete emprunte
    getline(ss, livreDispo, '|');

    getline(ss, borrowerId);

    //Convertir le texte livreDispo pour l'attribuer a isAvailable
    isAvailable = (livreDispo == "1");
}