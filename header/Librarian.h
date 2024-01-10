#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"
#include <string>

class Librarian : public Person {
	
private:
  // their  id and salary
    int staffId;
    int salary;

public:
    
    // Worker construcion
    
  Librarian(int staffId, std::string name, std::string address, std::string email, int salary);

    //member and books
  void addMember();
  void issueBook(int memberID, int bookID);
  void returnBook(int memberID, int bookID);
  void displayBorrowedBooks(int memberID);

    //Gets
  int getStaffID();
  int getSalary();
  
    
    //Sets
  
  void setStaffID(int staffID);
  void setSalary(int salary);
  	
  	// Calculate the fine
  void calcFine(int memberID);
    
};

#endif 
