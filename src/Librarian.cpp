#include "../header/Librarian.h"
#include <string>
#include <iostream>

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
void Librarian::addMember(){
	
}
