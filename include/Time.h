//
// Created by OSAMA ASHRAF on 4/6/2024.
//

#ifndef RA7AL_TIME_H
#define RA7AL_TIME_H
#include <iostream>
using namespace std;

class Time {
private:
    int seconds, minutes, hours;
    string period;
public:
    // Constructors
    Time();
    Time(int seconds, int minutes, int hours, string period);

    // Getters
    int getSeconds() const;
    int getMinutes() const;
    int getHours() const;

    // Setters
    bool setSeconds(int s);
    bool setMinutes(int m);
    bool setHours(int h);

    // Methods
    bool isValid();
    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    string toString();
};


#endif //RA7AL_TIME_H
