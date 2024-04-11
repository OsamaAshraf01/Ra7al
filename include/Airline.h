#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Airline {
private:
    string name;
    double maxWeight;
    vector<string> availableFlights;
    vector<string> availableAirports;
    vector<string> supportedCountries;

public:
    // Constructor
    Airline();

    // setters
    void setName(string& Name);
    void setMaxWeight(double MaxWeight);
    void setAvailableFlights(string& AvailableFlights);
    void setAvailableAirports(string& AvailableAirports);
    void setSupportedCountries(string& SupportedCountries);

    // getters
    string getName();
    double getMaxWeight() const;
    vector<string> getAvailableFlights();
    vector<string> getAvailableAirports();
    vector<string> getSupportedCountries();

    // method
    void printDetails();
};

#endif // AIRLINE_H






