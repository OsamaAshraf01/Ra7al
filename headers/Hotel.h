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
    void setName(string& name);
    void setLocation(string& location);
    void setType(string& type);
    void setDescription(string& description);
    void setAmenities(vector<string>& amenities);
    void setPricing(double pricing);

    // Getters
    string getName()const;
    string getLocation()const;
    string getType()const;
    string getDescription()const;
    vector<string> getAmenities()const;
    double getPricing() const;

    // Methods
    void showDetails()const;
    void showPricing() const;
    void showAmenities()const;
    void addAmenity(string& amenity);
};

#endif
