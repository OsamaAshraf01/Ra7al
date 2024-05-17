//Created By Ahmed Hamdy Kotp

#ifndef Budget_H
#define Budget_H
#include <string>
#include <map>


using namespace std;
class Budget  {
private :
	map<string, double> categories;
    double total_budget;
public :
    //Constructor
    Budget();
    Budget(map<string, double>& categories);
    //setters
    void setBudget(double amount);

    //getters
    double getTotalSpent() const;
    double getRemaining() const;
    double getBalance(const string& category_name) const;
    double getTotalBudget() const;

    //methods
    void spend(const string& category_name, double amount);
    void add_category(const string& category_name, double amount);
    void deposit(const string& category_name, double amount);
    void overview() const;
    void advice() const;
};

#endif 
