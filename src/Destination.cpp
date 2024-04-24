//created by ahmed hamdy kotp


#include "../header/Destination.h"
#include "../header/CSVManager.h" 

Destination::Destination() : description(""), countryName("") {
}

Destination::Destination(string& desc, string& country)
{
    this->description = desc;
    this->countryName = country;
}





vector<Activity> Destination::getActivities(const string& countryname) const {
    CSVManager csv("activities.csv");
    auto data = csv.read();
    vector<Activity> activities;

    for (const auto& row : data) {
        if (row[0] == countryname) {
            for (int i = 1; i < row.size(); ++i) {
                activities.push_back(Activity(row[i])); // TODO
            break;
        }
    }

    return activities;
}

vector<Airline> Destination::getHotels(const string& countryname) const {
    CSVManager csv("hotels.csv");
    auto data = csv.read();
    vector<Hotel> hotels;

    for (const auto& row : data) {
        if (row[0] == countryname) {
            for (int i = 1; i < row.size(); ++i) {
                hotels.push_back(Hotel(row[i])); // TODO
            }
            break;
        }
    }

    return hotels;
}

string Destination::getDescription(const string& countryname) const {
    return (this->countryName == countryname) ? this->description : "";
}

void Destination::showDestination(const string& countryname) const {
    if (this->countryName == countryname) {
        cout << "Description: " << this->description << endl;
        cout << "Country: " << this->countryName << endl;
        vector<Activity> activities = getActivities(countryname);
        cout << "Activities:" << endl;
        for (const auto& activity : activities) {
            activity.showAll(); // TODO
        }
        vector<Hotel> hotels = getHotels(countryname);
        cout << "Hotels:" << endl;
        for (const auto& hotel : hotels) {
            hotel.showAll(); // TODO
        }
        vector<Airline> airlines = getAirline(countryname);
        cout << "Airlines:" << endl;
        for (const auto& airline : airlines) {
            airline.showAll(); // TODO
        }
    }
    else {
        cout << "No details available for " << countryname << endl;
    }
}
