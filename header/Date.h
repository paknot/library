//Date class to handle the dates

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

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
    

    //Dates
    bool isDateValid();
    bool isLeap(int year);
    static int daysBetween(const Date& date1, const Date& date2);
    static Date stringToDate(const std::string &dateString);
    Date getDateAfter();

    

    //Gets
    int getDay() const;
    int getMonth()const ;
    int getYear() const;
};

#endif
