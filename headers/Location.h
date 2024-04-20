//
// Created by OSAMA ASHRAF on 4/5/2024.
//
/* ---Validation---
    Location l;   double lat, lon;
    do{
        cout<<"Enter Latitude: ";
        cin>>lat;
    } while(!l.setLatitude(lat) && (cout << "Invalid Value! "));
    do{
        cout<<"Enter Longitude: ";
        cin>>lon;
    } while(!l.setLongitude(lon) && (cout << "Invalid Value! "));

    cout<<l.toString();
*/


#ifndef RA7AL_LOCATION_H
#define RA7AL_LOCATION_H
#include <iostream>

class Location {
private:
    double longitude, latitude;
public:
    // Constructors
    Location();
    Location(double longitude, double latitude);


    // Getters
    double getLongitude() const;
    double getLatitude() const;


    // Setters
    bool setLongitude(double value);
    bool setLatitude(double value);


    // Methods
    std::string toString() const;
    double distanceTo(Location& other) const;
};


#endif //RA7AL_LOCATION_H
