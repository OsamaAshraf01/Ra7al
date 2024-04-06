//
// Created by OSAMA ASHRAF on 3/23/2024.
//

#ifndef RA7AL_DATE_H
#define RA7AL_DATE_H
#include <string>
using namespace std;

class Date {
    /*
     * TODO: Distance between two dates
     */
private:
    int day, month, year;
public:
    // Constructors
    Date();
    Date(int DD, int MM, int YYYY);

    // Getters
    double getDay() const;
    double getMonth() const;
    double getYear() const;

    // Setters
    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);

    // Methods
    string toString(string format="DD.MM.YYYY", string separator="/");
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);

    bool isValid() const;
    //Duration calcDistance(Date other);
};


#endif //RA7AL_DATE_H
