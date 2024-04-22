//
// Created by OSAMA ASHRAF on 4/15/2024.
//

#include "headers/Duration.h"


// Constructors
Duration::Duration(int seconds, int minutes, int hours, int days, int months, int years) : seconds(seconds),
                                                                                           minutes(minutes),
                                                                                           hours(hours), days(days),
                                                                                           months(months),
                                                                                           years(years) {}



// Duration::getters
int Duration::getSeconds() {return seconds;}

int Duration::getMinutes() {return minutes;}

int Duration::getHours() {return hours;}

int Duration::getDays() {return days;}

int Duration::getMonths() {return months;}

int Duration::getYears() {return years;}

// Methods
string Duration::toString() {
    ostringstream oss;
    if(years)
        oss << years << " years, ";
    if(months)
        oss << months << " months, ";
    if(days)
        oss << days << " days, ";
    if(hours)
        oss << hours << " hours, ";
    if(minutes)
        oss << minutes << " minutes, ";
    if(seconds)
        oss << seconds << " seconds";

    string result = strip(oss.str(), ", ");

    return result;
}


// Duration::operators
ostream& operator << (ostream& os, Duration d){
    os << d.toString();
    return os;
}

Duration Duration::operator+(Duration &other) {
    int secondsSum = seconds + other.seconds;
    int minutesSum = minutes + other.minutes + secondsSum / 60;
    int hoursSum = hours + other.hours + minutesSum / 60;
    int daysSum = days + other.days + hoursSum / 24;
    int monthsSum = months + other.months + daysSum / 30;
    int yearsSum = years + other.years + monthsSum / 12;

    int tempSeconds = secondsSum % 60;
    int tempMinutes = minutesSum % 60;
    int tempHours = hoursSum % 24;
    int tempDays = daysSum % 30;
    int tempMonths = monthsSum % 12;
    int tempYears = yearsSum;

    return {tempSeconds, tempMinutes, tempHours, tempDays, tempMonths, tempYears};
}

Duration Duration::operator-(Duration &other) {
    if (other > *this)
        return {};
    int secondsDiff = seconds - other.seconds;
    int minutesDiff = minutes - other.minutes + (secondsDiff < 0 ? -1 : 0);
    int hoursDiff = hours - other.hours + (minutesDiff < 0 ? -1 : 0);
    int daysDiff = days - other.days + (hoursDiff < 0 ? -1 : 0);
    int monthsDiff = months - other.months + (daysDiff < 0 ? -1 : 0);
    int yearsDiff = years - other.years + (monthsDiff < 0 ? -1 : 0);

    int tempSeconds = (secondsDiff + 60) % 60;
    int tempMinutes = (minutesDiff + 60) % 60;
    int tempHours = (hoursDiff + 24) % 24;
    int tempDays = (daysDiff + 30) % 30;
    int tempMonths = (monthsDiff + 12) % 12;
    int tempYears = yearsDiff;

    return {tempSeconds, tempMinutes, tempHours, tempDays, tempMonths, tempYears};
}

bool Duration::operator==(Duration &other) {
    return years == other.years && months == other.months && days == other.days && hours == other.hours &&
           minutes == other.minutes && seconds == other.seconds;
}

bool Duration::operator!=(Duration &other) {
    return !(*this == other);
}

bool Duration::operator<=(Duration &other) {
    return !(*this > other);
}

bool Duration::operator>=(Duration &other) {
    return !(*this < other);
}

bool Duration::operator<(Duration &other) {
    return !(*this > other) && !(*this == other);
}

bool Duration::operator>(Duration &other) {
    if(years > other.years)
        return true;
    if(years < other.years)
        return false;

    if(months > other.months)
        return true;
    if(months < other.months)
        return false;

    if(days > other.days)
        return true;
    if(days < other.days)
        return false;

    if(hours > other.hours)
        return true;
    if(hours < other.hours)
        return false;

    if(minutes > other.minutes)
        return true;
    if(minutes < other.minutes)
        return false;

    if(seconds > other.seconds)
        return true;
    if(seconds < other.seconds)
        return false;

    return false;
}

