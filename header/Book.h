#ifndef BOOK_H
#define BOOK_H
#include "Member.h"
#include "Date.h"
#include <string>


class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
   	Date dueDate; 
    Member borrower; 
public:
    //Book Constructor
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
    //Gets
	int getBookID();
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
    std::string getDueDate();
    //Set duedate
    void setDueDate(Date dueDate);
    //return and borrow book
    void returnBook();
    void borrowBook(Member borrower, Date dueDate); 
};

#endif
