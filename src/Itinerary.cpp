#include "../headers/Itinerary.h"
#include <iostream>

using namespace std;

Itinerary::Itinerary()
{
    popularity = 0;
}

Itinerary::Itinerary(Date startDate, Date endDate, vector<Hotel> hotels, vector<Flight> flights, vector<Transportation> transportations, vector<Destination> destinations, vector<Activity> activities, int popularity)
{
    this->startDate = startDate;
    this->endDate = endDate;
    this->hotels = hotels;
    this->flights = flights;
    this->transportations = transportations;
    this->destinations = destinations;
    this->activities = activities;
    this->popularity = popularity;
}

void Itinerary::show()
{
    cout << "Itinerary" << endl;
    cout << "Popularity: " << popularity << endl;

    cout << "Hotels: " << endl;
    for (int i = 0; i < hotels.size(); i++)
    {
        hotels[i].showDetails();
    }

    cout << "Flights: " << endl;
    for (int i = 0; i < flights.size(); i++)
    {
        flights[i].showDetails();
    }

    cout << "Transportations: " << endl;
    for (int i = 0; i < transportations.size(); i++)
    {
        transportations[i].showDetails();
    }

    cout << "Destinations: " << endl;
    for (int i = 0; i < destinations.size(); i++)
    {
        destinations[i].showDestination();
    }

    cout << "Activities: " << endl;
    for (int i = 0; i < activities.size(); i++)
    {
        activities[i].showDetails();
    }

    cout << "Start Date: ";
    startDate.toString();
    cout << "End Date: ";
    endDate.toString();
}

double Itinerary::getTotalCost()
{
    double totalCost = 0;

    for (int i = 0; i < hotels.size(); i++)
    {
        totalCost += hotels[i].getPricing();
    }

    for (int i = 0; i < flights.size(); i++)
    {
        totalCost += flights[i].getPrice();
    }

    for (int i = 0; i < transportations.size(); i++)
    {
        totalCost += transportations[i].getPrice();
    }

    for (int i = 0; i < activities.size(); i++)
    {
        totalCost += activities[i].getPrice();
    }

    return totalCost;
}