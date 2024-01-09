#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"

class Librarian : public Person {
private:
  // their  id and salary
    int staffId;
    int salary;

public:
    
    // Worker construcion
    
  Librarian(int staffId, const std::string& name, const std::string& address, int salary)

    //books and members
  void addMember();
  void issueBook(int memberID, int bookID);
  void returnBook(int memberID, int bookID);

    //salary and ID
  int getStaffID() const;
  int getSalary() const;
    
    //Gets
  void displayBorrowedBooks(int memberID);
  void setStaffID(int staffID);
  void setSalary(int salary);
    
};

#endif 
