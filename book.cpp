#include "Book.h"
#include "Member.h"
#include <iostream>

//Book Constructor
Book::Book(int id, const std::string& name, const std::string& authorFirst, const std::string& authorLast)
: bookID(id), bookName(name), authorFirstName(authorFirst), authorLastName(authorLast), borrower(nullptr) {}

//Book Destructor
Book::~Book() {}

//Prevent copying
Book::Book(const Book&) = delete;

//Stop asssignment
Book& Book::operator=(const Book&) = delete;

//Gets
int Book::getBookID() const {
    return bookID;
}

std::string Book::getBookName() const {
    return bookName;
}

std::string Book::getAuthorFirstName() const {
    return authorFirstName;
}

std::string Book::getAuthorLastName() const {
    return authorLastName;
}

std::string Book::getDueDate() const {
    return dueDate;
}

//Sets
void Book::setDueDate(const std::string& newDueDate) {
    dueDate = newDueDate;
}

// Other methods
void Book::borrowBook(Member* newBorrower, const std::string& newDueDate) {
    if (borrower) {
        std::cerr << "Book already borrowed by another member." << std::endl;
        return;
    }

    borrower = newBorrower;
    setDueDate(newDueDate);
    borrower->addBookLoaned(this);
}
