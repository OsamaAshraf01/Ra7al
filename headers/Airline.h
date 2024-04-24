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
    Airline(const string& name, double maxWeight,const vector<string>& availableFlights, const vector<string>& availableAirports, const vector<string>& supportedCountries);
    // setters
    void setName(string& Name);
    void setMaxWeight(double MaxWeight);
    void setAvailableFlights(string& AvailableFlights);
    void setAvailableAirports(string& AvailableAirports);
    void setSupportedCountries(string& SupportedCountries);

    // getters
    string getName()const;
    double getMaxWeight() const;
    vector<string> getAvailableFlights()const;
    vector<string> getAvailableAirports()const;
    vector<string> getSupportedCountries()const;

    // method
    void printDetails();
};

#endif // AIRLINE_H






