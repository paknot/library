//this is the person class
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
  

    // Gets
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;

  //Sets
  
    void setName(std::string &name);
    void setAddress(std::string &address);
    void setEmail(std::string &email);
};

#endif 
