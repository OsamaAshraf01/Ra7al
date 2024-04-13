//created By Ahmed Hamdy Kotp


#ifndef CURRENCY_H
#define CURRENCY_H

#include "../include/DataFrame/CSVManager.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;
class Currency {
private:
    string currencyCode;
    long amount;
    static map<string, double> exchangeRates;
    static CSVManager csvManager;

public:
    // Constructors
    Currency();
    Currency(const string& code, long amt);

    // Arithmetic Operators
    Currency operator+(const Currency& other) const;
    Currency operator-(const Currency& other) const;
    Currency operator*(double factor) const;
    Currency operator/(double factor) const;

    // Comparison Operators
    bool operator==(const Currency& other) const;
    bool operator!=(const Currency& other) const;
    bool operator<(const Currency& other) const;
    bool operator>(const Currency& other) const;
    bool operator<=(const Currency& other) const;
    bool operator>=(const Currency& other) const;

    // Input/Output Friends
    friend ostream& operator<<(ostream& os, const Currency& c);
    friend istream& operator>>(istream& is, Currency& c);

    // Conversion Method
    void convert(const string& newCode);

    // Other Potential Methods
    static double getExchangeRate(const string& otherCode);

    // Error Handling
    bool validateCurrencyCode(const std::string& code) const;
    void checkForOverflow(long newAmount) const;

    // Getters and Setters
    string getCurrencyCode() const { return currencyCode; }
    long getAmount() const { return amount; }
    void setCurrencyCode(const string& code);
    void setAmount(long amt);

    // Static Methods for CSV Operations
    static void initializeExchangeRates();
};

#endif // CURRENCY_H
