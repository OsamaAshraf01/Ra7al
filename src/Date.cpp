//
// Created by OSAMA ASHRAF on 23/3/MAX_YEAR.
//

#include "../include/Date.h"
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int MAX_YEAR = 2024;
int MIN_YEAR = 1800;

// Global Functions
bool isLeap(int year){
    return !(year % 4);
}
int dayLimit(int month, int year){
    if ((month == 4 || month == 6 || month == 9 || month == 11))
        return 30;
    else if (month == 2 && isLeap(year))
        return 29;
    else if (month == 2 && !isLeap(year))
        return 28;

    return 31;
}


// Constructors
Date::Date() {
    this->day=0;
    this->month=0;
    this->year=0;
}
Date::Date(int DD, int MM, int YYYY) {
    this->day=DD;
    this->month=MM;
    this->year=YYYY;
}

// Getters
double Date::getDay() const {return day;}
double Date::getMonth() const {return month;}
double Date::getYear() const {return year;}

// Setters
bool Date::setDay(int d) {return !(d > dayLimit(month, year) || d < 1) && (day=d);}
bool Date::setMonth(int m) {return !(m > 12 || m < 1) && (month=m);}
bool Date::setYear(int y) {return !(y > MAX_YEAR || y < MIN_YEAR) && (year=y);}

// Methods
string Date::toString(string format, string separator) {  // "DD.MM.YYYY"
    vector<pair<int, int>> index;

    int d_index = format.find("DD"), m_index = format.find("MM"), y_index = format.find("YYYY");

    if (d_index + 1)
        index.emplace_back(d_index, this->day);
    if (m_index + 1)
        index.emplace_back(m_index, this->month);
    if (y_index + 1)
        index.emplace_back(y_index, this->year);

    sort(index.begin(), index.end());

    ostringstream oss;
    for (int i = 0; i < index.size(); i++)
        oss << index[i].second << (i < index.size() - 1 ? separator : "");

    return oss.str();
}

bool Date::isValid() const {
    // Checking Year
    if (year > MAX_YEAR || year < MIN_YEAR)
        return false;


    // Checking Month
    if (month > 12 || month < 1)
        return false;


    // Checking Day
    if (day > dayLimit(month, year) || day < 1)
        return false;

    return true;
}

void Date::addDays(int days) {
    int sum = day + days;
    while(sum > dayLimit(month, year)){
        sum -= dayLimit(month, year);
        month++;

        if(month > 12){
            month -= 12;
            year++;
        }
    }
    day = sum;
}

void Date::addMonths(int months) {
    int sum = month + months;
    while(sum > 12){
        sum -= 12;
        year++;
    }
    month = sum;
}

void Date::addYears(int years) {
    year += years;
}

Duration Date::calcDistance(Date other) {
    int days = 0, months = 0, years = 0;
    Date copy = *this;

    if (year == other.year && month == other.month && day == other.day)
        return {};

    if (year > other.year || (year == other.year && month > other.month) || (year == other.year && month == other.month && day > other.day)){
        Date temp = *this;
        *this = other;
        other = temp;
    }

    while (year < other.year || month < other.month || day < other.day){
        days++;
        day++;
        if (day > dayLimit(month, year)){
            day = 1;
            month++;
            if (month > 12){
                month = 1;
                year++;
            }
        }
    }
    int virtualMonth=1, virtualYear=1;
    while (days >= dayLimit(virtualMonth, virtualYear)){
        months++;
        days -= dayLimit(virtualMonth, virtualYear);
        virtualMonth++;
        if (virtualMonth > 12){
            virtualMonth = 1;
            virtualYear++;
        }
    }

    while (months >= 12){
        years++;
        months -= 12;
    }

    *this = copy;

    return {0, 0, 0, days, months, years};
}