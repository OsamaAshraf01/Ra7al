
// Created by Ahmed Hamdy Kotp

#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
#include <fstream> 
#include "../include/CSVManager.h"
using namespace std;
class Currency {
private:
    string currencyCode;
    long amount;

public:
    // Constructors
    static map<string, double> exchangeRates;

    Currency();
    Currency(const string& code, long amt);

    // Input/Output Friends
    friend ostream& operator<<(ostream& os, const Currency& c);
  

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

