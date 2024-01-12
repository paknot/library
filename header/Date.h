//Date class to handle the dates

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>
class Date
{
private:
    int day;
    int month;
    int year;

public:
    //Date itself
    Date();
    Date(int day, int month, int year);
    std::string getFormatDate();

    //Dates
    bool isDateValid();
    bool isLeap(int year);
    static int daysBetween(const std::string &currentDate, const std::string &dueDate);
    static Date stringToDate(const std::string &dateString);
    Date getDateAfter();

    //Sets
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    //Gets
    int getDay();
    int getMonth();
    int getYear();
};

#endif
