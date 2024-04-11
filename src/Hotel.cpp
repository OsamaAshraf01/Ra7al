#include"../include/Hotel.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

// Setters
void Hotel::setName(string name) {
    this->name = name;
}

void Hotel::setLocation(string location) {
    this->location = location;
}

void Hotel::setType(string type) {
    this->type = type;
}

void Hotel::setDescription(string description) {
    this->description = description;
}

void Hotel::setAmenities(vector<string> amenities) {
    this->amenities = amenities;
}

void Hotel::setPricing(double pricing) {
    this->pricing = pricing;
}


// Getters
string Hotel::getName() {
    return name;
}

string Hotel::getLocation() {
    return location;
}

string Hotel::getType() {
    return type;
}

string Hotel::getDescription() {
    return description;
}

vector<string> Hotel::getAmenities() {
    return amenities;
}

double Hotel::getPricing() {
    return pricing;
}


// Methods
void Hotel::showDetails() {
    cout << "Name: " << name << "\n";
    cout << "Location: " << location << "\n";
    cout << "Type: " << type << "\n";
    cout << "Description: " << description << "\n";
    cout << "Amenities:\n";
    for (string amenity: amenities) {
        cout << amenity << " ,";
    }

}

void Hotel::showPricing() {
    cout << "Pricing: " << pricing << "\n";
}

void Hotel::showAmenities() {
    cout << "Amenities: " << "\n";
    for (string amenity: amenities) {
        cout << amenity << " ,";
    }

}

void Hotel::addAmenity(string amenity) {
    amenities.push_back(amenity);
}

