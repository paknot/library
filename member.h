#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include "Person.h"

// for pointers/forward declaration
class Book;

class Member : public Person {
private:
    int memberId;
    std::vector<Book*> booksLoaned;

public:
    //Member Constructor
    Member(int memberId, const std::string& name, const std::string& address);
    ~Member(); // Destructor 
    Member(const Member&) = delete; // Prevent copying 
    Member& operator=(const Member&) = delete; // Prevent assignment
    int getMemberID() const;
    std::vector<Book*> getBooksBorrowed() const;
    void addBookLoaned(Book* book); 
    void removeBookLoaned(Book* book); 
};

#endif 
