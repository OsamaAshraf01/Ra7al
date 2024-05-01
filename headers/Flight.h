#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <iostream>
#include "../headers/Airline.h"
#include "../headers/Date.h"
#include "Duration.h"
#include "Airport.h"
using namespace std;

class Flight
{
private:
    // Airport origin;
    // Airport destination;
    Date departure;
    Date arrival;
    Airline airline;
    double price;
    int flightNumber;
    Duration duration;

public:
    Flight();

    Flight(/*Airport origin, Airport destination, */Date departure, Date arrival, Airline airline, double price, int flightNumber, Duration duration);

    void showDetails();
    double getPrice();
};

#endif
