//Craeted By Ahmed Hamdy Kotp



#include "../include/Budget.h"
#include <iostream>
#include "Budget.h"
#include <iostream>
#include <iomanip>

// Constructor
Budget::Budget() : total_budget(0.0)
{
}

// set a new budget category
void Budget::add_category(const string& category_name, double amount) {
    categories[category_name] = amount;
    total_budget += amount;
}

// Gets the balance of a specific category
double Budget::getBalance(const string& category_name) const {
    auto findd = categories.find(category_name);
    if (findd != categories.end()) {
        return findd->second;
    }
    else {
        return 0.0;
    }
}

// set spending within a category
void Budget::spend(const string& category_name, double amount) {
    auto spen = categories.find(category_name);
    if (spen != categories.end()) {
        spen->second -= amount;
        if (spen->second < 0) {
            spen->second = 0;
        }
    }
}

// set a deposit to a category
void Budget::deposit(const string& category_name, double amount) {
    auto dep = categories.find(category_name);
    if (dep != categories.end()) {
        dep->second += amount;
    }
    else {
        categories[category_name] = amount; // this will create a new category
    }
    total_budget += amount;
}

// Calculates the total amount spent
double Budget::getTotalSpent(double& total) const {
    total = 0.0;
    for (const auto& item : categories) {
        total += (item.second - categories.at(item.first));
    }
    return total;
}

// Gets the overall remaining budget
double Budget::getRemaining() const {
    return total_budget - getTotalSpent(total_budget);
}

// Provides a formatted overview of the budget
void Budget::overview() const {
    cout << "Budget Overview:\n";
    cout << "----------------\n";
    for (const auto& item : categories) {
        cout << fixed << setprecision(2); // Set precision for currency
        cout << item.first << ": $" << item.second << endl;
    }
    cout << "Total Budget: $" << total_budget << endl;
}

// Offers basic budget advice 
void Budget::advice() const {
    double total_spent = 0.0;
    double spent = getTotalSpent(total_spent);
    if (spent > total_budget * 0.8) {
        cout << "Warning: You've spent over 80% of your budget. Consider reducing expenses.\n";
    }
    else {
        cout << "Your budget looks healthy.\n";
    }
}
