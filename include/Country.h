//created by Ahmed Hamdy Kotp

#ifndef COUNTRYINFO_H
#define COUNTRYINFO_H

#include "../include/DataFrame/CSVManager.h" // Include the CSVManager header
#include <string>
#include <vector>

// Use the standard namespace
using namespace std;

class CountryInfo {
private:
    string countryName;
    string officialLanguage;
    string currency;
    long population;
    string capitalCity;
    double area; 
    string countryCode; 
    string region; 
    string localTimezone;
    vector<string> popularCities;
    vector<string> touristAttractions;
    CSVManager csvManager; // CSVManager object to handle CSV operations

public:
    CountryInfo(const string& csvFilePath, const string& countryName);
    void loadFromCSV(const string& csvFilePath);
    string getOfficialLanguage() const;
    string getCurrency() const;
    string getCapitalCity() const;
    double getArea() const;
    string getLocalTimezone() const;

    // Additional method to interact with the CSVManager
    void loadCountryInfoFromCSV();
};

#endif // COUNTRYINFO_H
