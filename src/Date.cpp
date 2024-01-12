#include "../header/Date.h"

Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}
Date::Date(){
    this->day=11;
    this->month=1;
    this->year=2024;  
}

    //Gets
int Date::getDay(){
    return this->day;
}
int Date::getMonth(){
    return this->month;
}
int Date::getYear(){
    return this->year;
}
    //Sets
void Date::setDay(int day) {
    int originalDay = this->day;
    this->day = day; //temp
    if (!isDateValid()) {
        this->day = originalDay; //reverse
        std::cerr << "Invalid day: " << day << " Day must be a real day" << std::endl;
    }
}
void Date::setMonth(int month){
int originalMonth = this->month;
    this->month = month; //temp
    if (!isDateValid()) {
        this->month = originalMonth; //reverse
        std::cerr << "Invalid month: " << day << ", must be 1-12." << std::endl;
    }
}
void Date::setYear(int year){
int originalYear = this->year;
    this->year = year; //temp
    if (!isDateValid()) {
        this->year = originalYear; //reverse
        std::cerr << "Invalid year " << day << ", must be 2020-2026" << std::endl;
    }
}
std::string Date::getFormatDate(){
    return std::to_string(day) + '-' + std::to_string(month) + '-' + std::to_string(year);
}

//check the date
bool Date::isDateValid() {

    if (year < 2020 || year > 2026) {
        return false;
    }
    
    if (month < 1 || month > 12) {
        return false;
    }

    //day
    if (day < 1 || day > 31) {
        return false;
    }

    //check feb
    if (month == 2) {
        if (isLeap(year)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    }

    // April, June, Sept, Nov
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }

    
    return true;
}

bool Date::isLeap(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}
int Date::daysBetween(const std::string &currentDate, const std::string &dueDate) {
    Date date1 = stringToDate(currentDate);
    Date date2 = stringToDate(dueDate);

    std::tm tm1 = {0, 0, 0, date1.day, date1.month - 1, date1.year - 1900};
    std::tm tm2 = {0, 0, 0, date2.day, date2.month - 1, date2.year - 1900};

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    const double secondsPerDay = 60 * 60 * 24;
    double difference = std::difftime(time2, time1) / secondsPerDay;

    return static_cast<int>(difference);
}

Date Date::stringToDate(const std::string &dateString) {
    std::istringstream dateStream(dateString);
    int day, month, year;
    char delim;

    dateStream >> day >> delim >> month >> delim >> year;

    return Date(day, month, year);
}
Date Date::getDateAfter() {
    //get the current date form system
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    //construct a tm
    this->day = now->tm_mday;
    this->month = now->tm_mon + 1;    
    this->year = now->tm_year + 1900; 

    // Convert to time_t and add the days
    t += 3 * 24 * 3600; 

    //Convert back
    now = std::localtime(&t);

    //create and return date
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}


