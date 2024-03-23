//
// Created by OSAMA ASHRAF on 3/23/2024.
//

#ifndef RA7AL_DATE_H
#define RA7AL_DATE_H
#include <string>
using namespace std;

class Date {
    /* TODO: Date Validity
     * TODO: Add days, months, years (%)
     * TODO: Distance between two dates
     */
private:
    int day, month, year;
public:
    // Constructors
    Date();
    Date(int DD, int MM, int YYYY);

    double getDay() const;
    double getMonth() const;
    double getYear() const;

    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);

    string toString(string format="DD.MM.YYYY", string separator="/");
};


#endif //RA7AL_DATE_H
