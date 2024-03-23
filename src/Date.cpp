//
// Created by OSAMA ASHRAF on 23/3/2024.
//

#include "../include/Date.h"
#include <bits/stdc++.h>
using namespace std;

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

double Date::getDay() const {return this->day;}
double Date::getMonth() const {return this->month;}
double Date::getYear() const {return this->year;}
void Date::setDay(int _day) {this->day = _day;}
void Date::setMonth(int _month) {this->month = _month;}
void Date::setYear(int _year) {this->year = _year;}


string Date::toString(string format, string separator) {  // "DD.MM.YYYY"
    vector<pair<int, int>> index;

    int d_index = format.find("DD"), m_index = format.find("MM"), y_index = format.find("YYYY");

    if(d_index+1)
        index.emplace_back(d_index, this->day);
    if(m_index + 1)
        index.emplace_back(m_index, this->month);
    if(y_index + 1)
        index.emplace_back(y_index, this->year);

    sort(index.begin(), index.end());

    ostringstream oss;
    for(int i=0 ; i<index.size() ; i++)
        oss << index[i].second << (i<index.size()-1 ? separator : "");

    return oss.str();
}
