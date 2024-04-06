#include "../include/Activity.h"

// constructors
Activity::Activity()
{
    name = "";
    description = "";
    locations = {};
    price = 0;
    startDate = Date();
    endDate = Date();
}

Activity::Activity(string name, string description, vector<Location> locations, double price, Date startDate, Date endDate)
{
    this->name = name;
    this->description = description;
    this->locations = locations;
    this->price = price;
    this->startDate = startDate;
    this->endDate = endDate;
}

// getters
string Activity::getName() const { return name; }

string Activity::getDescription() const { return description; }

vector<Location> Activity::getLocations() const { return locations; }

double Activity::getPrice() const { return price; }

Date Activity::getStartDate() const { return startDate; }

Date Activity::getEndDate() const { return endDate; }

// setters
bool Activity::setName(string n)
{
    if (n.empty())
    {
        return false;
    }
    name = n;
    return true;
}

bool Activity::setDescription(string d)
{
    if (d.empty())
    {
        return false;
    }
    description = d;
    return true;
}

bool Activity::setLocations(vector<Location> l)
{
    if (l.empty())
    {
        return false;
    }
    locations = l;
    return true;
}

bool Activity::setPrice(double p)
{
    if (p < 0)
    {
        return false;
    }
    price = p;
    return true;
}

bool Activity::setStartDate(Date sd)
{
    if (!sd.isValid())
    {
        return false;
    }
    startDate = sd;
    return true;
}

bool Activity::setEndDate(Date ed)
{
    if (!ed.isValid())
    {
        return false;
    }
    endDate = ed;
    return true;
}

bool Activity::isAvailableAt(Location l)
{
    for (Location location : locations)
    {
        if (location.distanceTo(l) == 0)
        {
            return true;
        }
    }
    return false;
}

// methods
void Activity::show()
{
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Locations: ";
    for (Location location : locations)
    {
        cout << location.toString() << ", ";
    }
    cout << endl;
    cout << "Price: " << price << endl;
    cout << "Start Date: " << startDate.toString() << endl;
    cout << "End Date: " << endDate.toString() << endl;
}

// destructor
Activity::~Activity()
{
    cout << "Activity " << name << " deleted" << endl;
}