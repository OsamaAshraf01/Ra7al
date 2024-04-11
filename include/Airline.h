#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Airline {
private:
    string Name;
    double Maxweight;
    vector<string> availableFlights;
    vector<string> availableAirports;
    vector<string> supportedCountries;

public:
    // Constructor
    Airline();

    // setters
    void setname(string Name);
    void setMaxweight(double Maxweight);
    void setavailableFlights(string availableFlights);
    void setavailableAirports(string availableAirports);
    void setsupportedCountries(string supportedCountries);

    // getters
    string getName();
    double getMaxweight();
    vector<string> getavailableFlights();
    vector<string> getavailableAirports();
    vector<string> getsupportedCountries();

    // method
    void printDetails();
};

#endif // AIRLINE_H






