#ifndef BOOK_H
#define BOOK_H

#include <string>

// for pointer/forward declaration
class Member;

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string dueDate; 
    Member* borrower; 

public:
    //Book Constructor
    Book(int bookID, const std::string& bookName, const std::string& authorFirstName, const std::string& authorLastName);
    ~Book(); // Destructor 
    Book(const Book&) = delete; // Prevent coping
    Book& operator=(const Book&) = delete; // Prevent assignment
    int getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    std::string getDueDate() const;
    void setDueDate(const std::string& dueDate);
    void borrowBook(Member* borrower, const std::string& dueDate); //pointer to member
};

#endif
