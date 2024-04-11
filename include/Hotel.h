#ifndef HOTEL_H
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

#endif