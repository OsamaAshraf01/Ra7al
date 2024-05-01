// Created By Ahmed Hamdy Kotp

#ifndef DESTINATION_H
#define DESTINATION_H
#include "../headers/Activity.h"
#include "../headers/Airline.h"
#include "../headers/Hotel.h"
#include "../headers/Country.h"
#include "../headers/DataFrame/CSVManager.h"
#include <vector>
#include <string>
using namespace std;

class Destination : public Country {
private:
	vector<Activity> activities;
	vector<Hotel> hotels;
	vector<Airline> airlines;
	string description;
	string countryName;
	Activity myActivities;
public:
	CSVManager x;
	Destination();
	Destination(string& desc, string& country);

	// Getters
	vector<Activity> getActivities() const;
	vector<Hotel> getHotels() const;
	vector <Airline> getAirlines() const;
	string getDescription() const;
	string getCountryName() const;

	// Setters
	void setActivities(const vector<Activity>& activities);
	void setHotels(const vector<Hotel>& hotels);
	void setAirlines(const vector<Airline>& airlines);
	void setDescription(const string& description);
	void setCountryName(const string& countryName);
	//Methods
    void showDestination() const;
	void addActivity(const Activity& activity);
};

#endif
