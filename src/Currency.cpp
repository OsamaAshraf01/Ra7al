//Created By Ahmed Hamdy Kotp


#include "../include/Currency.h"
#include <sstream> 
#include <algorithm> 
#include <cmath>
#include <limits> 
#include <fstream> 
using namespace std;

// Static member initialization
map<string, double> Currency::exchangeRates;

// Constructors
Currency::Currency() : currencyCode("USD"), amount(0) {} // Default to USD

Currency::Currency(const string& code, long amt) {
    setCurrencyCode(code); // Reuse setCurrencyCode for validation
    setAmount(amt);
}

// Output operator
ostream& operator<<(ostream& os, const Currency& c) {
    os << c.currencyCode << " " << c.amount;
    return os;
}

// Conversion Method
void Currency::convert(const string& newCode) {
    if (currencyCode == newCode) {
        return;  // Already the same currency
    }

    double rate = Currency::getExchangeRate(newCode);
    amount = static_cast<long>(round(amount * rate));
    currencyCode = newCode;
}

// Static method to fetch an exchange rate
double Currency::getExchangeRate(const string& otherCode) {
    auto G = exchangeRates.find(otherCode);

    if (G != exchangeRates.end()) {
        return G->second; // Rate found
    }
    else {
        cout<<"Exchange rate not found for code: " << otherCode;
    }
}

// Error Handling
bool Currency::validateCurrencyCode(const string& code) const {
    // For simplicity, let's assume only 3-letter uppercase codes
    return code.length() == 3;
}

void Currency::checkForOverflow(long newAmount) const {
    // Adjust this logic to your overflow handling preference
    if (newAmount >LLONG_MAX ||
        newAmount < LLONG_MIN) {
        cout<<"Currency arithmetic overflow";
    }
}

// Getters and Setters (with validation)
void Currency::setCurrencyCode(const string& code) {
    if (!validateCurrencyCode(code)) {
        cout<<"Invalid currency code";
    }
    currencyCode = code;
}

void Currency::setAmount(long amt) {
    checkForOverflow(amt);
    amount = amt;
}

// Initialize exchange rates from CSV
void Currency::initializeExchangeRates() {

    CSVManager csv("../data/currencies.csv");
    vector<vector<string>> exchangeData = csv.read();
    if (!exchangeData.empty()) {
        exchangeData.erase(exchangeData.begin());
    }
    for (const vector<string>& row : exchangeData) {
        if (row.size() >= 2) {
            exchangeRates[row[0]] = stod(row[1]);
        }
    }
}

