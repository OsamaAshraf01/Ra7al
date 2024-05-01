//
// Created by OSAMA ASHRAF on 4/15/2024.
//

#ifndef RA7AL_AIRPORT_H
#define RA7AL_AIRPORT_H
#include <iostream>
#include <string>
#include <vector>
#include "Country.h"
#include "Airline.h"
#include "Flight.h"
#include "Location.h"

using namespace std;

class Airport
{
private:
    string name;
    string code;
    Country country;
    Location Loc;
    vector <Airline> airlines;
    // vector <Flight> flights;

public:

    //setters
    void setName(string name);

    void setCode(string Code);

    void setCountry(Country _country);

    void setLoc(Location loc);

    void setAirlines(vector<Airline> Airlines);

    // void setFlights(vector <Flight> Flights);


    //getters
    string getName();

    string getCode();

    Country getCountry();

    Location getLoc();

    vector <Airline> getAirlines();

    // vector <Flight> getFlights();

    //methods 
    // vector<Flight> getFlightsTo(const string& flightCode);

    vector<Airline> getFlightsByAirline(const string& airlineName);

    vector<string> getSupportedAirlines();

    double distanceTo(const Airport& other);

};


#endif //RA7AL_AIRPORT_H
