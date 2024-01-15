#include "../header/Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year){
   
}
//Set initial value to current date
Date::Date(){
   std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}

    //Gets

//getDay
int Date::getDay()const{
    return day;
}
//getMonth
int Date::getMonth() const{
    return month;
}
//getYear
int Date::getYear() const{
    return year;
}



//days between 2 dates
  int Date::daysBetween(const Date& date1, const Date& date2) {
        std::tm tm1 = {0, 0, 0, date1.getDay(), date1.getMonth() - 1, date1.getYear() - 1900};
        std::tm tm2 = {0, 0, 0, date2.getDay(), date2.getMonth() - 1, date2.getYear() - 1900};

        std::time_t time1 = std::mktime(&tm1);
        std::time_t time2 = std::mktime(&tm2);

        const double secondsPerDay = 60 * 60 * 24;
        double difference = std::difftime(time2, time1) / secondsPerDay;

        return static_cast<int>(difference);
    }
    std::ostream& operator<<(std::ostream& os, const Date& dt) {
    os << dt.getDay() << "-" << dt.getMonth() << "-" << dt.getYear();
    return os;
}

    //3 days after
Date Date::getDateAfter() {
        //gettign the current date
        auto current = std::chrono::system_clock::now();

        //adding 3 days in hours
        auto threeDays = current + std::chrono::hours(72);

        //swithc to tm
        time_t tt = std::chrono::system_clock::to_time_t(threeDays);
        tm tm = *std::localtime(&tt);
        
        return Date(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    }

