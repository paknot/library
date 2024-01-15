//this is the person head

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
  

    // Gets
    std::string getName();
    std::string getAddress();
    std::string getEmail();

  //Sets
  
    void setName(std::string name);
    void setAddress(std::string address);
    void setEmail(std::string email);

    
};

#endif 
