/*#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Airline {
private:
    string Name;
    double Maxweight;
    vector<string> availableFlights;
    vector<string> availableAirports;
    vector<string> supportedCountries;

public:
    // Constructor
    Airline();

    // setters
    void setname(string Name);
    void setMaxweight(double Maxweight);
    void setavailableFlights(string availableFlights);
    void setavailableAirports(string availableAirports);
    void setsupportedCountries(string supportedCountries);

    // getters
    string getName();
    double getMaxweight();
    vector<string> getavailableFlights();
    vector<string> getavailableAirports();
    vector<string> getsupportedCountries();

    // method
    void printDetails();
};

#endif // AIRLINE_H*/




/*#ifndef HOTEL_H
#define HOTEL_H

#include <iostream> 
#include <string>
#include <vector>

using namespace std;

class Hotel {

private:
    string name;
    string location;
    string type;
    string description;
    vector<string> amenities;
    double pricing;

public:

    // Setters
    void setName(string name);
    void setLocation(string location);
    void setType(string type);
    void setDescription(string description);
    void setAmenities(vector<string> amenities);
    void setPricing(double pricing);

    // Getters
    string getName();
    string getLocation();
    string getType();
    string getDescription();
    vector<string> getAmenities();
    double getPricing();

    // Methods
    void showDetails();
    void showPricing();
    void showAmenities();
    void addAmenity(string amenity);
};

#endif*/

