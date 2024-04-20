#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <iostream>
#include "../include/Airline.h"
#include "../include/Date.h"
//#include "Duration.h" // Not implemented yet
//#include "Airport.h"
using namespace std;

class Flight
{
private:
//    Airport origin; // Not implemented yet
//    Airport destination;
    Date departure;
    Date arrival;
    Airline airline;
    double price;
    int flightNumber;
//    Duration duration;

public:
    Flight();

    Flight(Date departure, Date arrival, Airline airline, double price, int flightNumber);

    void showDetails();
};

#endif
