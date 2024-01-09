#include "Person.h"

// Constructor 
Person::Person(const std::string& name, const std::string& address, const std::string& email)
    : name(name), address(address), email(email) {}

//Sets
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAddress(const std::string& address) {
    this->address = address;
}

void Person::setEmail(const std::string& email) {
    this->email = email;
}

// Gets

std::string Person::getName() const {
    return name;
}

std::string Person::getEmail() const {
    return email;
}

std::string Person::getAddress() const {
    return address;
}


