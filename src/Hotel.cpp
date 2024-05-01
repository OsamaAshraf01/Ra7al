#include"headers/Hotel.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

// Setters
void Hotel::setName(string& Name) {
    this->name = Name;
}

void Hotel::setLocation(string& Location) {
    this->location = Location;
}

void Hotel::setType(string& Type) {
    this->type = Type;
}

void Hotel::setDescription(string& Description) {
    this->description = Description;
}

void Hotel::setAmenities(vector<string>& Amenities) {
    this->amenities = Amenities;
}

void Hotel::setPricing(double Pricing) {
    this->pricing = Pricing;
}


// Getters
string Hotel::getName() const{
    return name;
}

string Hotel::getLocation() const{
    return location;
}

string Hotel::getType() const{
    return type;
}

string Hotel::getDescription() const{
    return description;
}

vector<string> Hotel::getAmenities() const{
    return amenities;
}

double Hotel::getPricing() const {
    return pricing;
}


// Methods
void Hotel::showDetails() const{
    cout << "Name: " << name << "\n";
    cout << "Location: " << location << "\n";
    cout << "Type: " << type << "\n";
    cout << "Description: " << description << "\n";
    cout << "Amenities:\n";
    for (auto& amenity: amenities) {
        cout << amenity << " ,";
    }

}

void Hotel::showPricing() const {
    cout << "Pricing: " << pricing << "\n";
}

void Hotel::showAmenities() const{
    cout << "Amenities: " << "\n";
    for (auto& amenity: amenities) {
        cout << amenity << " ,";
    }

}

void Hotel::addAmenity(string& amenity) {
    amenities.push_back(amenity);
}

