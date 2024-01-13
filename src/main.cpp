#include <iostream>
#include <string>
#include "../header/Librarian.h"
#include "../header/Member.h"
#include "../header/Person.h"
#include "../header/Book.h"
#include "../header/Date.h"

void displayMenu() {
    std::cout << "Library Management System" << std::endl;
    std::cout << "1. Add a member" << std::endl;
    std::cout << "2. Issue a book to a member" << std::endl;
    std::cout << "3. Return a book from a member and calc a fine" << std::endl;
    std::cout << "4. Display all books borrowed by a member" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::string libName, libAddress, libEmail;
    int libStaffID, libSalary;

    std::cout << "Please enter your details to initialize the Librarian." << std::endl;

    // Get and validate name
    do {
        std::cout << "Enter your name (alphabetic characters only): ";
        std::getline(std::cin, libName);
        if (!Person::isString(libName)) {
            std::cout << "Invalid name. Please use alphabetic characters only.\n";
        }
    } while (!Person::isString(libName));

    //adress
    std::cout << "Enter your address: ";
    std::getline(std::cin, libAddress);

    //valid email
    do {
        std::cout << "Enter your email: ";
        std::getline(std::cin, libEmail);
        if (!Person::isEmail(libEmail)) {
            std::cout << "Invalid email format. Please try again.\n";
        }
    } while (!Person::isEmail(libEmail));

    // Get and validate staff ID
    do {
        std::cout << "Enter your staff ID: ";
        if (!(std::cin >> libStaffID)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break; // Valid input
        }
    } while (true);

    // Get and validate salary
    do {
        std::cout << "Enter your salary: ";
        if (!(std::cin >> libSalary)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break; // Valid
        }
    } while (true);
    std::cin.ignore(); //ignore new line char
    

    //initialize librarian
    Librarian librarian(libStaffID, libName, libAddress, libEmail, libSalary);
    int choice;
    bool running = true;

    std::string filepath;
    std::cout << "Enter a pathway to your csv file:" <<std::endl;
    std::cin >> filepath;
    Book bookInstance;
    bookInstance.loadBooksFromFile(filepath);

    while (running) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "You must enter a number." << std::endl;
        continue; 
    }


        switch (choice) {
            case 1:
                librarian.addMember();
                break;
            case 2: {
                int memberID, bookID;
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                std::cout << "Enter book ID: ";
                std::cin >> bookID;
                librarian.issueBook(memberID, bookID);
                break;
            }
            case 3: {
                int memberID, bookID;
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                std::cout << "Enter book ID: ";
                std::cin >> bookID;
                librarian.returnBook(memberID, bookID);
                break;
            }
            case 4: {
                int memberID;
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                librarian.displayBorrowedBooks(memberID);
                break;
            }
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout << "Thank you for using the Library Management System." << std::endl;
    return 0;
}