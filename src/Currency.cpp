//created by Ahmed Hamdy Kotp

#include "Currency.h"
std::map<string, double> Currency::exchangeRates;
CSVManager Currency::csvManager("../data/currencies.csv");
// Constructors
Currency::Currency() : currencyCode("USD"), amount(0) {
    initializeExchangeRates();
}

Currency::Currency(const string& code, long amt) : currencyCode(code), amount(amt) {
    initializeExchangeRates();
}

// Arithmetic Operators
Currency Currency::operator+(const Currency& other) const {
    if (currencyCode != other.currencyCode) {
        throw invalid_argument("Currency codes do not match.");
    }
    long newAmount = amount + other.amount;
    checkForOverflow(newAmount);
    return Currency(currencyCode, newAmount);
}

Currency Currency::operator-(const Currency& other) const {
    if (currencyCode != other.currencyCode) {
        throw invalid_argument("Currency codes do not match.");
    }
    long newAmount = amount - other.amount;
    checkForOverflow(newAmount);
    return Currency(currencyCode, newAmount);
}

Currency Currency::operator*(double factor) const {
    double newAmount = amount * factor;
    checkForOverflow(static_cast<long>(newAmount));
    return Currency(currencyCode, static_cast<long>(newAmount));
}

Currency Currency::operator/(double factor) const {
    if (factor == 0) {
        throw invalid_argument("Division by zero.");
    }
    double newAmount = amount / factor;
    checkForOverflow(static_cast<long>(newAmount));
    return Currency(currencyCode, static_cast<long>(newAmount));
}

// Comparison Operators
bool Currency::operator==(const Currency& other) const {
    return currencyCode == other.currencyCode && amount == other.amount;
}

bool Currency::operator!=(const Currency& other) const {
    return !(*this == other);
}

bool Currency::operator<(const Currency& other) const {
    if (currencyCode != other.currencyCode) {
        throw invalid_argument("Currency codes do not match.");
    }
    return amount < other.amount;
}

bool Currency::operator>(const Currency& other) const {
    return other < *this;
}

bool Currency::operator<=(const Currency& other) const {
    return !(other > *this);
}

bool Currency::operator>=(const Currency& other) const {
    return !(*this < other);
}

// Input/Output Friends
ostream& operator<<(ostream& os, const Currency& c) {
    os << c.currencyCode << " " << c.amount;
    return os;
}

istream& operator>>(istream& is, Currency& c) {
    is >> c.currencyCode >> c.amount;
    if (!c.validateCurrencyCode(c.currencyCode)) {
        throw invalid_argument("Invalid currency code.");
    }
    return is;
}

// Conversion Metho
void Currency::convert(const string& newCode) {
    if (!validateCurrencyCode(newCode)) {
        throw std::invalid_argument("Invalid currency code.");
    }
    double exchangeRate = getExchangeRate(newCode);
    amount = static_cast<long>(amount * exchangeRate);
    currencyCode = newCode;
}

// Other Potential Methods
double Currency::getExchangeRate(const string& otherCode) {
    initializeExchangeRates();
    auto it = exchangeRates.find(otherCode);
    if (it == exchangeRates.end()) {
        throw std::invalid_argument("Exchange rate not found.");
    }
    return it->second;
}

// Error Handling
bool Currency::validateCurrencyCode(const string& code) const {
    return exchangeRates.find(code) != exchangeRates.end();
}

void Currency::checkForOverflow(long newAmount) const {
    if (newAmount > LONG_MAX || newAmount < LONG_MIN) {
        throw overflow_error("Currency amount overflow.");
    }
}

// Getters and Setters
void Currency::setCurrencyCode(const string& code) {
    if (!validateCurrencyCode(code)) {
        throw invalid_argument("Invalid currency code.");
    }
    currencyCode = code;
}

void Currency::setAmount(long amt) {
    checkForOverflow(amt);
    amount = amt;
}
// Static method to initialize exchange rates from the CSV file
void Currency::initializeExchangeRates() {
    if (exchangeRates.empty()) {
        auto data = csvManager.readCSV();
        for (const auto& row : data) {
            if (row.size() == 2) {
                exchangeRates[row[0]] = stod(row[1]);
            }
        }
    }
}

