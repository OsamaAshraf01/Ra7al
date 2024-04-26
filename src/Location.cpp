//
// Created by OSAMA ASHRAF on 4/5/2024.
//

#include "../headers/Location.h"
#include <sstream>
#include <cmath>
using namespace std;

// Constructors
Location::Location(double longitude, double latitude) : longitude(longitude), latitude(latitude) {}
Location::Location() : Location(0, 0) {}

// Getters
double Location::getLongitude() const { return this->longitude; }
double Location::getLatitude() const { return this->latitude; }

// Setters
bool Location::setLatitude(double value)
{
    if (value <= 90 && value >= -90)
    {
        this->latitude = value;
        return true;
    }
    return false;
}
bool Location::setLongitude(double value)
{
    if (value <= 180 && value >= -180)
    {
        this->longitude = value;
        return true;
    }
    return false;
}

// Methods
string Location::toString() const
{
    ostringstream oss;
    oss << '(' << this->longitude << ", " << this->latitude << ')';

    return oss.str();
}

double Location::distanceTo(Location &other) const
{
    double dx = (this->longitude - other.longitude) * (this->longitude - other.longitude);
    double dy = (this->latitude - other.latitude) * (this->latitude - other.latitude);

    return sqrt(dx + dy);
}