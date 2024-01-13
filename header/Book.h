
#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include "Member.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>


class Date;


class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
   	Date dueDate;
    bool isLoaned = false;
    Member borrower; 
public:
    //Book Constructor
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
    Book();
    //Gets

	
    std::string getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    Date getDueDate() ;

    bool getIsLoaned() const;
    void setIsLoaned(bool isLoaned);

    void setDueDate(Date dueDate);

    //return and borrow book
     
    void returnBook();
    void borrowBook(Member borrower, Date dueDate);

    //Books from a file

    void loadBooksFromFile(const std::string& filename); 

    //book vector
    static std::vector<Book> bookList;
};

#endif
