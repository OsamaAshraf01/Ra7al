#include "Flight.h"

Flight::Flight()
{
    origin = Airport();
    destination = Airport();
    departure = Date();
    arrival = Date();
    airline = Airline();
    price = 0.0;
    flightNumber = 0;
    duration = Duration();
}

Flight::Flight(Airport origin, Airport destination, Date departure, Date arrival, Airline airline, double price, int flightNumber, Duration duration)
{
    this->origin = origin;
    this->destination = destination;
    this->departure = departure;
    this->arrival = arrival;
    this->airline = airline;
    this->price = price;
    this->flightNumber = flightNumber;
    this->duration = duration;
}

void Flight::showDetails()
{
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Departure: " << departure.toString() << endl;
    cout << "Arrival: " << arrival.toString() << endl;
    cout << "Airline: " << airline.getName() << endl;
    cout << "Price: " << price << endl;
}

double Flight::getPrice()
{
    return price;
}