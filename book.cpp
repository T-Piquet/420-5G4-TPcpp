#include "book.h"
#include "library.h"

Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}
Book::Book(const string &title, const string &author, const string &isbn)
	: title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string &title) { this->title = title; }
void Book::setAuthor(const string &author) { this->author = author; }
void Book::setISBN(const string &isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { isAvailable = available; }
void Book::setBorrowerId(const string &id) { borrowerId = id; }

void Book::checkOut(const string& borrowerId) {
	setAvailability(false);
	setBorrowerId(borrowerId);
}

void Book::returnBook() {
	setAvailability(true);
	setBorrowerId("");
}

string Book::toString(Library& library) const {
	if (!isAvailable) {
		User* borrower = library.findUserById(borrowerId);
		if (borrower) {
			return "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn +
				"\nDisponible: " + "Non" + "\nEmprunté par: " + borrower->getName();
		}
	}

	return "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nDisponible: " + "Oui" + "\n";
}

string Book::toFileFormat() const {
	return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

void Book::fromFileFormat(const string &line) {
	std::string fields[5];

	int start = 0;
	for (int i = 0; i < 5; ++i) {
		int endPos = line.find('|', start);
		fields[i] = line.substr(start, endPos - start);
		start = endPos + 1;
	}

	title = fields[0];
	author = fields[1];
	isbn = fields[2];
	isAvailable = (fields[3] == "1");
	borrowerId = fields[4];
}