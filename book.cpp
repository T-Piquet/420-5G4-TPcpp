#include <sstream>

#include "book.h"

using namespace std;



Book::Book() {
    setTitle("");
    setAuthor("");
    setISBN("");
    setAvailability(true);
    setBorrowerId("");
}

Book::Book(const string& title, const string& author, const string& isbn){
    setTitle(title);
    setAuthor(author);
    setISBN(isbn);
    setAvailability(true);
    setBorrowerId("");
}

// Getters
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

//Setters
void Book::setTitle(const string& title){
    this->title=title;
}

void Book::setAuthor(const string& author){
    this->author=author;
}

void Book::setISBN(const string& isbn){
    this->isbn=isbn;
}

void Book::setAvailability(bool available){
    this->isAvailable=available;
}

void Book::setBorrowerId(const string& id){
    this->borrowerId=id;
}

// Methods
string Book::trim(const string& value) {
    const size_t first = value.find_first_not_of(" \t\r\n");
    if (first == string::npos) {
        return "";
    }

    const size_t last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

void Book::checkOut(const string& borrowerId){
    setAvailability(false);
    setBorrowerId(borrowerId);
}

void Book::returnBook(){
    setAvailability(true);
    setBorrowerId("");
}

string Book::toString(const string& borrowerName) const{
    string result = getTitle() + " | " 
        + getAuthor() + " | " 
        + getISBN() + " | ";

    if(getAvailability()){
        result += "1 |";
    }else{
        result += "0 | " + borrowerName;
    }

    return result;
}

string Book::toFileFormat() const{
    string result = getTitle() + " | " 
        + getAuthor() + " | " 
        + getISBN() + " | ";

    if(getAvailability()){
        result += "1 |";
    }else{
        result += "0 | " + getBorrowerId();
    }

    return result;
}

void Book::fromFileFormat(const string& line){
    stringstream bookInfo(line);

    string available;

    getline(bookInfo, this->title, '|');
    getline(bookInfo, this->author, '|');
    getline(bookInfo, this->isbn, '|');
    getline(bookInfo, available, '|');
    getline(bookInfo, this->borrowerId, '|');

    this->title = trim(this->title);
    this->author = trim(this->author);
    this->isbn = trim(this->isbn);
    this->borrowerId = trim(this->borrowerId);
    setAvailability(trim(available) == "1");
}