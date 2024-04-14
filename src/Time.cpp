//
// Created by OSAMA ASHRAF on 4/6/2024.
//
#include "../include/Time.h"
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
// Global Functions
void toggle(string &period) {
    if (period == "AM") period = "PM";
    else period = "AM";
}
string timeFormat(int x, bool isHour = false){
    ostringstream oss;
    if(x < 10 && !isHour)
        oss << 0;
    oss<< x;

    return oss.str();
}

// Constructors
Time::Time(int hours, int minutes, int seconds, string period) :
        seconds(seconds), minutes(minutes), hours(hours), period(period) {}

Time::Time() : Time(0, 0, 0, "AM") {}


// Getters
int Time::getSeconds() const { return seconds; }

int Time::getMinutes() const { return minutes; }

int Time::getHours() const { return hours; }

string Time::getPeriod() const { return period; }


// Setters
bool Time::setSeconds(int s) { return !(s > 59 || s < 1) && (seconds = s); }

bool Time::setMinutes(int m) { return !(m > 59 || m < 1) && (minutes = m); }

bool Time::setHours(int h) { return !(h > 24 || h < 1) && (hours = h); }

bool Time::setPeriod(string p) { return (p == "AM" || p == "PM") && (period = p, true); }


// Methods
bool Time::isValid() {
    if (setSeconds(seconds) && setMinutes(minutes) && setHours(hours) && setPeriod(period))
        return true;

    return false;
}

void Time::addSeconds(int s) {
    int sum = seconds + s;

    seconds = sum % 60;
    addMinutes(sum / 60);
}

void Time::addMinutes(int m) {
    addHours((minutes + m) / 60);
    minutes = (minutes + m) % 60;
}

void Time::addHours(int h) {
    while (h--) {
        hours++;

        if (hours == 12)
            toggle(period);

        if (hours > 12)
            hours -= 12;
    }
}

string Time::toString(string format, string separator) {
    vector<pair<int, string>> index;

    int h_index = format.find("hh"), m_index = format.find("mm"), s_index = format.find("ss");

    if (h_index + 1)
        index.emplace_back(h_index, timeFormat(hours, true));
    if (m_index + 1)
        index.emplace_back(m_index, timeFormat(minutes));
    if (s_index + 1)
        index.emplace_back(s_index, timeFormat(seconds));

    sort(index.begin(), index.end());

    ostringstream oss;
    for (int i = 0; i < index.size(); i++)
        oss << index[i].second << (i < index.size() - 1 ? separator : " ");
    oss << period;

    return oss.str();
}