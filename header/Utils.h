#pragma once
#include <regex>
#include <algorithm>
#include <cctype>


class Utils {
public:
    static void displayMenu();
    static bool isEmail(const std::string& email);
    static bool isString(const std::string& str);
};