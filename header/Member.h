#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Person.h" 
#include "Book.h"


class Member : public Person {
private:
    int memberId;
    std::vector<Book*> booksLoaned; 

public:
    // Member constructor
    Member(int memberId, std::string name, std::string address, std::string email);

    // Gets
    std::string getMemberId() ;
    std::vector<Book> getBooksBorrowed();

    //Sets
    void setBooksBorrowed(Book book);
};

#endif
