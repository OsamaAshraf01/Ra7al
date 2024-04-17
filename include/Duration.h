//
// Created by OSAMA ASHRAF on 4/15/2024.
//
/*=========Examples===========
    Duration d1(0, 0, 13);
    Duration d2(24, 0, 12);

    cout << (d1 + d2);

=================================



 */

#ifndef RA7AL_DURATION_H
#define RA7AL_DURATION_H
#include <string>
#include <sstream>
#include "../public/functions.h"
using namespace std;

class Duration {
private:
    int seconds, minutes, hours, days, months, years;

public:
    // Constructors
    Duration(int seconds=0, int minutes=0, int hours=0, int days=0, int months=0, int years=0);


    // Getters
    int getSeconds();
    int getMinutes();
    int getHours();
    int getDays();
    int getMonths();
    int getYears();

    // Methods
    string toString();


    // Operators
    Duration operator +(Duration& other);
    Duration operator -(Duration& other);
    bool operator ==(Duration& other);
    bool operator !=(Duration& other);
    bool operator <=(Duration& other);
    bool operator >=(Duration& other);
    bool operator >(Duration& other);
    bool operator <(Duration& other);

    friend ostream& operator <<(ostream& os, Duration other);

};


#endif //RA7AL_DURATION_H
