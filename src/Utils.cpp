#include "../header/utils.h"
#include <iostream>
#include <regex>

bool Utils::isEmail(const std::string& email) {
        
        std::regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

        //return true if match
        return std::regex_match(email, emailRegex);
    }
//valid string check
bool Utils::isString(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c) {
        return std::isalpha(c) || c == ' '; // Allow spaces
    });
}
//method to display the menu
void Utils::displayMenu() {
    std::cout << "Library Management System" << std::endl;
    std::cout << "1. Add a member" << std::endl;
    std::cout << "2. Issue a book to a member" << std::endl;
    std::cout << "3. Return a book from a member and calc a fine" << std::endl;
    std::cout << "4. Display all books borrowed by a member" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}