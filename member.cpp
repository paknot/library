#include "Member.h"

// Member Constructor
Member::Member(int id, const std::string& name, const std::string& address)
: Person(name, address), memberId(id) {}

// Member Destructor
Member::~Member() {}

//Prevent copying
Member::Member(const Member&) = delete;

//prevent assigmnent
Member& Member::operator=(const Member&) = delete;


int Member::getMemberID() const {
    return memberId;
}


std::vector<Book*> Member::getBooksBorrowed() const {
    return booksLoaned;
}


void Member::addBookLoaned(Book* book) {
    //the book cannot be added twice
    for(auto& b : booksLoaned) {
        if(b == book) {
            return; 
        }
    }
    booksLoaned.push_back(book);
}

void Member::removeBookLoaned(Book* book) {
    auto it = std::find(booksLoaned.begin(), booksLoaned.end(), book);
    if (it != booksLoaned.end()) {
        booksLoaned.erase(it);
    } else {
         std::cerr << "This book is not loaned to this member." << std::endl;
    }
}
