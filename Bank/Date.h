/**
 * @filename Date.h
 * @author Alex Euzent
 * @date 5/5/2014
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{
    friend ostream& operator<<(ostream &stream, const Date &date);
    friend bool operator<(const Date &date1, const Date &date2);
    friend bool operator>(const Date &date1, const Date &date2);

    public:
        Date();
        Date(int month, int day, int year);
        int getMonth() const;
        void setMonth(int newMonth);
        int getDay() const;
        void setDay(int newDay);
        int getYear() const;
        void setYear(int newYear);
        Date subDays(int count);
    	Date& operator=(const Date &date);


    private:
        int month, day, year;
        bool isLeapYear(int year);
        int maxDays(int month, bool leapYear);

};

#endif // DATE_H
