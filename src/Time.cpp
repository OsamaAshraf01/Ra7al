//
// Created by OSAMA ASHRAF on 4/6/2024.
//

#include "../include/Time.h"

// Constructors
Time::Time(int seconds, int minutes, int hours, string period):
    seconds(seconds), minutes(minutes), hours(hours), period(period) {}

Time::Time(): Time(0, 0, 0, "AM") {}


// Getters
int Time::getSeconds() const{return seconds;}
int Time::getMinutes() const{return minutes;}
int Time::getHours() const{return hours;}


// Setters
bool Time::setSeconds(int s){return !(s > 59 || s < 1) && (seconds = s);}
bool Time::setMinutes(int m){return !(m > 59 || m < 1) && (minutes = m);}
bool Time::setHours(int h){return !(h > 24 || h < 1) && (hours = h);}


// Methods
