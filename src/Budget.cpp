// Created By Ahmed Hamdy Kotp at 3/23/2024

#include "Budget.h"
#include <iostream>
#include <limits>


//constructor fuunction for the class
Budget::Budget() : total_budget(0.0) {
}
//setters
void Budget::add_category(const string& category_name, double amount)
{
    if (categories.count(category_name) > 0) {
        cout << "Category '" << category_name << "' actually exists." << endl;
    }
    else {
        categories[category_name] = amount;
        total_budget += amount;
    }
}

double Budget::getBalance(const string& category_name) const
{
    auto it = categories.find(category_name);
    if (it == categories.end()) {
        cout << "Category '" << category_name << "' does not exist." << endl;
        return 0.0;
    }
    else {
        return it->second;
    }
}
double total_spent = 0;
void Budget::spend(const string& category_name, double amount)
{
    auto it = categories.find(category_name);
    if (it == categories.end()) {
        cout << "Category '" << category_name << "' does not exist." << endl;
        return;
    }

    if (amount > it->second) {
        cout << "Insufficient funds in '" << category_name << "'." << endl;
    }
    else {
        it->second -= amount;
        total_spent += amount;
    }
}

void Budget::deposit(const string& category_name, double amount)
{   
    auto de = categories.find(category_name);
    if (de == categories.end()) {
        cout << "No category called : " << category_name << endl;

    }return;
    de->second += amount;
    total_budget += amount;
}
//getters
double Budget::getTotalSpent(double &total) const {
    total += total_spent;
    return total;
}


double Budget::getRemaining() const
{
    return total_budget - getTotalSpent(total_spent);
}

void Budget::overview() const
{
    std::cout << "Budget Overview:\n";
    for (const auto& item : categories) {
        cout << "- " << item.first << ": $" << item.second << endl;
    }
    cout << "Total Budget: $" << total_budget << endl;
    cout << "Total Spent: $" << getTotalSpent(total_spent) << endl;
    cout << "Remaining: $" << getRemaining() << endl;
}
//advices
void Budget::advice() const
{
    double remaining = getRemaining();
    if (remaining > 0) {
        cout << "Keep up the good work! You're staying within your budget.\n";
    }
    else if (remaining == 0) {
        cout << "You've used up your entire budget. Be mindful of your spending next time.\n";
    }
    else {
        cout << "You've overspent by $" << abs(remaining) << ". Time to re-evaluate!\n";
    }
}
