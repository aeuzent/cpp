/**
 * @filename Date.cpp
 * @author Alex Euzent
 * @date 5/5/2014
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Date.h"

using namespace std;


/**
 * Constructor for Date
 * creates a date for now
 */
 Date::Date() {
    time_t t = time(0);
    struct tm * now = localtime( & t );

    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}


/**
 * Constructor for Date
 * @param month
 * @param day
 * @param year
 */
Date::Date(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;
}


/**
 * Accessor for month
 * @return int
 */
int Date::getMonth() const {
   return month;
}


/**
 * Mutator for month
 * @param month
 */
void Date::setMonth(int month) {
    this->month = month;
}


/**
 * Accessor for day
 * @return int
 */
int Date::getDay() const {
   return day;
}


/**
 * Mutator for day
 * @param day
 */
void Date::setDay(int day) {
    this->day = day;
}


/**
 * Accessor for year
 * @return int
 */
int Date::getYear() const {
   return year;
}


/**
 * Mutator for year
 * @param year
 */
void Date::setYear(int year) {
    this->year = year;
}


/**
 * Overloaded operator for <<
 * @return ostream
 */
ostream& operator<<(ostream &stream, const Date &date) {
   stream << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
   return stream;
}


/**
 * Overloaded operator for <
 * @return bool
 */
bool operator<(const Date &date1, const Date &date2){
    bool result = false;
    if(date1.getYear() < date2.getYear()){
        result = true;;
    } else if (date1.getYear() == date2.getYear()){
        if(date1.getMonth() < date2.getMonth()){
            result = true;
        } else if (date1.getMonth() == date2.getMonth()) {
            if(date1.getDay() < date2.getDay()){
                result = true;
            }
        }
    }
    return result;
}


/**
 * Overloaded operator for >
 * @return bool
 */
bool operator>(const Date &date1, const Date &date2){
    bool result = false;
    if(date1.getYear() > date2.getYear()){
        result = true;;
    } else if (date1.getYear() == date2.getYear()){
        if(date1.getMonth() > date2.getMonth()){
            result = true;
        } else if (date1.getMonth() == date2.getMonth()) {
            if(date1.getDay() > date2.getDay()){
                result = true;
            }
        }
    }
    return result;
}


/**
 * Overloaded operator for =
 * @return Date
 */
Date& Date::operator=(const Date &date){
    if(this == &date)
        return *this;

    this->month = date.getMonth();
    this->day = date.getDay();
    this->year = date.getYear();
    return *this;
}


/**
 * Returns true if year is
 * a leap year
 * @param year
 * @return bool
 */
bool Date::isLeapYear(int year){
    bool result = false;
    if(year%4 == 0){
        if(year%100 != 0){
            result = true;
        } else {
            if(year%400 == 0){
                result = true;
            }
        }
    }
    return result;
}


/**
 * Returns total days for
 * a given month
 * @param month
 * @param leapYear
 * @return int
 */
int Date::maxDays(int month, bool leapYear){
    int days = 0;
    switch(month){
        case 2:
            if(leapYear){
                days = 29;
            } else {
                days = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }
    return days;
}


/**
 * Returns a date object
 * that is in the past
 * determined by count
 * @param count
 * @return Date
 */
Date Date::subDays(int count){
    int currMon = getMonth();
    int currDay = getDay();
    int currYear = getYear();

    bool leapYear = isLeapYear(currYear);

    while(count != 0){
        if(currDay != 0){
            currDay--;
            count--;
        } else {
            if(currMon != 0){
                currMon--;
                currDay = maxDays(currMon, leapYear)-1;
                count--;
            } else {
                currYear--;
                currMon = 11;
                leapYear = isLeapYear(currYear);
                currDay = maxDays(currMon, leapYear)-1;
                count--;
            }
        }
    }
    Date out(currMon, currDay, currYear);
    return out;
}
