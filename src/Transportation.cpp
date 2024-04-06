#include "../include/Transportation.h"

// Destructor

Transportation::~Transportation()
{
    cout << "Transportation" << type << " deleted" << endl;
}

// Constructors

Transportation::Transportation()
{
    type = "";
    origin = Location();
    destination = Location();
    departureTime = Time();
    arrivalTime = Time();
    price = 0;
    passengers = 0;
}

Transportation::Transportation(string type, Location origin, Location destination, Time departureTime, Time arrivalTime, double price, int passengers)
{
    this->type = type;
    this->origin = origin;
    this->destination = destination;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->price = price;
    this->passengers = passengers;
}

// Getters

string Transportation::getType() const { return type; }

Location Transportation::getOrigin() const { return origin; }

Location Transportation::getDestination() const { return destination; }

Time Transportation::getDepartureTime() const { return departureTime; }

Time Transportation::getArrivalTime() const { return arrivalTime; }

double Transportation::getPrice() const { return price; }

int Transportation::getPassengers() const { return passengers; }

// Setters

bool Transportation::setType(string t)
{
    if (t.empty())
    {
        return false;
    }
    type = t;
    return true;
}

bool Transportation::setOrigin(Location o)
{
    if (o.getLongitude() == destination.getLongitude() && o.getLatitude() == destination.getLatitude())
    {
        return false;
    }
    origin = o;
    return true;
}

bool Transportation::setDestination(Location d)
{
    if (d.getLongitude() == origin.getLongitude() && d.getLatitude() == origin.getLatitude())
    {
        return false;
    }
    destination = d;
    return true;
}

bool Transportation::setDepartureTime(Time dt)
{
    if (dt.getHours() > 24 || dt.getHours() < 0 || dt.getMinutes() > 60 || dt.getMinutes() < 0 || dt.getSeconds() > 60 || dt.getSeconds() < 0)
    {
        return false;
    }
    departureTime = dt;
    return true;
}

bool Transportation::setArrivalTime(Time at)
{
    if (at.getHours() > 24 || at.getHours() < 0 || at.getMinutes() > 60 || at.getMinutes() < 0 || at.getSeconds() > 60 || at.getSeconds() < 0)
    {
        return false;
    }
    arrivalTime = at;
    return true;
}

bool Transportation::setPrice(double p)
{
    if (p < 0)
    {
        return false;
    }
    price = p;
    return true;
}

bool Transportation::setPassengers(int p)
{
    if (p < 0)
    {
        return false;
    }
    passengers = p;
    return true;
}

void Transportation::cancelBooking()
{
    delete this;
}