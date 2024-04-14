#include "Flight.h"

Flight::Flight()
{
    // origin = Airport();
    // destination = Airport();
    departure = Date();
    arrival = Date();
    airline = Airline();
    price = 0.0;
    flightNumber = 0;
    // duration = Duration();
}

Flight::Flight(Date departure, Date arrival, Airline airline, double price, int flightNumber)
{
    // this->origin = Airport();
    // this->destination = Airport();
    this->departure = Date();
    this->arrival = Date();
    this->airline = Airline();
    this->price = price;
    this->flightNumber = flightNumber;
    // this->duration = Duration();
}

void Flight::showDetails()
{
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Departure: " << departure.toString() << endl;
    cout << "Arrival: " << arrival.toString() << endl;
    cout << "Airline: " << airline.getName() << endl;
    cout << "Price: " << price << endl;
}