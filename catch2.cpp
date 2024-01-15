#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "header/Librarian.h"
#include "header/Member.h"
#include "header/Book.h"
#include "header/Date.h"
#include "header/Person.h"

TEST_CASE("Librarian initializer", "[librarian]") {
    int staffID = 123;
    std::string name = "John Doe";
    std::string address = "123 Library Lane";
    std::string email = "john.doe@example.com";
    int salary = 50000;

    Librarian librarian(staffID, name, address, email, salary);

    REQUIRE(librarian.getStaffID() == staffID);
    REQUIRE(librarian.getName() == name);
    REQUIRE(librarian.getAddress() == address);
    REQUIRE(librarian.getEmail() == email);
    REQUIRE(librarian.getSalary() == salary);
}
TEST_CASE("Book initializer", "Book") {
    int bookID = 1;
    std::string bookName = "Test Book";
    std::string authorFirstName = "Jane";
    std::string authorLastName = "Doe";
    
    Book book(bookID, bookName, authorFirstName, authorLastName);

    REQUIRE(book.getBookID() == std::to_string(bookID));
    REQUIRE(book.getBookName() == bookName);
    REQUIRE(book.getAuthorFirstName() == authorFirstName);
    REQUIRE(book.getAuthorLastName() == authorLastName);

SECTION("Checking loan functionality") {
    Member dummyMember(1,  "Member", "Colindale", "mem@library.com");
    Date current;
    Date dueDate= current.getDateAfter();
    //borrow a book
    book.borrowBook(dummyMember, dueDate);
        
    REQUIRE(book.getIsLoaned() == true);
    
    //return it
    book.returnBook();
        
    REQUIRE(book.getIsLoaned() == false);


    }
}
TEST_CASE("Member initializer", "[member]") {
    int memberID = 1;
    std::string name = "Ankara Messi";
    std::string address = "123 Main St";
    std::string email = "messi@example.com";
    
    Member member(memberID, name, address, email);

    REQUIRE(member.getMemberID() == std::to_string(memberID));
    REQUIRE(member.getName() == name);
    REQUIRE(member.getAddress() == address);
    REQUIRE(member.getEmail() == email);

    SECTION("Borrowing") {
        Book book(157, "Test Book", "Jane", "Doe"); 

        //borrow the book
        member.setBooksBorrowed(book);
        
        //get borrowed books
        std::vector<Book>& booksLoaned = member.getBooksBorrowed();
        
        REQUIRE(booksLoaned.size() == 1);
        REQUIRE(booksLoaned[0].getBookID() == book.getBookID());
        REQUIRE(booksLoaned[0].getBookName() == book.getBookName());
        REQUIRE(booksLoaned[0].getAuthorFirstName() == book.getAuthorFirstName());
        REQUIRE(booksLoaned[0].getAuthorLastName() == book.getAuthorLastName());
    }
}
TEST_CASE("Date functionality", "[date]") {
    SECTION("Date construction with specific date") {
        Date specificDate(18, 4, 2024); 
        REQUIRE(specificDate.getDay() == 18);
        REQUIRE(specificDate.getMonth() == 4);
        REQUIRE(specificDate.getYear() == 2024);
    }
    //check if current time is actually current time
    SECTION("Current Time") {
        Date currentDate;
        
        std::time_t t = std::time(nullptr);
        std::tm *now = std::localtime(&t);

        REQUIRE(currentDate.getDay() == now->tm_mday);
        REQUIRE(currentDate.getMonth() == now->tm_mon + 1);
        REQUIRE(currentDate.getYear() == now->tm_year + 1900);
    }
    //check is daysBetween works 
    SECTION("daysBetween") {
        Date date1(1, 1, 2024);
        Date date2(2, 1, 2024);

        REQUIRE(Date::daysBetween(date1, date2) == 1);
    }
    //check if getDateAfter works using daysBetween
    SECTION("getDateAfter") {
        Date currentDate;
        Date dateAfter = currentDate.getDateAfter();

        
        REQUIRE(Date::daysBetween(currentDate, dateAfter) == 3);
    }
}
