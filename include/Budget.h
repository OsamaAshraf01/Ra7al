//Created By Ahmed Hamdy Kotp

#ifndef Budget_H
#define Budget_H
#include <string>
#include <map>


using namespace std;
class Budget :  Person {
private :
	map<string, double> categories;
    double total_budget;
public :
    //Constructor
    Budget();

    //setters
    void add_category(const string& category_name);
    void deposit(const string& category_name, double amount);

    //getters
    double getTotalSpent() const;
    double getRemaining() const;
    double getBalance(const string& category_name) const;
    //methods
    void spend(const string& category_name, double amount);
    void overview() const;
    void advice() const;
};

#endif 
