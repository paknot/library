
#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "Person.h"
#include "Member.h"
#include "Date.h"
#include "Book.h"
#include <vector>
#include <string>

class Librarian : public Person {
	
private:
  // their  id and salary
    int staffID;
    int salary;
    

public:
    
    // Worker construcion
    
  Librarian(int staffID, std::string name, std::string adress, std::string email, int salary);

    //member and books
  void addMember();
  void issueBook(int memberID, int bookID);
  void returnBook(int memberID, int bookID);
  void displayBorrowedBooks(int memberID);

    //Gets
  int getStaffID();
  int getSalary();
  

  std::vector<Member> memberList;
  
    
    //Sets
  void getID();
  void setStaffID(int staffID);
  void setSalary(int salary);
  	
  	// Calculate the fine
  void calcFine(int memberID);
    
};

#endif 
