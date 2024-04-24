// Created By Ahmed Hamdy Kotp

#ifndef DESTINATION_H
#define DESTINATION_H
#include "Activity.h"
#include "Airline.h"
#include "Hotel.h"
#include "Country.h"
#include "CSVManager.h"
#include <vector>
#include <string>
using namespace std;

class Destination : Country {
private :
	vector<Activity>activities;
	vector<Hotel>hotels;
	vector<Airline> airlines;
	string description;
	string countryName;
	Activity myActivities;
public:
	Destination();
	Destination(string&desc,string&country);
	
	vector<Activity> getActivities(string& countryname)const;
	vector<Hotel> getHotels(string & countryname)const;
	vector <Airline> getAirline(const string& countryname) const;
	string getdescription(string& countryname );

	void showDestination(string& countryname);
};


#endif
