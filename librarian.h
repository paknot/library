#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"

class Librarian : public Person {
private:
  // his id and salary
    int staffId;
    int salary;

public:
    
    // Worker construcion
    
    Librarian(const std::string& name, const std::string& address, const std::string& email, int staffId, int salary)
        : Person(name, address, email), staffId(staffId), salary(salary) {}

    //Sets
    
    void setStaffId(int newStaffId) {
        staffId = newStaffId;
    }

    void setSalary(int newSalary) {
        salary = newSalary;
    }
    
    //Gets
    
    int getStaffId() const {
        return staffId;
    }

    int getSalary() const {
        return salary;
    }
};

#endif 
