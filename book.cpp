#include <fstream>
#include <iostream>
#include <filesystem>
#include "book.h"

using namespace std;

//Default constructor
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId(""){}

//Constructor 
Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn) {}

//getters
string Book::getTitle() const {return title;}
string Book::getAuthor() const { return author;}
string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
string Book::getBorrowerId() const {return borrowerId;}

//Setters
void Book::setTitle(const string& title){ this->title = title;}
void Book::setAuthor(const string& author) { this->author = author;}
void Book::setISBN(const string& isbn) {this->isbn = isbn;}
void Book::setAvailability(const bool available) {this->isAvailable= available;}
void Book::setBorrowerId(const string& id){this-> borrowerId = id;}


//checkout
void Book::checkOut(const string& borrowerId){
    this->setAvailability(false);
    this->setBorrowerId(borrowerId);
}
//return book
void Book::returnBook(){
    this->setAvailability(true);
    this->setBorrowerId("");
}

//toString
string Book::toString() const {
    string result;
    if(isAvailable){
        result = "Nom du livre: " + title + "\nAutheur: " + author +
                    "\nISBN: " + isbn + "\nDisponible: Oui";
    }else{
         result = "Nom du livre: " + title + "\nAutheur: " + author +
                    "\nISBN: " + isbn + "\nDisponible: Non" +
                    "\nLouer par: " + borrowerId;
    }

    return result;
}
//to file format
string Book::toFileFormat() const{
    string result = title + "|" + author + '|' + isbn + "|";
    if(isAvailable){
        result += "1" ;
    }else{
        result +=  "0|" + borrowerId + "|";
    }
    return result;
}
//fromFile Format
void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    string token;

    getline(ss,title,'|');
    getline(ss,author,'|');
    getline(ss,isbn,'|');

    getline(ss, token, '|');
    isAvailable = (token == "1");

    getline(ss, borrowerId, '|');
    
}
