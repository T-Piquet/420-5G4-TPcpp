#include "book.h"
#include <sstream>
#include <vector>

using namespace std;


//Constructeur par defaut
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

 
//Constructeur paramétré
Book::Book(const string& title, const string& author, const string& isbn) :
    title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}


//Getters
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerId() const {
    return borrowerId;
}


//Setters
void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Book::setBorrowerId(const string& borrowerId) {
    this->borrowerId = borrowerId;
}


//Methodes
void Book::checkOut(const string& borrowerId) {
    this->borrowerId = borrowerId;
    isAvailable = false;
}

void Book::returnBook() {
    borrowerId = "";
    isAvailable = true;
}

string Book::toString() const {
    string resultat = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nStatut: " + (isAvailable ? "Disponible" : "Emprunté");
    return resultat;
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1|" : "0|" + borrowerId);
}

void Book::fromFileFormat(const string& line) {
    vector<string> champs;
    stringstream ss(line);
    string champ;

    // Decouper la ligne au niveau des |
    while (getline(ss, champ, '|')) {
        champs.push_back(champ);
    }

    // Si la ligne finit par |, ajouter le dernier champ vide ""
    if (!line.empty() && line.back() == '|') {
        champs.push_back("");
    }

    // check si ya 5 elements
    if (champs.size() != 5) {
        return;
    }

    title = champs[0];
    author = champs[1];
    isbn = champs[2]; 
    isAvailable = (champs[3] == "1");
    borrowerId = champs[4];
}
