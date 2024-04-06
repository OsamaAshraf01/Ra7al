#include "../include/Transportation.h"

// destructor
Transportation::~Transportation()
{
    cout << "Transportation Object Destroyed!!!" << endl;
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

string Transportation::getType() const
{
    return type;
}

Location Transportation::getOrigin() const
{
    return origin;
}

Location Transportation::getDestination() const
{
    return destination;
}

Time Transportation::getDepartureTime() const
{
    return departureTime;
}

Time Transportation::getArrivalTime() const
{
    return arrivalTime;
}

double Transportation::getPrice() const
{
    return price;
}

int Transportation::getPassengers() const
{
    return passengers;
}

// Setters

bool Transportation::setType(string t)
{
    if (t.empty())
    {
        cout << "Type cannot be empty" << endl;
        return false;
    }
    type = t;
    return true;
}

bool Transportation::setOrigin(Location o)
{
    origin = o;
    return true;
}

bool Transportation::setDestination(Location d)
{
    destination = d;
    return true;
}

bool Transportation::setDepartureTime(Time dt)
{
    departureTime = dt;
    return true;
}

bool Transportation::setArrivalTime(Time at)
{
    arrivalTime = at;
    return true;
}

bool Transportation::setPrice(double p)
{
    if (p < 0)
    {
        cout << "Price cannot be negative" << endl;
        return false;
    }
    price = p;
    return true;
}

bool Transportation::setPassengers(int p)
{
    if (p < 0)
    {
        cout << "Passengers cannot be negative" << endl;
        return false;
    }
    passengers = p;
    return true;
}

void Transportation::cancelBooking()
{
    // We use destructor on the object
    delete this;
}