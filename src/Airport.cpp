//
// Created by OSAMA ASHRAF on 4/15/2024.
//

#include "../include/Airport.h"



//setters
void Airport::setName(string name)
{
    this->name = name;
}

void Airport::setCode(string Code)
{
    this->code = Code;
}

void Airport::setCountry(Country _country)
{
    this->country = _country;
}

void Airport::setLoc(Location loc)
{
    this->Loc = loc;
}

void Airport::setAirlines(vector<Airline> Airlines)
{
    this->airlines = Airlines;
}

void Airport::setFlights(vector <Flight> Flights)
{
    this->flights = Flights;
}


//Airport::getters
string Airport::Airport::getName()
{
    return name;
}

string Airport::Airport::getCode()
{
    return code;
}

Country Airport::getCountry()
{
    return country;
}

Location Airport::getLoc()
{
    return Loc;
}

vector <Airline> Airport::getAirlines()
{
    return airlines;
}

vector <Flight> Airport::getFlights()
{
    return flights;
}

//methods 
vector<Flight> Airport::getFlightsTo(const string& flightCode){}

vector<Airline> Airport::getFlightsByAirline(const string& airlineName){}

vector<string> Airport::getSupportedAirlines(){}

double Airport::distanceTo(const Airport& other){}
