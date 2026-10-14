#include "book.h" 
#include <sstream>
using namespace std;


//initialiser les variables du constructeur par défaut
Book::Book()
    : title(""),
      author(""),
      isbn(""),
      isAvailable(true),
      borrowerId("")
{
}

//initialiser les variables du constructeur avec parametres
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title),
      author(author),
      isbn(isbn),
      isAvailable(true),
      borrowerId("")
{
}

//getters
string Book::getTitle() const{
    return title; 
}

string Book::getAuthor() const{
    return author ;
}

string Book::getISBN() const{
    return isbn ;
}

bool Book::getAvailability() const{
    return isAvailable ;
}

string Book::getBorrowerId() const{
    return borrowerId ;
}

//setters
void Book::setTitle(const string& title) {
    this->title = title ;
}

void Book::setAuthor(const string& author) {
    this->author = author ;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn ;
}

void Book::setAvailability(bool available) {
    this->isAvailable = available ;
}

void Book::setBorrowerId(const string& id) {
    this->borrowerId = id ;
}

//method

void Book::checkOut(const string& borrowerId){
    this->borrowerId = borrowerId ;
    isAvailable = false ;
}

void Book::returnBook(){
    isAvailable = true; 
    borrowerId = "";
}

string Book::toString() const{
    string txt = "Titre : " + title + "\n" + 
    "Auteur : " + author + "\n" + "ISBN : " + isbn + "\n";
    
    if (!isAvailable){
        txt += "Statut : Emprunté \n"; 
        txt += "Emprunteur : " + borrowerId;
    } else {
        txt += "Statut : Disponible"; 
    }

    return txt;
}

string Book::toFileFormat() const{
    string txt = title + "|" + author +"|" + isbn + "|";
    if (!isAvailable){
        txt += "0|" + borrowerId ;
    } else {
        txt += "1|";
    }

    return txt;
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line); 
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss,isbn,'|');
    
    string dispo ;
    getline(ss, dispo ,'|');

    if (dispo == "0"){
        isAvailable = false ;
        getline(ss,borrowerId, '|');
    } else {
        isAvailable = true ;
        borrowerId = "";
    }

}