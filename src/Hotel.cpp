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
    {
        this->name = name;
    }

    void setLocation(string location)
    {
        this->location = location;
    }

    void setType(string type)
    {
        this->type = type;
    }

    void setDescription(string description)
    {
        this->description = description;
    }

    void setAmenities(vector<string> amenities)
    {
        this->amenities = amenities;
    }

    void setPricing(double pricing)
    {
        this->pricing = pricing;
    }


    // Getters
    string getName()
    {
        return name;
    }

    string getLocation()
    {
        return location;
    }

    string getType()
    {
        return type;
    }

    string getDescription()
    {
        return description;
    }

    vector<string> getAmenities()
    {
        return amenities;
    }

    double getPricing()
    {
        return pricing;
    }


    // Methods
    void showDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Location: " << location << "\n";
        cout << "Type: " << type << "\n";
        cout << "Description: " << description << "\n";
        cout << "Amenities:\n";
        for (string amenity : amenities) {
            cout << amenity << " ,";
        }

    }

    void showPricing()
    {
        cout << "Pricing: " << pricing << "\n";
    }

    void showAmenities()
    {
        cout << "Amenities: " << "\n";
        for (string amenity : amenities) {
            cout << amenity << " ,";
        }

    }

    void addAmenity(string amenity)
    {
        amenities.push_back(amenity);
    }
};