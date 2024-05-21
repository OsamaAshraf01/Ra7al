//
// Created by OSAMA ASHRAF on 3/23/2024.
//
/* ========Validation========
    #include "Date.h"

    Date d;
    int day, month, year;
    do{
        cin>>day>>month>>year;
        d = {day, month, year};
    } while(!d.isValid() && cout<<"Enter valid date!\n");


  ========Adding========
  Date d{1, 1, 2003};
  d.addYears(3);
  d.addMonths(1);
  d.addDays(28);
  cout<<d.toString();

  ========Distance========
  Date d1{1, 1, 2000};
  Date d2{1, 1, 2005};
  cout<<d1.calcDistance(d2);

*/

#ifndef RA7AL_DATE_H
#define RA7AL_DATE_H
#include <string>
#include "Duration.h"
using namespace std;

class Date
{
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
    bool setDay(int _day);
    bool setMonth(int _month);
    bool setYear(int _year);

    // Methods
    string toString(string format = "DD.MM.YYYY", string separator = "/");
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);

    bool isValid() const;
    Duration calcDistance(Date other);
};

#endif // RA7AL_DATE_H
