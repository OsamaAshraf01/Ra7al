#include"../include/Airline.h"
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

    // setters
    void setname(string Name)
    {
        this->Name = Name;
    }

    void setMaxweight(double Maxweight)
    {
        this->Maxweight = Maxweight;
    }

    void setavailableFlights(string availableFlights)
    {
        this->availableFlights.push_back(availableFlights);
    }

    void setavailableAirports(string availableAirports)
    {
        this->availableAirports.push_back(availableAirports);
    }

    void setsupportedCountries(string supportedCountries)
    {
        this->supportedCountries.push_back(supportedCountries);
    }


    //getters
    string getName()
    {
        return Name;
    }

    double getMaxweight()
    {
        return Maxweight;
    }

    vector<string> getavailableFlights()
    {
        return availableFlights;
    }

    vector<string> getavailableAirports()
    {
        return availableAirports;
    }

    vector<string> getsupportedCountries()
    {
        return supportedCountries;
    }


    //methods
    void printDetails() {
        cout << "Name: " << Name << "\n";
        cout << "Maxweight: " << Maxweight << "\n";
        cout << "Available Flights:\n";

    }
};







