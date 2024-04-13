//created by Ahmed Hamdy Kotp

#include "../include/Country.h"
#include "../include/CSVManager.h"
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Constructor
CountryInfo::CountryInfo(const string& csvFilePath, const string& name)
    : countryName(name), csvManager(csvFilePath, ',') {
    loadCountryInfoFromCSV();
}

// Method to load country information from a CSV file
void CountryInfo::loadFromCSV(const string& csvFilePath) {
    csvManager = CSVManager(csvFilePath, ',');
    loadCountryInfoFromCSV();
}

// Getters for the private attributes
string CountryInfo::getOfficialLanguage() const { return officialLanguage; }
string CountryInfo::getCurrency() const { return currency; }
string CountryInfo::getCapitalCity() const { return capitalCity; }
double CountryInfo::getArea() const { return area; }
string CountryInfo::getLocalTimezone() const { return localTimezone; }

// Method to interact with the CSVManager and load data into the CountryInfo object
void CountryInfo::loadCountryInfoFromCSV() {
    vector<vector<string>> data = csvManager.readCSV();

    for (const auto& row : data) {
        if (row[0] == countryName) { // Match the country name
            officialLanguage = row[1];
            currency = row[2];
            capitalCity = row[3];
            area = stod(row[4]);
            localTimezone = row[5];
            population = row[6];
            break;
        }
    }
}

