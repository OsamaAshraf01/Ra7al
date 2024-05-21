//Created by Ahmed Hamdy Kotp

#include "../headers/Destination.h"

// Constructors
Destination::Destination() {}

Destination::Destination(string& desc, string& country) : description(desc), countryName(country) {}

// Getters
vector<Activity> Destination::getActivities() const {
    return activities;
}

vector<Hotel> Destination::getHotels() const {
    return hotels;
}

vector <Airline> Destination::getAirlines() const {
    return airlines;
}

string Destination::getDescription() const {
    return description;
}

string Destination::getCountryName() const {
    return countryName;
}

// Setters
void Destination::setActivities(const vector<Activity>& activities) {
    this->activities = activities;
}

void Destination::setHotels(const vector<Hotel>& hotels) {
    this->hotels = hotels;
}

void Destination::setAirlines(const vector<Airline>& airlines) {
    this->airlines = airlines;
}


void Destination::setDescription(const string& description) {
    this->description = description;
}

void Destination::setCountryName(const string& countryName) {
    this->countryName = countryName;
}

void Destination::showDestination() const {
    cout << "Country: " << countryName << endl;
    cout << "Description: " << description << endl;

    // Display activities
    cout << "Activities: " << endl;
    for (const auto& activity : activities) {
        cout << "Activity Name: " << activity.getName() << endl;
        cout << "Activity Description: " << activity.getDescription() << endl;
        cout << "Activity Price: " << activity.getPrice() << endl;
    }

    cout << "Hotels: " << endl;
    for (const auto& hotel : hotels) {
        cout << "Hotel Name: " << hotel.getName() << endl;
        cout << "Hotel Location: " << hotel.getLocation() << endl;
        cout << "Hotel Type: " << hotel.getType() << endl;
        cout << "Hotel Description: " << hotel.getDescription() << endl;
        cout << "Hotel Pricing: " << hotel.getPricing() << endl;

        cout << "Hotel Amenities: " << endl;
        for (const auto& amenity : hotel.getAmenities()) {
            cout << "- " << amenity << endl;
        }
    }

    // Display airlines
    cout << "Activities: " << endl;
    for (const auto& activity : activities) {
        cout << "Activity Name: " << activity.getName() << endl;
        cout << "Activity Description: " << activity.getDescription() << endl;
        cout << "Activity Price: " << activity.getPrice() << endl;
    }

}


void Destination::addActivity(const Activity& activity) {
    activities.push_back(activity);
}
