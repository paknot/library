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
    // Person construction
    Person(const std::string &name, const std::string &address, const std::string &email);

    // Gets
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;

  //Sets
  
    void setName(const std::string &name);
    void setAddress(const std::string &address);
    void setEmail(const std::string &email);
};

#endif 
