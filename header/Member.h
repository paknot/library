#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Person.h" 
#include "Book.h"


class Member : public Person {
private:
    int memberID;
    std::vector<Book> booksLoaned; 

public:
    // Member constructor
    Member(int memberID, std::string name, std::string address, std::string email);

    // Gets
    std::string getMemberID() ;
    std::vector<Book> getBooksBorrowed();

    //Sets
    void setBooksBorrowed(Book book);
};

#endif
