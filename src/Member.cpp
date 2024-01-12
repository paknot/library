#include "../header/Member.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include "../header/Book.h"

//Member construction 
Member::Member(int memberID, std::string name, std::string address, std::string email){
	this->memberID =memberID;
	setName(name);
	setAddress(address);
	setEmail(email);
}
Member::Member(){

}


std::string Member::getMemberID(){
return std::to_string(this->memberID);
}
//Get books borrowed
std::vector<Book>& Member::getBooksBorrowed(){
	return this->booksLoaned;
}
void Member::setBooksBorrowed(Book book) {
	this->booksLoaned.push_back(book);
}



