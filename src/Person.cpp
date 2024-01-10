#include "../header/Person.h"


//Sets
void Person::setName(std::string name) {
    this->name = name;
}

void Person::setAddress(std::string address) {
    this->address = address;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

// Gets

std::string Person::getName(){
    return this->name;
}

std::string Person::getEmail(){
    return this->email;
}

std::string Person::getAddress(){
    return this->address;
}


