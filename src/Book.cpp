#include "../header/Book.h"



Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
}
Book::Book(){

}
    //Gets

std::string Book::getBookID() const{
    return std::to_string(this->bookID);
}
std::string Book::getBookName() const{
    return this->bookName;
}
std::string Book::getAuthorFirstName() const{
    return this->authorFirstName;
}
std::string Book::getAuthorLastName() const{
    return this->authorLastName;
}
Date Book::getDueDate() const{
    return this->dueDate;
}
    //Set due date
void Book::setDueDate(Date dueDate)
{
    this->dueDate = dueDate;
}
    //Books
void Book::returnBook(){
    Member nMember;
    Date nDate;
    this->borrower = nMember;
    this->dueDate = nDate;
}
void Book::borrowBook(Member borrower,Date duedate){
    this->borrower = borrower;
    setDueDate(dueDate);
}
//load the books from a file

void Book::loadBooksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    //skip header
    std::getline(file, line);

    while (getline(file, line)) {
        std::istringstream ss(line);
        int bookID;
        std::string bookName, authorFirstName, authorLastName, pageCount, bookType;
        
        
        if (ss >> bookID && std::getline(ss, bookName, ',') && std::getline(ss, pageCount, ',') 
            && std::getline(ss, authorFirstName, ',') && std::getline(ss, authorLastName, ',') 
            && std::getline(ss, bookType)) {
            
            // Trim potential leading spaces
            bookName.erase(0, bookName.find_first_not_of(" "));
            authorFirstName.erase(0, authorFirstName.find_first_not_of(" "));
            authorLastName.erase(0, authorLastName.find_first_not_of(" "));
            
           
            Book book(bookID, bookName, authorFirstName, authorLastName);
            Book::bookList.push_back(book); 
        }
    }

    file.close();
}
