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
Date Book::getDueDate() {
    return this->dueDate;
}

bool Book::getIsLoaned() const {
    return this->isLoaned;
}

void Book::setIsLoaned(bool isLoaned) {
    this->isLoaned = isLoaned;
}

    //Set due date
void Book::setDueDate(Date dueDate)
{
    this->dueDate = dueDate;
}
    //Books

void Book::borrowBook(Member borrower, Date duedate) {
    if(!this->isLoaned) {
        this->borrower = borrower;
        setDueDate(duedate);
        this->isLoaned = true;
        std::cout << "Book ID " << this->getBookID() << " due date set to: " << this->getDueDate() << std::endl;
    } else {
        std::cerr << "Book is already loaned." << std::endl;
    }
}

void Book::returnBook(){
    Member nMember;
    Date nDate;
    this->borrower = nMember;
    this->dueDate = nDate;
    this->isLoaned = false;
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
        std::vector<std::string> marks;
        std::string mark;
        bool inQuote = false;
        for (char ch : line)
        {
            if (ch == '"')
            {
                inQuote = !inQuote;
            }
            else if (ch == ',' && !inQuote)
            {

                marks.push_back(mark);
                mark.clear();
            }
            else
            {

                mark += ch;
            }
        }

        marks.push_back(mark);

        if(marks.size() >= 4) { 
            int bookID = std::stoi(marks[0]);
            std::string bookName = marks[1];
            std::string authorFirstName = marks[3]; 
            std::string authorLastName = marks[4]; 

            
            Book book(bookID, bookName, authorFirstName, authorLastName);
            
            Book::bookList.push_back(book); 

    
        }
    }   
}