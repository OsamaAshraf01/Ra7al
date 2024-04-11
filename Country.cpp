#include "../include/Country.h"
#include "Country.h"
#include <sstream>
Country::Country()
{
}

Country::Country(string &name, string &capital, long &popu)
{
    this->name = name;
    this->capital = capital;
    this->population = popu ;
}

string Country::showDetails(){
    stringstream ss; 
    ss << "------- Country Details -------" << endl;
    ss << "Name:    " << name << endl;
    ss << "Capital: " << capital << endl;
    ss << "Population: " << population << endl; 
    ss << "-------------------------------" << endl;
    return ss.str(); 
}
