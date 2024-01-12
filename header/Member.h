
#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Person.h" 

class Book;


class Member : public Person {
private:
    int memberID;
    std::vector<Book> booksLoaned; 

public:
    // Member constructor
    Member(int memberID, std::string name, std::string address, std::string email);
    Member();
    // Gets
    std::string getMemberID() ;
    std::vector<Book>& getBooksBorrowed();

    //Sets
    void setBooksBorrowed(Book book);
    void setMemberID();

    //Removes books
    void removeBookByName(std::string bookName);

};

#endif
