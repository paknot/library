//Date class to handle the dates
#ifndef DATE_H
#define DATE_H

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

    //Sets
    void setDay(int day);
    void setMonth( int month);
    void setYear(int year);

    //Gets
    int getDay();
    int getMonth();
    int getYear();
};

#endif
