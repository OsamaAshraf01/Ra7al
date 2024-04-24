#include"../include/Airline.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructors
Airline::Airline(){
    maxWeight = 0;
    name = "N/A";
}

Airline::Airline(const string &name, double maxWeight, const vector<string> &availableFlights,
                 const vector<string> &availableAirports, const vector<string> &supportedCountries) {
    this->name = name;
    this->maxWeight = maxWeight;
    this->availableAirports = availableAirports;
    this->availableFlights = availableFlights;
    this->supportedCountries = supportedCountries;
}


// setters
void Airline::setName(string &Name) {
    this->name = Name;
}

void Airline::setMaxWeight(double MaxWeight) {
    this->maxWeight = MaxWeight;
}

void Airline::setAvailableFlights(string &AvailableFlights) {
    this->availableFlights.push_back(AvailableFlights);
}

void Airline::setAvailableAirports(string &AvailableAirports) {
    this->availableAirports.push_back(AvailableAirports);
}

void Airline::setSupportedCountries(string &SupportedCountries) {
    this->supportedCountries.push_back(SupportedCountries);
}


//getters
string Airline::getName() const{
    return name;
}

double Airline::getMaxWeight() const {
    return maxWeight;
}

vector<string> Airline::getAvailableFlights()const {
    return availableFlights;
}

vector<string> Airline::getAvailableAirports()const {
    return availableAirports;
}

vector<string> Airline::getSupportedCountries()const {
    return supportedCountries;
}


//methods
void Airline::printDetails() {
    cout << "Name: " << name << "\n";
    cout << "Max Weight: " << maxWeight << "\n";
    cout << "Available Flights:\n";
}

