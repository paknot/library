#include "../header/Librarian.h"
#include "../header/Member.h"
#include "../header/Person.h"
#include "../header/Book.h"
#include "../header/Date.h"

//Sets
void Person::setName(std::string name) {
    if(isString(name)){
        this->name = name;
    } else{
        std::cerr <<"invalid input, needs to be a string "<< name <<std::endl;
    }
    
}

void Person::setAddress(std::string address) {
    if(isString(name)){
        this->address = address;
    } else{
        std::cerr <<"invalid input, needs to be a string "<< address <<std::endl;
    }
    
}

void Person::setEmail(std::string email) {
    if(isEmail(email)){
	this->email = email;
	} else {
		std::cerr<< "invalid email: " << email << std::endl;
	}
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
//valid email check
    bool Person::isEmail(const std::string& email) {
        
        std::regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

        //return true if match
        return std::regex_match(email, emailRegex);
    }
     bool Person::isString(const std::string& str) {
        return std::all_of(str.begin(), str.end(), [](char c) {
            return std::isalpha(c);
        });
    }


