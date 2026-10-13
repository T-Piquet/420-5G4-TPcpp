#include <iostream>
#include <algorithm>

#include "library.h"
#include "logger.h"
using namespace std;

// Constructor
Library::Library() {}

// Add book to library
void Library::addBook(const Book& book, bool addToLog) {
    books.push_back(make_unique<Book>(book));

    if (addToLog) {
        ecrireJournal("[AJOUT LIVRE] " + book.toFileFormat());
    }
}

// Remove book from library
bool Library::removeBook(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](const unique_ptr<Book>& book) {
            return book->getISBN() == isbn;
        });

    if (it != books.end()) {
        string result = (*it)->getTitle() +
                        "|" + (*it)->getAuthor() +
                        "|" + (*it)->getISBN();

        ecrireJournal( " [SUPPRESSION LIVRE] " + result);

        books.erase(it);
        return true;
    }

    return false;
}

// Find book by ISBN
Book* Library::findBookByISBN(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](const unique_ptr<Book>& book) {
            return book->getISBN() == isbn;
        });
    
    return (it != books.end()) ? it->get() : nullptr;
}

// Search books by title (case-insensitive partial match)
vector<Book*> Library::searchBooksByTitle(const string& title) {
    vector<Book*> results;
    string lowerTitle = title;
    transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
    
    for (auto& book : books) {
        string bookTitle = book->getTitle();
        transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);
        
        if (bookTitle.find(lowerTitle) != string::npos) {
            results.push_back(book.get());
        }
    }

    return results;
}

// Search books by author (case-insensitive partial match)
vector<Book*> Library::searchBooksByAuthor(const string& author) {
    vector<Book*> results;
    string lowerAuthor = author;
    transform(lowerAuthor.begin(), lowerAuthor.end(), lowerAuthor.begin(), ::tolower);
    
    for (auto& book : books) {
        string bookAuthor = book->getAuthor();
        transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);
        
        if (bookAuthor.find(lowerAuthor) != string::npos) {
            results.push_back(book.get());
        }
    }
    return results;
}

// Get all available books
vector<Book*> Library::getAvailableBooks() {
    vector<Book*> available;
    for (auto& book : books) {
        if (book->getAvailability()) {
            available.push_back(book.get());
        }
    }
    return available;
}

// Get all books
vector<Book*> Library::getAllBooks() {
    vector<Book*> allBooks;
    for (auto& book : books) {
        allBooks.push_back(book.get());
    }
    return allBooks;
}

// Add user to library
void Library::addUser(const User& user) {
    users.push_back(make_unique<User>(user));
}

// Find user by ID
User* Library::findUserById(const string& userId) {
    auto it = find_if(users.begin(), users.end(),
        [&userId](const unique_ptr<User>& user) {
            return user->getUserId() == userId;
        });
    
    return (it != users.end()) ? it->get() : nullptr;
}

// Get all users
vector<User*> Library::getAllUsers() {
    vector<User*> allUsers;
    for (auto& user : users) {
        allUsers.push_back(user.get());
    }
    return allUsers;
}

// Check out book
bool Library::checkOutBook(const string& isbn, const string& userId) {
    Book* book = findBookByISBN(isbn);
    User* user = findUserById(userId);

    if (book && user && book->getAvailability()) {
        book->checkOut(user->getUserId());
        user->borrowBook(isbn);

        string result = book->getTitle() +
                        "|" + book->getAuthor() +
                        "|" + book->getISBN() +
                        "|0|" + user->getName();

        ecrireJournal( " [EMPRUNT] " + result);

        return true;
    }

    return false;
}

// Return book
bool Library::returnBook(const string& isbn) {
    Book* book = findBookByISBN(isbn);

    if (book && !book->getAvailability()) {
        string userName = "";

        for (auto& user : users) {
            if (user->hasBorrowedBook(isbn)) {
                userName = user->getName();
                user->returnBook(isbn);
                break;
            }
        }

        book->returnBook();

        string result = book->getTitle() +
                        "|" + book->getAuthor() +
                        "|" + book->getISBN() +
                        "|1|" + userName;

        ecrireJournal( " [RETOUR] " + result);

        return true;
    }

    return false;
}

// Display all books
void Library::displayAllBooks() {
    if (books.empty()) {
        cout << "Aucun livre dans la bibliothèque.\n";
        return;
    }

    vector<Book*> sortedBooks;

    for (auto &&book : books)
    {
        sortedBooks.push_back(book.get());
    }
    sort(sortedBooks.begin(), sortedBooks.end(),
    [](Book* a, Book* b) {
        if (a->getTitle() == b->getTitle()) {
            return a->getAuthor() < b->getAuthor();
        }

        return a->getTitle() < b->getTitle();
    });
    
    cout << "\n=== TOUS LES LIVRES ===\n";
    for (size_t i = 0; i < sortedBooks.size(); ++i) {
        cout << "\nLivre " << (i + 1) << " :\n";
        cout << sortedBooks[i]->toString(*this) << "\n";
        cout << "-------------------------\n";
    }
}

// Display available books
void Library::displayAvailableBooks() {
    auto available = getAvailableBooks();
    
    if (available.empty()) {
        cout << "Aucun livre disponible pour emprunt.\n";
        return;
    }
    
    cout << "\n=== LIVRES DISPONIBLES ===\n";
    for (size_t i = 0; i < available.size(); ++i) {
        cout << "\nLivre " << (i + 1) << " :\n";
        cout << available[i]->toString(*this) << "\n";
        cout << "---------------------------\n";
    }
}

// Display all users
void Library::displayAllUsers() {
    if (users.empty()) {
        cout << "Aucun utilisateur enregistré.\n";
        return;
    }
    
    cout << "\n=== TOUS LES UTILISATEURS ===\n";
    for (size_t i = 0; i < users.size(); ++i) {
        cout << "\nUtilisateur " << (i + 1) << " :\n";
        cout << users[i]->toString() << "\n";
        cout << "------------------------------\n";
    }
}

// Statistics
int Library::getTotalBooks() const { return books.size(); }
int Library::getAvailableBookCount() const {
    return count_if(books.begin(), books.end(),
        [](const unique_ptr<Book>& book) {
            return book->getAvailability();
        });
}
int Library::getCheckedOutBookCount() const { return getTotalBooks() - getAvailableBookCount(); }