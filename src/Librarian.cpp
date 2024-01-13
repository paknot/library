#include "../header/Librarian.h"
#include "../header/Member.h"
#include "../header/Person.h"
#include "../header/Book.h"

#include <string>
#include <iostream>
 
Librarian::Librarian(int staffID, std::string name, std::string adress, std::string email, int salary)
{
    this->staffID = staffID;
    this->salary = salary;
    setName(name);
    setAddress(adress);
    setEmail(email);
}
//Set Staff ID
void Librarian::setStaffID(int staffID) {
    if (staffID > 0 && staffID < 1000) {
        this->staffID = staffID;
    } else {
        std::cout << "Invalid input. Staff ID must be 3-digit positive integer" << std::endl;
    }
}
void Librarian::setSalary(int salary){
	if(salary >10000 && salary < 60000 ){
		this->salary = salary;
	} else {
		std::cout << "Invalid input. Staff salary must be between 10k and 60k" << std::endl;
	}
}

int Librarian::getStaffID() {
    return this->staffID;
  }
  int Librarian::getSalary() {
    return this->salary;
  }

  void Librarian::addMember(){
    Person person;
    std::string memName, memAddress, memEmail;
    
    int id = memberList.size() +1;
    //member name
   while (true) {
    std::cout << "Enter member's name: " << std::endl;
    std::cin >> memName;
    if (person.isString(memName)) {
        break;
    } else {
        std::cerr << "Name must only contain letters." << std::endl;
    }
}

while (true) {
    std::cout << "Enter member's email: " << std::endl;
    std::cin >> memEmail;
    if (person.isEmail(memEmail)) {
        break;
    } else {
        std::cerr << "Invalid email. Email must look like this user@example.com" << std::endl;
    }
}
    std::cout << "Enter member's address: " << std::endl;
    std::cin >> memAddress;

    Member newMember(id, memName, memAddress, memEmail);
    memberList.push_back(newMember);

    std::cout <<std::endl<< "New member added with the following details:" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << memName << std::endl;
    std::cout << "Address: " << memAddress << std::endl;
    std::cout << "Email: " << memEmail << std::endl;

  }
  std::vector<Book> Book::bookList;

  void Librarian::issueBook(int memberID, int bookID) {
    
    // Find the member
    Member* member = nullptr;
    for (auto& m : memberList) {
        if (std::stoi(m.getMemberID()) == memberID) {
            member = &m;
            break;
        }
    }

    //For time
    Book books;
    Date currentDate;
    Date newDate = currentDate.getDateAfter();
    
   
    // Find the book
   Book* book = nullptr;
    for (auto& b : Book::bookList) {
        if (b.getBookID() == std::to_string(bookID)) {
            book = &b;
            break;
        }
    }

    if (book != nullptr && book->getIsLoaned()) {
        std::cerr << "The book is currently loaned and cannot be issued." << std::endl;
        return;
    }
    

    // Issue the book
    if (member != nullptr && book != nullptr) {
        member->setBooksBorrowed(*book);
        book->borrowBook(*member, newDate);
        std::cout <<std::endl<< "Book with id: " << bookID << " has been loaned to memberID: "<< memberID << std::endl;
        std::cout << "Current date (DD-MM-YYYY): " << currentDate.getDay() << "-" << currentDate.getMonth() << "-" << currentDate.getYear() << std::endl;
        std::cout << "Due date (DD-MM-YYYY): " << book->getDueDate()<< std::endl;
        } else {
        std::cerr << "unknown error. try again?";
    }

  }

void Librarian::returnBook(int memberID, int bookID) {
    Member* member = nullptr;
    Book* book = nullptr;
    int fine = 0;

    // Find the member
    for (auto& m : memberList) {
        if (std::stoi(m.getMemberID()) == memberID) {
            member = &m;
            break;
        }
    }

    // Find the book
    for (auto& b : Book::bookList) {
    if (b.getBookID() == std::to_string(bookID)) {
        book = &b;
        break;
        }
    }

    //both exist
    if (member && book) {
        
        Date today; 
        
        

        // Assuming Date class has a method to calculate the difference in days
        int daysOverdue = Date::daysBetween(book->getDueDate(), today);
        if (daysOverdue > 0) {
            // Calculate fine, £1 per day overdue
            fine = daysOverdue;
        }

        //remove books
        auto& booksLoaned = member->getBooksBorrowed();
        booksLoaned.erase(std::remove_if(booksLoaned.begin(), booksLoaned.end(),
                          [bookID](const Book& b) { return std::stoi(b.getBookID()) == bookID; }),
                          booksLoaned.end());

        // Reset the borrower and due date in the Book object
        book->returnBook();
        
        // Output the fine if there is one
        if (fine > 0) {
            std::cout << "The book is overdue. The fine is £" << fine << ".\n";
        } else {
            std::cout << "Book returned on time. No fine due.\n";
        }
    } else {
        if (!member) {
            std::cerr << "Member ID " << memberID << " not found." << std::endl;
        }
        if (!book) {
            std::cerr << "Book ID " << bookID << " not found." << std::endl;
        }
    }
}
void Librarian::displayBorrowedBooks(int memberID) {
    // Find the member again

    Member* member = nullptr;
    for (auto& m : memberList) {
        if (std::stoi(m.getMemberID()) == memberID) {
            member = &m;
            break;
        }
    }

    //if found display books
    if (member) {
        std::cout << "Books borrowed by member ID " << memberID << ":" << std::endl;

         auto& booksLoaned = member->getBooksBorrowed();
        if (booksLoaned.empty()) {
            std::cout << "No books currently borrowed." << std::endl;
            return;
        }

        for (auto& book : booksLoaned) {
            std::cout << "Book ID: " << book.getBookID()
                      << ", Title: " << book.getBookName()
                      << ", Author: " << book.getAuthorFirstName() << " " << book.getAuthorLastName()
                      << ", Due Date: " << book.getDueDate()
                      << std::endl;
        }
    } else {
        std::cerr << "Member ID " << memberID << " not found." << std::endl;
    }
}
  
  
