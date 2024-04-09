#ifndef Budget_H
#define Budget_H
#include <string>
#include <vector>
#include <map>

using namespace std;


class Budget
{
private :
	map<string, double> categories;

public :
//constructors
    Budget();
    Budget(map<string, double> &categories);
    double total_budget;
//Methods
    void add_category(const string& category_name, double amount);
    double getBalance(const string& category_name) const;
    void spend(const string& category_name, double amount);
    void deposit(const string& category_name, double amount);
    double getTotalSpent(double &total) const;
    double getRemaining() const;
    void overview() const;
    void advice() ;
};

#endif 
