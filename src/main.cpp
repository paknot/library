#include <iostream>
#include <string>
#include "../header/Librarian.h"
#include "../header/Member.h"
#include "../header/Person.h"
#include "../header/Book.h"
#include "../header/Date.h"
#include "../header/Utils.h"



int main() {
    std::string libName, libAddress, libEmail;
    int libStaffID, libSalary;
    

    std::cout << "Please enter your details as a Librarian" << std::endl;

    //get a valid name
    do {
        std::cout << "Enter your name (letters only): ";
        std::getline(std::cin, libName);
        if (!Utils::isString(libName)) {
            std::cout << "Invalid name. Please use letters only.\n";
        }
    } while (!Utils::isString(libName));

    //adress
    std::cout << "Enter your address: ";
    std::getline(std::cin, libAddress);

    //valid email
    do {
        std::cout << "Enter your email: ";
        std::getline(std::cin, libEmail);
        if (!Utils::isEmail(libEmail)) {
            std::cout << "Invalid email format. Should be in a format user@user.com .\n";
        }
    } while (!Utils::isEmail(libEmail));

    //get a valid staff ID
    do {
        std::cout << "Enter librarian staff ID: ";
        if (!(std::cin >> libStaffID)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break; //valid
        }
    } while (true);

    //get a valid salary
    do {
        std::cout << "Enter librarian salary: ";
        if (!(std::cin >> libSalary)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error 
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
    //CSV filepath take
    std::string filepath;
    std::cout << "Enter a pathway to your csv file:" <<std::endl;
    std::cin >> filepath;
    Book bookInstance;
    bookInstance.loadBooksFromFile(filepath);

    while (running) {
        Utils::displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "You must enter a number." << std::endl;
        continue; 
    }

        //Swithc to take care of the numbers
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