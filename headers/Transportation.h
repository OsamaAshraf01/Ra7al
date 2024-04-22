#ifndef RA7AL_TRANSPORTATION_H
#define RA7AL_TRANSPORTATION_H
#include <iostream>
#include "Location.h"
#include "Time.h"
#include "Duration.h"
using namespace std;

class Transportation
{
private:
    string type;
    Location origin;
    Location destination;
    Time departureTime;
    Time arrivalTime;
    double price;
    int passengers;

public:
    // Constructors
    Transportation();
    Transportation(string type, Location origin, Location destination, Time departureTime, Time arrivalTime, double price, int passengers);

    // Getters
    string getType() const;
    Location getOrigin() const;
    Location getDestination() const;
    Time getDepartureTime() const;
    Time getArrivalTime() const;
    double getPrice() const;
    int getPassengers() const;

    // Setters
    bool setType(string t);
    bool setOrigin(Location o);
    bool setDestination(Location d);
    bool setDepartureTime(Time dt);
    bool setArrivalTime(Time at);
    bool setPrice(double p);
    bool setPassengers(int p);

    void cancelBooking();
    Duration duration();
    void showDetails();

    ~Transportation();
};

#endif