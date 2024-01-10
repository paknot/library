#include "../header/Member.h"
#include <ctime>
#include <cstdlib>
#include <string>

//Member construction 
Member::Member(int memberID, std::string name, std::string address, std::string email)
: Person(name, address, email), memberID(memberID) {}

//Get memberID
std::string Member::getMemberID() {
	static bool isSeeded = false;
	if(!isSeeded) {
		
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	isSeeded = true;
	}
	//Generate a random 3-digit ID
	memberID = std::rand() % 900 + 100;
    return std::to_string(this->memberID);
}

//Get books borrowed
std::vector<Book> Member::getBooksBorrowed() {
	return this->booksLoaned;
}
void Member::setBooksBorrowed(Book book) {
	this->booksLoaned.push_back(book);
}

