//created by Ahmed Hamdy Kotp

#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
#include <string>

using namespace std;

class Country {
private :
    string name ;
    string capital ;
    long population ;
    // Location location ;
    // Currency currency ;
    // Location location;
public:
//constructors
    Country();
    Country(string &name , string&capital ,long &popu);


    //methods
    string showDetails();
};

#endif
