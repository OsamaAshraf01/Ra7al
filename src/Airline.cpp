#include"../include/Airline.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// setters
void Airline::setName(string & Name) {
    this->name = Name;
}

void Airline::setMaxWeight(double MaxWeight) {
    this->maxWeight = MaxWeight;
}

void Airline::setAvailableFlights(string & AvailableFlights) {
    this->availableFlights.push_back(AvailableFlights);
}

void Airline::setAvailableAirports(string & AvailableAirports) {
    this->availableAirports.push_back(AvailableAirports);
}

void Airline::setSupportedCountries(string & SupportedCountries) {
    this->supportedCountries.push_back(SupportedCountries);
}


//getters
string Airline::getName() {
    return name;
}

double Airline::getMaxWeight() const {
    return maxWeight;
}

vector<string> Airline::getAvailableFlights() {
    return availableFlights;
}

vector<string> Airline::getAvailableAirports() {
    return availableAirports;
}

vector<string> Airline::getSupportedCountries() {
    return supportedCountries;
}


//methods
void Airline::printDetails() {
    cout << "Name: " << name << "\n";
    cout << "Max Weight: " << maxWeight << "\n";
    cout << "Available Flights:\n";
}
