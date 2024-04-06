//
// Created by OSAMA ASHRAF on 4/6/2024.
//
/*------Printing-------
    Time t(5, 0, 0, "AM");
    cout<<t.toString()<<'\n';    // 5:00:00 AM

  ------Adding------
    t.addHours(7);
    t.addMinutes(30);
    t.addSeconds(40);
    cout << t.toString("hh:mm") <<'\n';   // 12:30 PM
 */
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
    string getPeriod() const;

    // Setters
    bool setSeconds(int s);
    bool setMinutes(int m);
    bool setHours(int h);
    bool setPeriod(string p);

    // Methods
    bool isValid();
    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    string toString(string format="hh:mm:ss", string separator=":");
};


#endif //RA7AL_TIME_H
