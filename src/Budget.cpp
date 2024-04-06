//created By Ahmed Hamdy Kotp



#include "Budget.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor 
Budget::Budget() : total_budget(0.0) {}

// Add a new budget category or update an existing one
void Budget::add_category(const string& category_name) {
    categories[category_name] = 0.0;
}

// Get the balance of a specific category
double Budget::getBalance(const string& category_name) const {
    auto bal = categories.find(category_name);
    return bal != categories.end() ? bal->second : 0.0;
}

// Spend from a category
void Budget::spend(const string& category_name, double amount) {
    if (categories[category_name] >= amount) {
        categories[category_name] -= amount; total_budget -= amount;
    }
}

// Deposit to a category
void Budget::deposit(const string& category_name, double amount) {
    categories[category_name] += amount;
    total_budget += amount;
}

// Calculate the total amount spent
double Budget::getTotalSpent() const {
    double total = 0.0;
    for (const auto& item : categories) {
        total += item.second;
    }
    return total;
}

// Get the overall remaining budget
double Budget::getRemaining() const {
    return total_budget - getTotalSpent();
}

// Provide a formatted overview of the budget
void Budget::overview() const {
    cout << fixed << setprecision(2);
    cout << "Budget Overview:\n----------------\n";
    for (const auto& item : categories) {
        cout << item.first << ": $" << item.second << '\n';
    }
    cout << "Total Budget: $" << total_budget << '\n';
}

// Offer basic budget advice
void Budget::advice() const {
    double spent = getTotalSpent();
    if (spent > total_budget * 0.8) {
        cout << "Warning: You've spent over 80% of your budget. Consider reducing expenses.\n";
    }
    else {
        cout << "Your budget looks healthy.\n";
    }
}
