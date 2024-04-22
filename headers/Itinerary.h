#ifndef RA7AL_ITINERARY_H
#define RA7AL_ITINERARY_H

#include <vector>
#include "Hotel.h"
#include "Flight.h"
#include "Transportation.h"
#include "Destination.h"
#include "Activity.h"
#include "Date.h"

class Itinerary
{
private:
    int popularity;
    vector<Hotel> hotels;
    vector<Flight> flights;
    vector<Transportation> transportations;
    vector<Destination> destinations;
    vector<Activity> activities;
    Date startDate;
    Date endDate;

public:
    Itinerary();
    Itinerary(Date startDate, Date endDate, vector<Hotel> hotels, vector<Flight> flights, vector<Transportation> transportations, vector<Destination> destinations, vector<Activity> activities);
    void show();
    double getTotalCost();
};

#endif