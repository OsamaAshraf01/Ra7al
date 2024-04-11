#include"../include/Airline.h"
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

    // setters
    void setname(string Name)
    {
        this->Name = Name;
    }

    void setMaxweight(double Maxweight)
    {
        this->Maxweight = Maxweight;
    }

    void setavailableFlights(string availableFlights)
    {
        this->availableFlights.push_back(availableFlights);
    }

    void setavailableAirports(string availableAirports)
    {
        this->availableAirports.push_back(availableAirports);
    }

    void setsupportedCountries(string supportedCountries)
    {
        this->supportedCountries.push_back(supportedCountries);
    }


    //getters
    string getName()
    {
        return Name;
    }

    double getMaxweight()
    {
        return Maxweight;
    }

    vector<string> getavailableFlights()
    {
        return availableFlights;
    }

    vector<string> getavailableAirports()
    {
        return availableAirports;
    }

    vector<string> getsupportedCountries()
    {
        return supportedCountries;
    }


    //methods
    void printDetails() {
        cout << "Name: " << Name << "\n";
        cout << "Maxweight: " << Maxweight << "\n";
        cout << "Available Flights:\n";

    }
};




#include"../include/Hotel.h"
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
    void setName(string name)
     { this->name = name; }

    void setLocation(string location) 
     { this->location = location; }

    void setType(string type) 
     { this->type = type; }

    void setDescription(string description) 
     { this->description = description; }

    void setAmenities(vector<string> amenities) 
     { this->amenities = amenities; }

    void setPricing(double pricing) 
     { this->pricing = pricing; }


    // Getters
    string getName() 
     { return name; }

    string getLocation() 
     { return location; }

    string getType() 
     { return type; }

    string getDescription() 
     { return description; }

    vector<string> getAmenities() 
     { return amenities; }

    double getPricing() 
     { return pricing; }


    // Methods
    void showDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Location: " << location << "\n";
        cout << "Type: " << type << "\n";
        cout << "Description: " << description << "\n";
        cout << "Amenities:\n";

    }

    void showPricing()
    {
        cout << "Pricing: " << pricing << "\n";
    }

    void showAmenities()
    {
        cout << "Amenities: " <<"amenities "<<"\n";

    }

    void addAmenity(string amenity)
    {
        amenities.push_back(amenity);
    }
};














