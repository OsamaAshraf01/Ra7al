//created By Ahmed Hamdy Kotp



#include "headers/Budget.h"
#include <iostream>
#include <iomanip>
#include "headers/Budget.h"
using namespace std;

// Constructor 
Budget::Budget() : total_budget(0.0) {} 
Budget::Budget(map<string, double>& categories) : categories(categories), total_budget(0.0) {
    for (const auto& item : categories) {
        total_budget += item.second;
    }
}

// Add a new budget category or update an existing one
void Budget::add_category(const string& category_name, double amount){
    for (auto& x : categories) {
        if (category_name != x.first) {
            categories[category_name] = 0.0;
        }
        else {
            cout<<"THis category is already exist !\n" ;
        }
    }
}

// Get the balance of a specific category
double Budget::getBalance(const string& category_name) const {
    auto bal = categories.find(category_name);
    return bal != categories.end() ? bal->second : -1;
}

// Spend from a category
void Budget::spend(const string& category_name, double amount) {
    auto it = categories.find(category_name);  // Use map::find for efficient lookup

    if (it != categories.end()) { // Category found
        if (it->second >= amount) { 
            it->second -= amount;
            total_budget = getRemaining(); 
        } else {
            // Handle insufficient funds if needed (not shown in the original code)
        }
    } else {
        cout << "Error: Category '" << category_name << "' not found." << endl;
    }
}


void Budget::deposit(const string& category_name, double amount) {
    auto it = categories.find(category_name);

    if (it != categories.end()) { 
        it->second += amount;
        total_budget += amount;
    } else {
        cout << "Error: Category '" << category_name << "' not found." << endl;
    } 
}

// Calculate the total amount spent
double Budget::getTotalSpent() const {
    return total_budget - getRemaining();
}


// Get the overall remaining budget
double Budget::getRemaining() const {
    double totalRemaining = 0.0;
    for (const auto& item : categories) {
        totalRemaining += item.second; 
    }
    return totalRemaining;
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
void Budget::advice()  const{
    double spent = getTotalSpent();
    if (spent > total_budget * 0.8) {
        cout << "Warning: You've spent over 80% of your budget. Consider reducing expenses.\n";
    }
    else {
        cout << "Your budget looks healthy.\n";
    }
}
