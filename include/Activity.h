#ifndef RA7AL_ACTIVITY_H
#define RA7AL_ACTIVITY_H
#include <iostream>
#include <vector>
#include <string>
#include "Location.h"
#include "Time.h"
#include "Date.h"
using namespace std;

class Activity
{
private:
    string name;
    string description;
    vector<Location> locations;
    double price;
    Date startDate;
    Date endDate;

public:
    Activity();
    Activity(string name, string description, vector<Location> locations, double price, Date startDate, Date endDate);

    string getName() const;
    string getDescription() const;
    vector<Location> getLocations() const;
    double getPrice() const;
    Date getStartDate() const;
    Date getEndDate() const;

    bool setName(string n);
    bool setDescription(string d);
    bool setLocations(vector<Location> l);
    bool setPrice(double p);
    bool setStartDate(Date sd);
    bool setEndDate(Date ed);

    // Duration getDuration();
    bool isAvailableAt(Location l);
    void show();

    ~Activity();
};

#endif